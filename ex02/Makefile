NAME = Memory

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = ${wildcard *.cpp}
OBJS = $(SRC:.cpp=.o)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re