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

SRC_SNAKE	=	src/games/snake/Snake.cpp	\
				src/games/snake/SnakeLib.cpp

SRC			=	$(SRC_CORE) $(SRC_ERROR)

TESTS_SRC	=	tests/tests_args.cpp

OBJ_CORE	=	$(SRC:.cpp=.o) $(SRC_MAIN:.cpp=.o)

OBJ_SNAKE	=	$(SRC_SNAKE:.cpp=.o)

OBJ_NIBBLER	=	$(SRC_NIBBLER:.cpp=.o)

CORE_NAME = arcade

GAME_NIBBLER = ./lib/arcade_nibbler.so
GAME_SNAKE	 = ./lib/arcade_snake.so
GAME_TEST	 = ./lib/test_game.so

GRAPHIC_SFML = ./lib/arcade_sfml.so
GRAPHIC_NCURSES = ./lib/arcade_ncurses.so
GRAPHIC_SDL  = ./lib/arcade_sdl2.so

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
				-I ./include/games/snake

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

graphicals: $(GRAPHIC_SFML) $(GRAPHIC_NCURSES) $(GRAPHIC_SDL)
.PHONY: graphicals

$(GRAPHIC_SFML):
	$(CC) $(CXXFLAGS) -fpic -shared -o $(GRAPHIC_SFML) $(SRC_SFML) $(CPPFLAGS) $(SFMLFLAGS)

$(GRAPHIC_NCURSES):
	$(CC) $(CXXFLAGS) -fpic -shared -o $(GRAPHIC_NCURSES) $(SRC_NCURSES) $(CPPFLAGS) $(NCURSESFLAG)

$(GRAPHIC_SDL):
	$(CC) $(CXXFLAGS) -fpic -shared -o $(GRAPHIC_SDL) $(SRC_SDL) $(CPPFLAGS) $(SDLFLAG)

games: $(GAME_TEST) $(GAME_NIBBLER) $(GAME_SNAKE)
.PHONY: games

$(GAME_TEST):
	$(CC) $(CXXFLAGS) -fpic -shared -o $(GAME_TEST) $(SRC_GAMETEST) $(CPPFLAGS)

$(GAME_NIBBLER): $(OBJ_NIBBLER)
	$(CC) $(CXXFLAGS) -fpic -shared -o $(GAME_NIBBLER) $(SRC_NIBBLER) $(CPPFLAGS)

$(GAME_SNAKE): $(OBJ_SNAKE)
	$(CC) $(CXXFLAGS) -fpic -shared -o $(GAME_SNAKE) $(SRC_SNAKE) $(CPPFLAGS)

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
	rm -f $(OBJ_SNAKE)
	rm -f $(OBJ_NIBBLER)
.PHONY: clean

fclean:	clean
	rm -f $(CORE_NAME)
	rm -f $(GAME_NIBBLER)
	rm -f $(GAME_SNAKE)
	rm -f $(GRAPHIC_SFML)
	rm -f $(GRAPHIC_NCURSES)
	rm -f $(GRAPHIC_SDL)
.PHONY: fclean

re:	fclean all
.PHONY: re

debug:	fclean
	$(CC) -o $(CORE_NAME) $(SRC_CORE) $(SRC_ERROR) $(SRC_MAIN) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(SFMLFLAGS) $(DEBUGFLAG)

.PHONY: debug
