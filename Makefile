NAME		=	containers

NAMESPACE1	=	ft

NAMESPACE2	=	std

SRCS		=	tests/main.cpp tests/stack.cpp tests/vector.cpp tests/map.cpp

OBJDIR		=	objs

OBJDIR1		=	objs/objs_ft

OBJDIR2		=	objs/objs_std

OBJS1		=	$(addprefix $(OBJDIR1)/, $(SRCS:.cpp=.o))

OBJS2		=	$(addprefix $(OBJDIR2)/, $(SRCS:.cpp=.o))

RM			=	rm -rf

CXX			=	c++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 #-g -fsanitize=address


$(OBJDIR1)/%.o	:	%.cpp
				@mkdir -p $(@D)
				$(CXX) $(CXXFLAGS) -D NAMESPACE=$(NAMESPACE1) -c $< -o $@

$(OBJDIR2)/%.o	:	%.cpp
				@mkdir -p $(@D)
				$(CXX) $(CXXFLAGS) -D NAMESPACE=$(NAMESPACE2) -c $< -o $@

$(NAME)			:	$(NAMESPACE1) $(NAMESPACE2)


$(NAMESPACE1)	:	$(OBJS1)
				$(CXX) $(CXXFLAGS) $(OBJS1) -o $(NAMESPACE1)

$(NAMESPACE2)	:	$(OBJS2)
				$(CXX) $(CXXFLAGS) $(OBJS2) -o $(NAMESPACE2)

all				:	$(NAME)

clean			:
				$(RM) $(OBJDIR)

fclean			:	clean
				$(RM) $(NAMESPACE1) $(NAMESPACE2)

re				:	fclean all

.PHONY			:	all clean fclean re test
