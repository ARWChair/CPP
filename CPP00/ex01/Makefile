SRC	=	Contacts.cpp PhoneBook.cpp

CXX			=	c++
RM			=	rm -f
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic
NAME		=	Phonebook
OBJ			= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME):	$(OBJ)
	$(CXX) $(SRC) -o $(NAME) $(CXXFLAGS)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all