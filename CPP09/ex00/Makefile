SRC			= main.cpp BitcoinExchange.cpp
NAME		= BitcoinExchange
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

re: fclean all