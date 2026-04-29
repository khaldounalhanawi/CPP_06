NAME = convert
CC = c++
HEADER = ScalarConverter.hpp
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = ScalarConverter.cpp \
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





test: all

	@RED=\\033[31m;GREEN=\\033[32m;RESET=\\033[0m;BLUE=\\033[34m; \
	i=0; \
	for arg in	123123 \
				-1231 \
				11872628736487236487623 \
				-11872628736487236487623 \
				a23423 \
				sa324 \
				+-34 \
				-3 \
				0000 \
				+0 \
				-0 \
				.0234 \
				1.232 \
				a.1. \
				0.a \
				"" \
				\n2 \
				\t \
				f \
				1.2f \
				1f \
				0f \
				ff \
				-4f \
				-3.f4 \
				-3.0f4;\
				do printf "$$RED(test nr.%s)$$BLUE input: $$arg\n$$RESET" $$i; \
				i=$$((i + 1)); \
				./convert $$arg; \
				done

.PHONY: all clean fclean re
