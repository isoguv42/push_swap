# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igyuveni <igyuveni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 17:05:14 by igyuveni          #+#    #+#              #
#    Updated: 2025/04/03 21:11:14 by igyuveni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME = push_swap

# Directories
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include
LIBFT_DIR = libft

# Test suite integration
TEST_REPO = https://github.com/isoguv42/push_swap_tester.git
TEST_DIR = push_swap_tester

# Source files
SRCS = \
	$(SRC_DIR)/core/main.c \
	$(SRC_DIR)/parsing/args_utils.c \
	$(SRC_DIR)/stack/init_stack.c \
	$(SRC_DIR)/stack/operations.c \
	$(SRC_DIR)/stack/stack_utils.c \
	$(SRC_DIR)/sorting/indexing.c \
	$(SRC_DIR)/sorting/small_sort.c \
	$(SRC_DIR)/sorting/radix_sort.c \
	$(SRC_DIR)/utils/free_utils.c

# Object files
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_REPO = https://github.com/isoguv42/libft.git

# Compiler settings
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I./$(INCLUDE_DIR) -I$(LIBFT_DIR)/include

# Colors for output
COLOR_GREEN = \033[1;32m
COLOR_BLUE = \033[1;34m
COLOR_ORANGE = \033[38;5;214m
COLOR_YELLOW = \033[1;33m
COLOR_RED = \033[1;31m
COLOR_RESET = \033[0m

# Default target
all: $(NAME)

# Create object directories
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/core
	@mkdir -p $(OBJ_DIR)/parsing
	@mkdir -p $(OBJ_DIR)/stack
	@mkdir -p $(OBJ_DIR)/sorting
	@mkdir -p $(OBJ_DIR)/utils

# Check and setup libft
$(LIBFT_DIR):
	@echo "$(COLOR_YELLOW)📚 Libft not found. Downloading from repository...$(COLOR_RESET)"
	@git clone $(LIBFT_REPO) $(LIBFT_DIR) 2>/dev/null || { \
		echo "$(COLOR_RED)❌ Failed to clone libft repository$(COLOR_RESET)"; \
		echo "$(COLOR_RED)Please ensure you have git installed and internet connection$(COLOR_RESET)"; \
		exit 1; \
	}
	@echo "$(COLOR_GREEN)✅ Libft downloaded successfully!$(COLOR_RESET)"

# Build libft
$(LIBFT): $(LIBFT_DIR)
	@echo "$(COLOR_YELLOW)🔨 Building libft...$(COLOR_RESET)"
	@make -C $(LIBFT_DIR) --silent
	@echo "$(COLOR_GREEN)✅ Libft built successfully!$(COLOR_RESET)"

# Main executable
$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	@echo "$(COLOR_YELLOW)🔨 Building push_swap...$(COLOR_RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(COLOR_ORANGE)🚀 Push_swap built successfully!$(COLOR_RESET)"

# Compile object files with progress
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# Download test suite
$(TEST_DIR):
	@echo "$(COLOR_YELLOW)📚 Downloading test suite...$(COLOR_RESET)"
	@git clone $(TEST_REPO) $(TEST_DIR) 2>/dev/null || { \
		echo "$(COLOR_RED)❌ Failed to clone test repository$(COLOR_RESET)"; \
		echo "$(COLOR_RED)Please ensure you have git installed and internet connection$(COLOR_RESET)"; \
		exit 1; \
	}
	@echo "$(COLOR_GREEN)✅ Test suite downloaded successfully!$(COLOR_RESET)"

# Clean object files
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		rm -rf $(OBJ_DIR); \
		echo "$(COLOR_BLUE)🧹 Object files cleaned.$(COLOR_RESET)"; \
	fi
	@if [ -d "$(LIBFT_DIR)" ]; then \
		make -C $(LIBFT_DIR) clean --silent; \
	fi

# Clean everything including libft and test suite
fclean: clean
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME); \
		echo "$(COLOR_BLUE)🗑️  Executable cleaned.$(COLOR_RESET)"; \
	fi
	@if [ -d "$(LIBFT_DIR)" ]; then \
		rm -rf $(LIBFT_DIR); \
		echo "$(COLOR_BLUE)🗑️  Libft directory removed.$(COLOR_RESET)"; \
	fi
	@if [ -d "$(TEST_DIR)" ]; then \
		rm -rf $(TEST_DIR); \
		echo "$(COLOR_BLUE)🗑️  Test suite removed.$(COLOR_RESET)"; \
	fi

# Rebuild everything
re: fclean all

# Install dependencies (libft)
install: $(LIBFT_DIR)
	@echo "$(COLOR_GREEN)✅ Dependencies installed!$(COLOR_RESET)"

# Show project information
info:
	@echo "$(COLOR_ORANGE)📋 Project Information:$(COLOR_RESET)"
	@echo "$(COLOR_BLUE)   Name: $(NAME)$(COLOR_RESET)"
	@echo "$(COLOR_BLUE)   Source files: $(words $(SRCS))$(COLOR_RESET)"
	@echo "$(COLOR_BLUE)   Compiler: $(CC)$(COLOR_RESET)"
	@echo "$(COLOR_BLUE)   Flags: $(CFLAGS)$(COLOR_RESET)"
	@echo "$(COLOR_BLUE)   Libft: $(LIBFT_REPO)$(COLOR_RESET)"
	@echo "$(COLOR_BLUE)   Test Suite: $(TEST_REPO)$(COLOR_RESET)"

# Run main test suite
test: $(NAME) $(TEST_DIR)
	@echo "$(COLOR_YELLOW)🧪 Running test suite...$(COLOR_RESET)"
	@./$(TEST_DIR)/test_push_swap.sh

# Run basic tests only
test-basic: $(NAME) $(TEST_DIR)
	@echo "$(COLOR_YELLOW)🧪 Running basic tests only...$(COLOR_RESET)"
	@./$(TEST_DIR)/test_push_swap.sh

# Run performance benchmarks
test-performance: $(NAME) $(TEST_DIR)
	@echo "$(COLOR_YELLOW)⚡ Running performance benchmarks...$(COLOR_RESET)"
	@./$(TEST_DIR)/test_push_swap.sh --performance

# Help target
help:
	@echo "$(COLOR_ORANGE)🆘 Available targets:$(COLOR_RESET)"
	@echo "$(COLOR_GREEN)  all$(COLOR_RESET)              - Build the project"
	@echo "$(COLOR_GREEN)  clean$(COLOR_RESET)            - Remove object files"
	@echo "$(COLOR_GREEN)  fclean$(COLOR_RESET)           - Remove everything including libft and test suite"
	@echo "$(COLOR_GREEN)  re$(COLOR_RESET)               - Rebuild everything"
	@echo "$(COLOR_GREEN)  install$(COLOR_RESET)          - Install dependencies (libft)"
	@echo "$(COLOR_GREEN)  info$(COLOR_RESET)             - Show project information"
	@echo "$(COLOR_GREEN)  help$(COLOR_RESET)             - Show this help message"
	@echo
	@echo "$(COLOR_YELLOW)🧪 Test Targets:$(COLOR_RESET)"
	@echo "$(COLOR_GREEN)  test$(COLOR_RESET)             - Run comprehensive test suite (31 tests)"
	@echo "$(COLOR_GREEN)  test-basic$(COLOR_RESET)       - Same as test (for compatibility)"
	@echo "$(COLOR_GREEN)  test-performance$(COLOR_RESET) - Run performance benchmarks with 42 evaluation"
	@echo
	@echo "$(COLOR_YELLOW)🔧 Test Suite:$(COLOR_RESET)"
	@echo "$(COLOR_GREEN)  Repository: $(TEST_REPO)$(COLOR_RESET)"
	@echo "$(COLOR_GREEN)  Auto-download on first test run$(COLOR_RESET)"
	@echo "$(COLOR_GREEN)  Removed with 'make fclean'$(COLOR_RESET)"

# Declare phony targets
.PHONY: all clean fclean re install info test test-basic test-performance help
