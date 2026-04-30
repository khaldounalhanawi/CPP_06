NAME = Serialize_tester
CC = c++
HEADER =	Serializer.hpp \
			Data.hpp
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Serializer.cpp \
		main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
