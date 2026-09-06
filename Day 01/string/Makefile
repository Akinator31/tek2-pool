##
## EPITECH PROJECT, 2026
## Makefile
## File description:
## Makefile for zorglub
##

SRC_DIR     	=	.
BUILD_DIR   	=	build
BUILD_TESTS		= 	build-tests
TESTS_DIR		=	tests

SRC          	=	$(shell find . -type f -name "*.c" ! -path "./tests/*")
TESTS			=	$(shell find . -name "*.c")

OBJ          	= 	$(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJ_TESTS    	= 	$(TESTS:$(TESTS_DIR)/%.c=$(BUILD_TESTS)/%.o)

CC           	= 	epiclang
CFLAGS       	= 	-Wall -Wextra
TEST_FLAGS		=	-lcriterion

NAME         	= 	libstring.a
TESTS_NAME		=	string_test

COLOR_BLUE    := $(shell printf "\033[1;34m")
COLOR_GREEN   := $(shell printf "\033[1;32m")
COLOR_RED     := $(shell printf "\033[1;31m")

all: $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(COLOR_RED)Building $<$(COLOR_RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_TESTS)/%.o: tests/%.c
	@mkdir -p $(dir $@)
	@echo "$(COLOR_RED)Building $< for testing$(COLOR_RESET)"
	@$(CC) $(TEST_FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "$(COLOR_RED)Linking $(NAME)$(COLOR_RESET)"
	@ar rc $(NAME) $(OBJ)
	@echo "$(COLOR_GREEN)Project built successfully!$(COLOR_RESET)"

$(TESTS_NAME): $(OBJ_TESTS)
	@echo "$(COLOR_RED)Linking $(TESTS_NAME)$(COLOR_RESET)"
	@$(CC) -o $(TESTS_NAME) $(OBJ_TESTS) $(TEST_FLAGS)
	@echo "$(COLOR_GREEN)Tests build completed!$(COLOR_RESET)"

tests_run: $(TESTS_NAME)
	@echo "$(COLOR_RED)Running tests...$(COLOR_RESET)"
	@./$(TESTS_NAME)

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
