NAME = Brain

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =  main.cpp Polymorphism.cpp Cat.cpp Dog.cpp Brain.cpp
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
