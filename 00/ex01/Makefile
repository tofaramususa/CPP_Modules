NAME = PhoneBook

SRCS = Main.cpp Contact.cpp PhoneBook.cpp

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) PhoneBook.hpp Contact.hpp
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
