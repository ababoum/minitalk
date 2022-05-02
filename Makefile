F_NONE		= \033[37;0m
F_BOLD		= \033[1m
F_ORANGE	= \033[38m
F_RED		= \033[31m
F_YELLOW	= \033[33m
F_GREEN		= \033[32m
F_CYAN		= \033[36m
F_BLUE		= \033[34m

CC			= @gcc

CFLAGS		= -Wall -Wextra -Werror -g

SRCS		= 

INCLUDES	= 

OBJS		= $(SRCS:.c=.o)


all:
		make -C ./server
		make -C ./client

clean:
		@rm -f $(OBJS)
		make -C ./server clean
		make -C ./client clean

fclean:
		make -C ./server fclean
		make -C ./client fclean

re:	fclean all

.PHONY: clean fclean all re