SRC			= main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
NAME		= animal_with_brains_abstract
CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -pedantic -std=c++98
OBJS		= $(SRC:.cpp=.o)
RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(SRC) $(CXXFLAGS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean:
	@$(RM) $(OBJS) $(NAME)

nclean:
	@$(RM) $(NAME)

re: fclean all

super: sclean all