NAME = btc
CC = c++
CFLAGS = -Wall -Wextra -Werror -g  -std=c++98
ODIR = ./odir/
SRCDIR = ./src/

# Color definitions
BLUE = \033[34m
GREEN = \033[32m
RED = \033[31m
RESET = \033[0m

SRC = 	$(SRCDIR)main.cpp  $(SRCDIR)BitcoinExchange.cpp

OBJ = $(SRC:$(SRCDIR)%.cpp=$(ODIR)%.o)

all: $(ODIR) $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)Linking objects...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(ODIR)%.o: $(SRCDIR)%.cpp
	@mkdir -p $(ODIR)
	@echo "$(BLUE)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

$(ODIR):
	@mkdir -p $(ODIR)

clean:
	@echo "$(BLUE)Cleaning up...$(RESET)"
	@rm -rf $(ODIR)

fclean: clean
	@echo "$(RED)Removing executable...$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
