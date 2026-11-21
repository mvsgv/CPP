NAME = Megaphone

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Megaphone.cpp

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
		@rm -rf $(NAME)

fclean: clean
		@rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re