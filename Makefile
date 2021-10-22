CC		= gcc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -f
LIBFT	= ./libft/libft.a

NAME 	= client
SRCS	= client.c
OBJS	= $(SRCS:.c=.o)

NAME_S	= server
SRCS_S	= server.c
OBJS_S	= $(SRCS_S:.c=.o)

all:	$(NAME) $(NAME_S)

$(NAME):
	$(MAKE) bonus -C libft
	$(CC) $(SRCS) $(FLAGS) $(LIBFT) -o $(NAME)

$(NAME_S) : 
	$(CC) $(SRCS_S) $(FLAGS) $(LIBFT) -o $(NAME_S)

clean:
	$(MAKE) clean -C libft
	$(RM) $(OBJS) 
	$(RM) $(OBJS_S) 

fclean: clean
	 	$(RM) $(NAME)
	 	$(RM) $(NAME_S)

re: fclean all

.PHONY:		all clean fclean re 
