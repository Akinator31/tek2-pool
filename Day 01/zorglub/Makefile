##
## EPITECH PROJECT, 2026
## Makefile
## File description:
## Makefile for zorglub
##

SRC_DIR     	=	.
BUILD_DIR   	=	build

SRC          	=	$(shell find . -type f -name "*.c" ! -path "./tests/*")

OBJ          	= 	$(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

CC           	= 	epiclang
CFLAGS       	= 	-Wall -Wextra

NAME         	= 	z

COLOR_BLUE    := $(shell printf "\033[1;34m")
COLOR_GREEN   := $(shell printf "\033[1;32m")
COLOR_RED     := $(shell printf "\033[1;31m")

all: $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(COLOR_RED)Building $<$(COLOR_RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "$(COLOR_RED)Linking $(NAME)$(COLOR_RESET)"
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
	@echo "$(COLOR_GREEN)Project built successfully!$(COLOR_RESET)"

clean:
	@$(RM) -r $(BUILD_DIR)
	@echo "$(COLOR_GREEN)Object files cleaned!$(COLOR_RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) -r $(BUILD_DIR)
	@echo "$(COLOR_GREEN)Project cleaned!$(COLOR_RESET)"

re: fclean all

.PHONY: all clean fclean re tests_run show_test perf_debug