NAME = btc

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98


SRC = 	main.cpp \
			BitcoinExchange.cpp
OBJS = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -rf $(NAME) $(OBJS)

re:	fclean all

.PHONY: all clean fclean re