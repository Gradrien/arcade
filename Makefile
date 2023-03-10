##
## EPITECH PROJECT, 2023
## arcade
## File description:
## Makefile
##

CC	=	g++

SRC_PARSER	=	src/ArgsHandler.cpp

SRC_MAIN	=	src/Main.cpp

TESTS_SRC	=	tests/tests_args.c

OBJ	=	$(SRC_PARSER:.cpp=.o) $(SRC_MAIN:.cpp=.o)

NAME = arcade

TEST_NAME	=	unit_tests

CXXFLAGS	=	-std=c++20 -Wall -Wextra -Werror -fno-gnu-unique

CPPFLAGS = -I ./include

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS) $(CPPFLAGS)

tests_run:
	$(CC) -o $(TEST_NAME) $(SRC_PARSER) $(TESTS_SRC) $(CPPFLAGS) \
	--coverage -lcriterion -lgcov
	./$(TEST_NAME)

clean_tests:
	rm -f *.gc*
	rm -f $(TEST_NAME)

coverage:
	gcovr --exclude tests/ && gcovr --exclude tests/ -b

clean: clean_tests
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY	=	all tests_run clean_tests coverage clean fclean re
