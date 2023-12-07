NAME = megaphone
CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = megaphone.cpp

all: $(NAME)

$(NAME) : 
			@echo "			-> Compiling $(NAME)..."
			@$(CC) $(CFLAGS) $(SRC) -o $@
			@echo "			-> Finished $(NAME)"

clean:
		@rm -rf $(NAME)

re: clean all

.PHONY: all clean re