NAME = a.out
CC = c++
FLAGS = -Wall -Wextra -Werror
SRCS = ex00/ex00.cpp \
		ex01/ex01.cpp \
		test.cpp \
		ex02/ex02.cpp \
		ex03/ex03.cpp \
		ex04/ex04.cpp

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRCS) -o $(NAME) 
	@valgrind ./a.out
	@rm a.out
clean :
	rm -rf $(NAME)

fclean :
	rm -rf $(NAME)
re: clean all