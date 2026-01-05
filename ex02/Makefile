CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = AForm.cpp main.cpp RobotomyRequestForm.cpp Bureaucrat.cpp  PresidentialPardonForm.cpp ShrubberyCreationForm.cpp
OBJ = $(SRC:.cpp=.o)
NAME = form

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $@ $^

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
