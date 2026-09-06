##
## EPITECH PROJECT, 2026
## Makefile
## File description:
## Makefile for zorglub
##

SRC_DIR     	=	.
BUILD_DIR   	=	build
TESTS_DIR		=	tests

SRC          	=	$(shell find . -type f -name "*.cpp" ! -path "./tests/*")
TESTS			=	$(shell find . -name "*.cpp")

OBJ          	= 	$(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

CC           	= 	clang++
CXXFLAGS       	= 	-std=c++20 -Wall -Wextra -Werror

NAME         	=	StupidUnitConverter

COLOR_BLUE    := $(shell printf "\033[1;34m")
COLOR_GREEN   := $(shell printf "\033[1;32m")
COLOR_RED     := $(shell printf "\033[1;31m")

all: $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "$(COLOR_RED)Building $<$(COLOR_RESET)"
	@$(CC) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "$(COLOR_RED)Linking $(NAME)$(COLOR_RESET)"
	@$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS)
	@echo "$(COLOR_GREEN)Project built successfully!$(COLOR_RESET)"

clean:
	@$(RM) -r $(BUILD_DIR)
	@echo "$(COLOR_GREEN)Object files cleaned!$(COLOR_RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(TESTS_NAME)
	@$(RM) -r $(BUILD_DIR)
	@$(RM) -r $(BUILD_TESTS)
	@echo "$(COLOR_GREEN)Project cleaned!$(COLOR_RESET)"

re: fclean all

.PHONY: all clean fclean re tests_run show_test perf_debug
