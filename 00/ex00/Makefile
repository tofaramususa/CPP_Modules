NAME = megaphone

SRCS = megaphone.cpp

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

OBJ = $(SRCS:.c=.o) 

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS)

# clean: 
# 	rm -rf $(OBJ)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

.PHONY: all clean fclean re
