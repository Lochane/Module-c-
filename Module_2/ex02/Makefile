NAME = Fixed
CXX = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp Fixed.cpp

all: $(NAME)

$(NAME) :
			@echo "			-> Compiling $(NAME)..."
			@$(CXX) $(FLAGS) $(SRC) -o $@
			@echo "			-> Finished $(NAME)"

valgrind: all
		valgrind --trace-children=yes \
		--leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes    \
    	./Zombie

clean:
		@rm -rf $(NAME)

re: clean all

.PHONY: all clean re