CXX         ?= c++
NAME        = phonebook
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98 -pedantic
CPPFLAGS    = -I.
SRC         = main.cpp PhoneBook.cpp
BUILD_DIR   = build
OBJ         = $(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.o))
DEPS        = $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $(NAME)..."
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(BUILD_DIR)/%.o: %.cpp $(BUILD_DIR)/.dir_stamp Makefile Contact.hpp PhoneBook.hpp
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

-include $(DEPS)

.PHONY: all clean fclean re
