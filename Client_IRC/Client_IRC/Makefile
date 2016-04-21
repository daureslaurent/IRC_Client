NAME	=	ClientIrc

DIR	=	src/

SRCS	=		$(DIR)main.cpp \
				$(DIR)clientIrc.cpp \
				$(DIR)irc_net.cpp \
				$(DIR)MessageManager.cpp \
				$(DIR)reseau_cli.cpp \
				$(DIR)threadInput.cpp \
				$(DIR)util.cpp

OBJS	=	$(SRCS:.cpp=.o)

CC	=	g++

LIB		= -pthread

FLAGS	=	-std=c++0x -W -Wall -O3

RM	=	rm -f

all:	$(NAME)

$(NAME)	:
	$(CC) $(SRCS) $(FLAGS) $(LIB) -o $(NAME)
	@echo "\033[1;32m[G++][EXC] creation de -> $@\033[00m"

clean:
	@$(RM) $(OBJS)
	@echo "\033[1;36m[RM][OBJ] $@\033[00m"


fclean: clean
	@$(RM) $(NAME)
	@echo "\033[1;33m[RM][EXC] $@\033[00m"

re: fclean all
