NAME = btc

SRCS = main.cpp \
		BitcoinExchange.cpp

CXX = c++
CXXFLAGS = -g3 -std=c++98 -Wall -Wextra -Werror -Iinclude

OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
