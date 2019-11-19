# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 10:03:04 by jergauth          #+#    #+#              #
#    Updated: 2019/11/19 11:52:28 by jergauth         ###   ########.fr        #
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
		core_shell.c\
		signals.c\
		debug.c

BT_DIR=	$(SRCS_DIR)/builtins
BT_SRCS=	get_builtin.c\
			echo.c\
			exit.c\
			cd.c\
			env.c\
			setenv.c\
			unsetenv.c

ENV_DIR= $(SRCS_DIR)/env_methods
ENV_SRCS=	get_var.c\
			upsert_var.c\
			create_env.c\
			del_var.c\
			free_env.c

PATH_DIR= $(SRCS_DIR)/path_methods
PATH_SRCS=	create_path.c\
			free_path.c\
			get_path.c\
			reload_path.c

EXP_DIR= $(SRCS_DIR)/expansions
EXP_SRCS=	exp_parser.c\
			exp_tilde.c\
			exp_parameter.c

## COMMON OBJS
OBJS= $(SRCS:.c=.o)
OBJS_DIR= $(SRCS_DIR)/$(OBJS_DIRNAME)
OBJS_PRE= $(addprefix $(OBJS_DIR)/, $(OBJS))

BT_OBJS= $(BT_SRCS:.c=.o)
BT_OBJS_DIR= $(BT_DIR)/$(OBJS_DIRNAME)
BT_OBJS_PRE= $(addprefix $(BT_OBJS_DIR)/, $(BT_OBJS))

ENV_OBJS= $(ENV_SRCS:.c=.o)
ENV_OBJS_DIR= $(ENV_DIR)/$(OBJS_DIRNAME)
ENV_OBJS_PRE= $(addprefix $(ENV_OBJS_DIR)/, $(ENV_OBJS))

PATH_OBJS= $(PATH_SRCS:.c=.o)
PATH_OBJS_DIR= $(PATH_DIR)/$(OBJS_DIRNAME)
PATH_OBJS_PRE= $(addprefix $(PATH_OBJS_DIR)/, $(PATH_OBJS))

EXP_OBJS= $(EXP_SRCS:.c=.o)
EXP_OBJS_DIR= $(EXP_DIR)/$(OBJS_DIRNAME)
EXP_OBJS_PRE= $(addprefix $(EXP_OBJS_DIR)/, $(EXP_OBJS))

ALL_DIR= $(OBJS_DIR) $(BT_OBJS_DIR) $(ENV_OBJS_DIR) $(PATH_OBJS_DIR) $(EXP_OBJS_DIR)
ALL_PRE= $(OBJS_PRE) $(BT_OBJS_PRE) $(ENV_OBJS_PRE) $(PATH_OBJS_PRE) $(EXP_OBJS_PRE)

## LIB
LIBFT_DIR= ./libft

## HEADERS
HEADER_DIR=	includes/
HEADER=	minishell.h\
		defines.h\
		types.h

HEADERS= $(addprefix $(HEADER_DIR), $(HEADER))

## INCLUDES
INC= -I ./$(HEADER_DIR)
LIB_INC= -I $(addprefix $(LIBFT_DIR)/, $(HEADER_DIR))
INCS = $(INC) $(LIB_INC)

## FLAGS
ifeq ($(UNAME), Darwin)
CC		=	gcc
CFLAGS	+=	-Wall -Werror -Wextra# -O2 -fno-builtin -flto=full
endif

ifeq ($(UNAME), Linux)
CC		=	clang
CFLAGS	+=	-Wall -Werror -Wextra -g3 # -O2 -fno-builtin
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

$(BT_OBJS_DIR)/%.o: $(BT_DIR)/%.c $(HEADERS)
			$(CC) -c -o $@ $< $(CFLAGS) $(INCS)

$(BT_OBJS_DIR):
			@mkdir -p $(BT_OBJS_DIR)

$(ENV_OBJS_DIR)/%.o: $(ENV_DIR)/%.c $(HEADERS)
			$(CC) -c -o $@ $< $(CFLAGS) $(INCS)

$(ENV_OBJS_DIR):
			@mkdir -p $(ENV_OBJS_DIR)

$(PATH_OBJS_DIR)/%.o: $(PATH_DIR)/%.c $(HEADERS)
			$(CC) -c -o $@ $< $(CFLAGS) $(INCS)

$(PATH_OBJS_DIR):
			@mkdir -p $(PATH_OBJS_DIR)

$(EXP_OBJS_DIR)/%.o: $(EXP_DIR)/%.c $(HEADERS)
			$(CC) -c -o $@ $< $(CFLAGS) $(INCS)

$(EXP_OBJS_DIR):
			@mkdir -p $(EXP_OBJS_DIR)

$(NAME):	$(ALL_DIR) $(ALL_PRE) $(HEADERS) $(LIBFT_DIR) Makefile
			$(CC) -o $(NAME) $(CFLAGS) $(ALL_PRE) $(LFLAGS)

LIBFT:
		@make -C $(LIBFT_DIR)

clean:	
		rm -rf $(ALL_DIR) $(DSYM)
		@make -C $(LIBFT_DIR) clean

fclean:	clean
		rm -rf $(NAME)
		@make -C $(LIBFT_DIR) fclean

re:		fclean all

.PHONY: all clean fclean re LIBFT
