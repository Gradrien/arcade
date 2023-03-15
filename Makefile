##
## EPITECH PROJECT, 2023
## arcade
## File description:
## Makefile
##

CC	=	g++

SRC_CORE	=	src/core/ArgsHandler.cpp

SRC_MAIN	=	src/Main.cpp

SRC			=	$(SRC_CORE) $(SRC_MAIN)

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

CPPFLAGS = -I ./include/core -I ./include/graphics -I ./include/games

all:	core
.PHONY: all

core:	$(CORE_NAME)
.PHONY: core

$(CORE_NAME):	$(OBJ_CORE)
	$(CC) -o $(CORE_NAME) $(OBJ_CORE) $(CXXFLAGS) $(CPPFLAGS)

games:	$(GAME1_NAME) $(GAME_SNAKE)
	$(CC) -o $(GAME_NIBBLER) $(OBJ) $(CXXFLAGS) $(CPPFLAGS)
	$(CC) -o $(GAME_SNAKE) $(OBJ) $(CXXFLAGS) $(CPPFLAGS)
.PHONY: games

graphics:	$(GRAPHIC_SFML) $(GRAPHIC_NCUR) $(GRAPHIC_SDL)
	$(CC) -o $(GRAPHIC_SFML) $(OBJ) $(CXXFLAGS) $(CPPFLAGS)
	$(CC) -o $(GRAPHIC_NCUR) $(OBJ) $(CXXFLAGS) $(CPPFLAGS)
	$(CC) -o $(GRAPHIC_SDL) $(OBJ) $(CXXFLAGS) $(CPPFLAGS)
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
