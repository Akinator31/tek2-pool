##
## EPITECH PROJECT, 2077
## Makefile
## File description:
## Makefile for GKrellM project
##

SRC_DIR     	=	src
INCLUDE_DIR		=	include
BUILD_DIR   	=	build
DEBUG_DIR		=	build_debug

SRC          	=	$(shell find $(SRC_DIR) -name "*.cpp")

OBJ          	= 	$(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
OBJ_DEBUG       = 	$(SRC:$(SRC_DIR)/%.cpp=$(DEBUG_DIR)/%.o)

CXX          	= 	clang++

CXXFLAGS        =   -W -Wall -std=c++20 -I$(INCLUDE_DIR) -I$(SRC_DIR)
LDFLAGS			=	-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-network -lsfml-system -lncurses
CXXFLAGS_DEBUG  = 	-fsanitize=address -g3

NAME         	= 	MyGKrellm
DEBUG_NAME		=	debug

COLOR_BLUE    := $(shell printf "\033[1;34m")
COLOR_GREEN   := $(shell printf "\033[1;32m")
COLOR_RED     := $(shell printf "\033[1;31m")

all: $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "$(COLOR_RED)Building $<$(COLOR_RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(DEBUG_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "$(COLOR_RED)Building (debug) $<$(COLOR_RESET)"
	@$(CXX) $(CXXFLAGS) $(CXXFLAGS_DEBUG) -c $< -o $@

$(NAME): $(OBJ)
	@echo "$(COLOR_RED)Linking $(NAME)$(COLOR_RESET)"
	@$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS) $(LDFLAGS)
	@echo "$(COLOR_GREEN)Project built successfully!$(COLOR_RESET)"

$(DEBUG_NAME): $(OBJ_DEBUG)
	@echo "$(COLOR_RED)Linking (debug) $(NAME)$(COLOR_RESET)"
	@$(CXX) -o $(DEBUG_NAME) $(OBJ_DEBUG) $(CXXFLAGS) $(LDFLAGS) $(CXXFLAGS_DEBUG)
	@echo "$(COLOR_GREEN)Project built successfully (debug) !$(COLOR_RESET)"

run: clean $(NAME)
	@./$(NAME)

clean:
	@$(RM) -rf $(BUILD_DIR)
	@echo "$(COLOR_GREEN)Object files cleaned!$(COLOR_RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(DEBUG_NAME)
	@$(RM) -r $(BUILD_DIR)
	@$(RM) -r $(DEBUG_DIR)
	@echo "$(COLOR_GREEN)Project cleaned!$(COLOR_RESET)"

re: fclean all

.PHONY: all clean fclean re
