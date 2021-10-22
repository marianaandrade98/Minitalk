# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mandrade <mandrade@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 20:10:19 by mandrade          #+#    #+#              #
#    Updated: 2021/10/13 14:40:27 by mandrade         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libft.a
HEADER		= libft.h
INCLUDES	= -Idouble_lst -I.
FLAGS      	= -Wall -Wextra -Werror -g
RM          = rm -f

SRCS        = ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
                ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c \
                ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
                ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c \
                ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
                ft_strrchr.c ft_tolower.c ft_toupper.c ft_itoa.c \
                ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
                ft_putstr_fd.c ft_split.c ft_strjoin.c ft_strmapi.c \
                ft_strtrim.c ft_substr.c ft_atoi.c ft_swap.c ft_putstr.c ft_putchar.c \
				ft_atoll.c ft_str_isnumeric.c ft_isint.c

OBJS        = $(SRCS:.c=.o)

SRCS_DLST = double_lst/ft_dlstadd_back.c double_lst/ft_dlstadd_front.c \
			double_lst/ft_dlst_clear.c double_lst/ft_dlst_first.c \
			double_lst/ft_dlst_last.c double_lst/ft_dlst_max.c \
			double_lst/ft_dlst_min.c double_lst/ft_dlst_new.c \
			double_lst/ft_dlst_remove.c double_lst/ft_dlst_size.c \
			double_lst/ft_dlstis_dup.c double_lst/ft_dlstis_sorted.c \
			double_lst/ft_dlst_print.c double_lst/ft_dlst_duplicate.c \
			double_lst/ft_dlst_find.c double_lst/ft_dlst_get.c\
			double_lst/ft_dlst_has_bigger.c double_lst/ft_dlst_median.c \
			double_lst/ft_dlst_sort.c

OBJS_DLST = $(SRCS_DLST:.c=.o)

BONUS_S     = ft_lstsize.c ft_lstnew.c ft_lstmap.c ft_lstiter.c ft_lstlast.c \
            	ft_lstdelone.c ft_lstclear.c ft_lstadd_front.c ft_lstadd_back.c

BONUS_O =	$(BONUS_S:.c=.o)

all:		$(NAME)

%.o: %.c 
	gcc $(FLAGS) $(INCLUDES) -c -o $@ $<

$(NAME): $(OBJS) $(BONUS_O) $(OBJS_DLST)
	ar -rs $(NAME) $(OBJS) $(BONUS_O) $(OBJS_DLST)

bonus:		$(NAME) $(BONUS_O)
			ar -rcs $(NAME) $(BONUS_O)

.c.o:
			gcc $(FLAGS) -I$(HEADER) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS) $(BONUS_O) $(OBJS_DLST)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

rebonus:	fclean bonus

.PHONY:		all clean fclean re bonus rebonus
