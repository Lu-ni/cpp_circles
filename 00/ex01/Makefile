NAME    = phonebook

CXX     = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -pedantic

SRC     = main.cpp PhoneBook.cpp
OBJ     = $(SRC:.cpp=.o)
DEPS    = $(SRC:.cpp=.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp Contact.hpp PhoneBook.hpp
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

clean:
	rm -f $(OBJ) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
