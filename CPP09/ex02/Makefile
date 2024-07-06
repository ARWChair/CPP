SRC			= main.cpp PmergeMe.cpp
NAME		= PmergeMe
CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -pedantic -std=c++98 -g
OBJS		= $(SRC:.cpp=.o)
RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(SRC) $(CXXFLAGS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean:
	@$(RM) $(OBJS) $(NAME)

re: fclean all