NAME		= PmergeMe
	
CC			= c++
FLAGS		= -g #-Wall -Wextra -Werror -std=c++98 -g
RM			= rm -rf

OBJDIR = .objFiles

FILES		= main  PmergeMe
#TPPFILES    = 

SRC			= $(FILES:=.cpp)#(FILES:=.tpp))
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		=  PmergeMe.hpp

#Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m


all: $(NAME)

$(NAME): $(OBJ) $(HEADER)

	@printf "$(_SUCCESS) $(GREEN)			-> Compiling $(NAME)...\n$(RESET)"
	@$(CC) $(OBJ) $(OPTS) -o $(NAME)
	@printf "$(_SUCCESS) $(GREEN)			-> Finished $(NAME)\n$(RESET)"

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(OPTS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR) $(OBJ)
	@printf "$(YELLOW)			-> Object files removed.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(YELLOW)			-> Executable removed.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re bonus
