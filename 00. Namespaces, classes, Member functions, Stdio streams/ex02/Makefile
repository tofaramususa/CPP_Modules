NAME = Account

SRCS = Account.cpp Account.hpp 

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) Account.hpp
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean: 
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
