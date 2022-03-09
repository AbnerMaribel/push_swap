# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 02:03:48 by amaribel          #+#    #+#              #
#    Updated: 2022/01/20 23:06:35 by amaribel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
NAME_B	= checker

SRCS	= 	push_swap.c get_argv.c get_argv_utils.c\
			from_a_to_b.c lists.c\
			commands.c commands_n.c\
			from_b_to_a.c\
			sorting.c\
			move.c utils.c\

BNS		= 	checker.c\
			get_argv.c get_argv_utils.c sorting.c\
			lists.c commands.c commands_n.c utils.c\
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\

LIB 	= ./libft/libft.a

HEADER  = push_swap.h ./libft/libft.h

RM		= rm -f
		 
OBJS	= $(SRCS:.c=.o)
BOBJS	= $(BNS:.c=.o)

CC		= gcc

CFLAGS	=	-Wall -Wextra -Werror

$(NAME):	$(OBJS) $(HEADER)
			$(MAKE) -C ./libft
			$(CC) $(CFLAGS) $(OBJS) $(LIB) -o ${NAME}

bonus:		$(BOBJS) $(HEADER) get_next_line/get_next_line.h
			$(MAKE) -C ./libft
			$(CC) $(CFLAGS) $(BOBJS) $(LIB) -o ${NAME_B}

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(BOBJS)
			$(MAKE) clean -C ./libft

fclean:		clean
			$(RM) $(NAME) checker ./libft/libft.a

re:			fclean all

.PHONY:		all clean fclean re	
