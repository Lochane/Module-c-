NAME = PhoneBook
CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp Phonebook.class.cpp Contact.class.cpp

all: $(NAME)

$(NAME) : 
			@echo "			-> Compiling $(NAME)..."
			@$(CC) $(FLAGS) $(SRC) -o $@
			@echo "			-> Finished $(NAME)"

valgrind: all
		valgrind --trace-children=yes \
		--leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes    \
    	./PhoneBook

clean:
		@rm -rf $(NAME)

re: clean all

.PHONY: all clean re