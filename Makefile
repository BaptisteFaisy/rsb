NAME = a.out
CC = c++
FLAGS = -Wall -Wextra -Werror
SRCS = ex00/ex00.cpp \
		ex01/ex01.cpp \
		test.cpp \
		ex02/ex02.cpp \
		ex03/ex03.cpp \
		ex04/ex04.cpp \
		ex05/ex05.cpp

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRCS) -o $(NAME) 
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out
	# @./a.out
	# @rm a.out
clean :
	rm -rf $(NAME)

fclean :
	rm -rf $(NAME)
re: clean all