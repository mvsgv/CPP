NAME	= ex01
CXX		= c++ 
CXXFLAGS = -Wall -Werror -Wextra  -std=c++98

SRCS = 	main.cpp \
		Span.cpp

OBJS =  $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:
	rm -rf $(NAME) $(OBJS)

re: fclean all

.PHONY : all clean fclean re