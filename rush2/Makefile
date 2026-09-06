##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile for wolf3D project
##

SRC          	=	$(shell find src -type f -name "*.hs")

BUILD_DIR		=	build

CC           	= 	ghc

NAME         	= 	pushswap_checker

COLOR_BLUE    := $(shell printf "\033[1;34m")
COLOR_GREEN   := $(shell printf "\033[1;32m")
COLOR_RED     := $(shell printf "\033[1;31m")

all: $(NAME)

$(NAME): $(SRC)
	@echo "$(COLOR_RED)Building $(NAME)$(COLOR_RESET)"
	@$(CC) -isrc -hidir $(BUILD_DIR) -odir $(BUILD_DIR) -o $(NAME) $(SRC)
	@echo "$(COLOR_GREEN)Project built successfully!$(COLOR_RESET)"

clean:
	@$(RM) -r $(BUILD_DIR)
	@echo "$(COLOR_GREEN)Object files cleaned!$(COLOR_RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) -r $(BUILD_DIR)
	@echo "$(COLOR_GREEN)Project cleaned!$(COLOR_RESET)"

re: fclean all

.PHONY: all clean fclean re