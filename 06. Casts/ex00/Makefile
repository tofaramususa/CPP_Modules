NAME = convert

SRCS = main.cpp ScalarConverter.cpp Methods.cpp

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -Iinclude

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