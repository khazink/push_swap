# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/21 18:41:56 by kkaman            #+#    #+#              #
#    Updated: 2026/01/28 21:02:37 by kkaman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRC_PATH	= ./src/

LIBFT_PATH	= ./libft/

INCLUDES = -Iincludes -I$(LIBFT_PATH)

CC	= cc

CFLAGS	= -Wall -Wextra -Werror

LFLAGS 	= -L$(LIBFT_PATH) -lft

RM	= rm -rf

SRCS	= push_swap.c print_stack.c free_stack.c parse_args.c add_stack.c

SRC	= $(addprefix $(SRC_PATH), $(SRCS))

OBJS 	= $(SRC:.c=.o)

$(NAME)	: $(OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)  $(LFLAGS)

$(SRC_PATH)%.o	: $(SRC_PATH)%.c
	 $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all     : $(NAME)

clean	:
	 $(RM) $(OBJS)
	 make -C $(LIBFT_PATH) clean

fclean	: clean
	 $(RM) $(NAME)
	 make -C $(LIBFT_PATH) fclean

re	: fclean all

.PHONY	: all clean fclean re
