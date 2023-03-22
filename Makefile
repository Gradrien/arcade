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

SRC_SDL	=	src/graphics/sdl/SDLGraphic.cpp	\
				src/graphics/sdl/SDLGraphicLib.cpp	\
				src/graphics/sdl/SDLEvent.cpp	\

SRC_GAMETEST	=	src/games/test_game/TestGame.cpp	\
					src/games/test_game/TestGameLib.cpp

SRC_NIBBLER	=	src/games/nibbler/Nibbler.cpp	\
				src/games/nibbler/NibblerLib.cpp

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
				-I ./include/graphics/sdl	\
				-I ./include/error	\
				-I ./include/games/test_game	\
				-I ./include/games/nibbler	\

SFMLFLAGS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
NCURSESFLAG = -lncurses
SDLFLAG = -lSDL2 -lSDL2_ttf

LDFLAGS	=	-ldl

DEBUGFLAG = -ggdb3

all:	core graphicals games
.PHONY: all

core:	$(CORE_NAME)
.PHONY: core

$(CORE_NAME):	$(OBJ_CORE)
	$(CC) -o $(CORE_NAME) $(OBJ_CORE) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS)

games:
	$(CC) $(CXXFLAGS) -fpic -shared -o $(GAME_TEST) $(SRC_GAMETEST) $(CPPFLAGS)
	mv $(GAME_TEST) ./lib/
	$(CC) $(CXXFLAGS) -fpic -shared -o $(GAME_NIBBLER) $(SRC_NIBBLER) $(CPPFLAGS)
	mv $(GAME_NIBBLER) ./lib/
#$(CC) -o $(GAME_SNAKE) $(OBJ) $(CXXFLAGS) $(CPPFLAGS)
.PHONY: games

graphicals:
	$(CC) $(CXXFLAGS) -fpic -shared -o $(GRAPHIC_SFML) $(SRC_SFML) $(CPPFLAGS) $(SFMLFLAGS)
	mv $(GRAPHIC_SFML) ./lib/
	$(CC) $(CXXFLAGS) -fpic -shared -o $(GRAPHIC_NCURSES) $(SRC_NCURSES) $(CPPFLAGS) $(NCURSESFLAG)
	mv $(GRAPHIC_NCURSES) ./lib/
	$(CC) $(CXXFLAGS) -fpic -shared -o $(GRAPHIC_SDL) $(SRC_SDL) $(CPPFLAGS) $(SDLFLAG)
	mv $(GRAPHIC_SDL) ./lib/

.PHONY: graphicals

tests_run: graphicals games
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
	rm -f ./lib/$(CORE_NAME)
	rm -f ./lib/$(GAME_NIBBLER)
	rm -f ./lib/$(GAME_SNAKE)
	rm -f ./lib/$(GRAPHIC_SFML)
	rm -f ./lib/$(GRAPHIC_NCURSES)
	rm -f ./lib/$(GRAPHIC_SDL)
.PHONY: fclean

re:	fclean all
.PHONY: re

debug:	fclean
	$(CC) -o $(CORE_NAME) $(SRC_CORE) $(SRC_ERROR) $(SRC_MAIN) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(SFMLFLAGS) $(DEBUGFLAG)

.PHONY: debug
