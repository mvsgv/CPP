NAME = PhoneBook

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = PhoneBook.cpp main.cpp Contact.cpp

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
		@rm -f $(NAME)

fclean: clean
		@rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re