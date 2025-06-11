CXX         ?= c++
NAME        = out
# Added -g for debug symbols, useful for Valgrind/GDB
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98 -pedantic -g
CPPFLAGS    = -I.
SRC         = main.cpp Fixed.cpp
BUILD_DIR   = build
OBJ         = $(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.o))
DEPS        = $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $(NAME)..."
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(BUILD_DIR)/%.o: %.cpp $(BUILD_DIR)/.dir_stamp Makefile
	@echo "Compiling $< -> $@..."
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@ -MMD -MP -MF $(@:.o=.d)

$(BUILD_DIR)/.dir_stamp:
	@echo "Creating build directory: $(BUILD_DIR)/"
	@mkdir -p $(BUILD_DIR)
	@touch $@

clean:
	@echo "Cleaning object and dependency files..."
	rm -f $(OBJ) $(DEPS)
	@rm -f $(BUILD_DIR)/.dir_stamp

fclean: clean
	@echo "Cleaning executable..."
	rm -f $(NAME)

re: fclean all

dev: $(NAME)
	@echo "Running $(NAME) with leak check..."
	$(LEAK_CHECK_CMD)

-include $(DEPS)

.PHONY: all clean fclean re dev
