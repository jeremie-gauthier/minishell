# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 10:03:04 by jergauth          #+#    #+#              #
#    Updated: 2019/11/07 10:47:37 by jergauth         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell
UNAME	:= $(shell uname)

OBJS_DIRNAME= .objs

## COMMON SOURCES
SRCS_DIR= ./srcs
SRCS=	main.c\
		interpreter.c\
		exec.c\
		path_methods.c\
		core_shell.c\
		debug.c

## COMMON OBJS
OBJS= $(SRCS:.c=.o)
OBJS_DIR= $(SRCS_DIR)/$(OBJS_DIRNAME)
OBJS_PRE= $(addprefix $(OBJS_DIR)/, $(OBJS))

ALL_DIR= $(OBJS_DIR) 
ALL_PRE= $(OBJS_PRE)

## LIB
LIBFT_DIR= ./libft

## HEADERS
HEADER_DIR=	includes/
HEADER=	minishell.h\
		types.h
HEADERS= $(addprefix $(HEADER_DIR), $(HEADER))

## INCLUDES
INC= -I ./$(HEADER_DIR)
LIB_INC= -I $(LIBFT_DIR)
INCS = $(INC) $(LIB_INC)

## FLAGS
ifeq ($(UNAME), Darwin)
CC		=	gcc
CFLAGS	+=	-Wall -Werror -Wextra -O2 -fno-builtin -flto=full
endif

ifeq ($(UNAME), Linux)
CC		=	clang
CFLAGS	+=	-Wall -Werror -Wextra -O2 -fno-builtin
endif

LFLAGS	+= -L $(LIBFT_DIR) -lft

## DEBUG SYMBOLS
DSYM= $(NAME).dSYM

## RULES
all:	LIBFT $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS)
			$(CC) -c -o $@ $< $(CFLAGS) $(INCS)

$(OBJS_DIR):
			@mkdir -p $(OBJS_DIR)

$(NAME):	$(ALL_DIR) $(ALL_PRE) $(HEADERS) $(LIBFT_DIR) Makefile
			$(CC) -o $(NAME) $(CFLAGS) $(ALL_PRE) $(LFLAGS)

LIBFT:
		@make -C $(LIBFT_DIR)

clean:	
		rm -rf $(OBJS_DIR) $(DSYM)
		@make -C $(LIBFT_DIR) clean

fclean:	clean
		rm -rf $(NAME)
		@make -C $(LIBFT_DIR) fclean

re:		fclean all

.PHONY: all clean fclean re LIBFT
