NAME    = program_name

# Compiler and flags
CXX     = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

# Source and object files
SRC     = main.cpp Class1.cpp Class2.cpp
OBJ     = $(SRC:.cpp=.o)
DEPS    = $(SRC:.cpp=.d)

# Build rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

clean:
	$(RM) $(OBJ) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
