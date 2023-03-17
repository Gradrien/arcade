##
## EPITECH PROJECT, 2023
## arcade
## File description:
## Makefile
##

CC	=	g++

SRC_CORE	=	src/core/ArgsHandler.cpp	\
				src/core/Menu.cpp	\
				src/core/Core.cpp

SRC_ERROR	=	src/error/Error.cpp

SRC_MAIN	=	src/Main.cpp

SRC_SFML	=	src/graphics/sfml/SFMLGraphic.cpp	\
				src/graphics/sfml/SFMLGraphicLib.cpp	\
				src/graphics/sfml/SFMLEvent.cpp	\

SRC_NCURSES	=	src/graphics/ncurses/NcursesGraphic.cpp	\
				src/graphics/ncurses/NcursesGraphicLib.cpp	\
				src/graphics/ncurses/NcursesEvent.cpp	\

SRC_GAMETEST	=	src/games/test_game/TestGame.cpp	\
					src/games/test_game/TestGameLib.cpp

SRC			=	$(SRC_CORE) $(SRC_ERROR)

TESTS_SRC	=	tests/tests_args.c

OBJ_CORE	=	$(SRC:.cpp=.o) $(SRC_MAIN:.cpp=.o)

CORE_NAME = arcade

GAME_NIBBLER = arcade_nibbler.so
GAME_SNAKE	 = arcade_snake.so
GAME_TEST	 = test_game.so

GRAPHIC_SFML = arcade_sfml.so
GRAPHIC_NCURSES = arcade_ncurses.so
GRAPHIC_SDL  = arcade_sdl2.so

TEST_NAME	=	unit_tests

CXXFLAGS	=	-std=c++20 -Wall -Wextra -Werror -fno-gnu-unique

CPPFLAGS	=	-I	./include/core	\
				-I ./include/graphics	\
				-I ./include/games	\
				-I ./include/graphics/sfml	\
				-I ./include/graphics/ncurses	\
				-I ./include/error	\
				-I ./include/games/test_game	\

SFMLFLAGS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
NCURSESFLAG = -lncurses

LDFLAGS	=	-ldl

DEBUGFLAG = -ggdb3

all:	core graphics games
.PHONY: all

core:	$(CORE_NAME)
.PHONY: core

$(CORE_NAME):	$(OBJ_CORE)
	$(CC) -o $(CORE_NAME) $(OBJ_CORE) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(SFMLFLAGS)

games:
	$(CC) $(CXXFLAGS) -fpic -shared -o $(GAME_TEST) $(SRC_GAMETEST) $(CPPFLAGS)
	mv $(GAME_TEST) ./lib/games/
#$(CC) -o $(GAME_NIBBLER) $(OBJ) $(CXXFLAGS) $(CPPFLAGS)
#$(CC) -o $(GAME_SNAKE) $(OBJ) $(CXXFLAGS) $(CPPFLAGS)
.PHONY: games

graphics:
	$(CC) $(CXXFLAGS) -fpic -shared -o $(GRAPHIC_SFML) $(SRC_SFML) $(CPPFLAGS) $(SFMLFLAGS)
	mv $(GRAPHIC_SFML) ./lib/graphics/
	$(CC) $(CXXFLAGS) -fpic -shared -o $(GRAPHIC_NCURSES) $(SRC_NCURSES) $(CPPFLAGS) $(NCURSESFLAG)
	mv $(GRAPHIC_NCURSES) ./lib/graphics/
#	$(CC) -o $(GRAPHIC_SFML) $(OBJ) $(CXXFLAGS) $(CPPFLAGS)
#	$(CC) -o $(GRAPHIC_NCUR) $(OBJ) $(CXXFLAGS) $(CPPFLAGS)
#	$(CC) -o $(GRAPHIC_SDL) $(OBJ) $(CXXFLAGS) $(CPPFLAGS)
.PHONY: graphics

tests_run:
	$(CC) -o $(TEST_NAME) $(SRC) $(TESTS_SRC) $(CPPFLAGS) $(LDFLAGS) \
	--coverage -lcriterion -lgcov
	./$(TEST_NAME)
.PHONY: tests_run

clean_tests:
	rm -f *.gc*
	rm -f $(TEST_NAME)
.PHONY: clean_tests

coverage:
	gcovr --exclude tests/ && gcovr --exclude tests/ -b
.PHONY: coverage

clean: clean_tests
	rm -f $(OBJ_CORE)
.PHONY: clean

fclean:	clean
	rm -f $(CORE_NAME)
	rm -f $(GAME_NIBBLER)
	rm -f $(GAME_SNAKE)
	rm -f ./lib/$(GRAPHIC_SFML)
	rm -f ./lib/$(GRAPHIC_NCURSES)
	rm -f ./lib/$(GRAPHIC_SDL)
.PHONY: fclean

re:	fclean all
.PHONY: re

debug:	fclean
	$(CC) -o $(CORE_NAME) $(SRC_CORE) $(SRC_ERROR) $(SRC_MAIN) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(SFMLFLAGS) $(DEBUGFLAG)

.PHONY: debug
