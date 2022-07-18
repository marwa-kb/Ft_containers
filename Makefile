NAME		=	test

SRCS		=	main.cpp

OBJS		=	$(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

OBJDIR		=	objs

RM			=	rm -rf

CXX			=	c++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98


$(OBJDIR)/%.o	:	%.cpp
				@mkdir -p $(@D)
				$(CXX) $(CXXFLAGS) -c $< -o $@


$(NAME)			:	$(OBJS)
				$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all				:	$(NAME)

clean			:
				$(RM) $(OBJDIR)

fclean			:	clean
				$(RM) $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re
