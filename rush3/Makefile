##
## EPITECH PROJECT, 2077
## Makefile
## File description:
## Makefile for bistroMatic project
##

SRC_DIR     	=	src
INCLUDE_DIR		=	include
BUILD_DIR   	=	build

SRC          	=	$(shell find $(SRC_DIR) -name "*.cpp")

OBJ          	= 	$(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

CXX          	= 	clang++
CXXFLAGS       	= 	-W -Wall -Wextra -Werror -std=c++20 -I$(INCLUDE_DIR)

NAME         	= 	bistroMatic

COLOR_BLUE    := $(shell printf "\033[1;34m")
COLOR_GREEN   := $(shell printf "\033[1;32m")
COLOR_RED     := $(shell printf "\033[1;31m")

all: $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "$(COLOR_RED)Building $<$(COLOR_RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "$(COLOR_RED)Linking $(NAME)$(COLOR_RESET)"
	@$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS)
	@echo "$(COLOR_GREEN)Project built successfully!$(COLOR_RESET)"

clean:
	@$(RM) -rf $(BUILD_DIR)
	@echo "$(COLOR_GREEN)Object files cleaned!$(COLOR_RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) -r $(BUILD_DIR)
	@echo "$(COLOR_GREEN)Project cleaned!$(COLOR_RESET)"

re: fclean all

.PHONY: all clean fclean re
