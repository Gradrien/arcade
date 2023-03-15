##
## EPITECH PROJECT, 2023
## arcade
## File description:
## Makefile
##

CC	=	g++

SRC_CORE	=	src/core/ArgsHandler.cpp	\
				src/core/Core.cpp

SRC_ERROR	=	src/error/Error.cpp

SRC_MAIN	=	src/Main.cpp

SRC_SFML	=	src/graphics/sfml/SFMLWindow.cpp	\
				src/graphics/sfml/SFMLDrawable.cpp	\
				src/graphics/sfml/SFMLGraphic.cpp	\
				src/graphics/sfml/SFMLGraphicLib.cpp	\

SRC			=	$(SRC_CORE) $(SRC_MAIN) $(SRC_ERROR)

TESTS_SRC	=	tests/tests_args.c

OBJ_CORE	=	$(SRC:.cpp=.o)

CORE_NAME = arcade

GAME_NIBBLER = arcade_nibbler.so
GAME_SNAKE	 = arcade_snake.so

GRAPHIC_SFML = arcade_sfml.so
GRAPHIC_NCUR = arcade_ncurses.so
GRAPHIC_SDL  = arcade_sdl2.so

TEST_NAME	=	unit_tests

CXXFLAGS	=	-std=c++20 -Wall -Wextra -Werror -fno-gnu-unique

CPPFLAGS = -I ./include/core -I ./include/graphics -I ./include/games -I ./include/graphics/sfml -I ./include/error

SFMLFLAGS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

all:	core
.PHONY: all

core:	$(CORE_NAME)
.PHONY: core

$(CORE_NAME):	$(OBJ_CORE)
	$(CC) -o $(CORE_NAME) $(OBJ_CORE) $(CXXFLAGS) $(CPPFLAGS) $(SFMLFLAGS)

games:	$(GAME1_NAME) $(GAME_SNAKE)
	$(CC) -o $(GAME_NIBBLER) $(OBJ) $(CXXFLAGS) $(CPPFLAGS)
	$(CC) -o $(GAME_SNAKE) $(OBJ) $(CXXFLAGS) $(CPPFLAGS)
.PHONY: games

graphics:
	$(CC) $(CXXFLAGS) -fpic -shared -o $(GRAPHIC_SFML) $(SRC_SFML) $(CPPFLAGS) $(SFMLFLAGS)
	cp $(GRAPHIC_SFML) ./lib/
#	$(CC) -o $(GRAPHIC_SFML) $(OBJ) $(CXXFLAGS) $(CPPFLAGS)
#	$(CC) -o $(GRAPHIC_NCUR) $(OBJ) $(CXXFLAGS) $(CPPFLAGS)
#	$(CC) -o $(GRAPHIC_SDL) $(OBJ) $(CXXFLAGS) $(CPPFLAGS)
.PHONY: graphics

tests_run:
	$(CC) -o $(TEST_NAME) $(SRC_CORE) $(TESTS_SRC) $(CPPFLAGS) \
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
	rm -f $(GRAPHIC_SFML)
	rm -f $(GRAPHIC_NCUR)
	rm -f $(GRAPHIC_SDL)
.PHONY: fclean

re:	fclean all
.PHONY: re
