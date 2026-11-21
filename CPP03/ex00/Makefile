NAME = ClapTrap

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98


SRC = main.cpp ClapTrap.cpp
OBJS = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re