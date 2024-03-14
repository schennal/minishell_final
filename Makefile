# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schennal <schennal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 16:50:52 by schennal          #+#    #+#              #
#    Updated: 2024/03/14 17:07:11 by schennal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror #-fsanitize=address
# # Sources
# SRC_PATH	=	src/
# SRC			=	\
# main.c main_loop.c signal.c signal_tools.c init.c \
# parsing/parser_cmd.c \
# parsing/parser_redir.c \
# parsing/parser_tools.c \
# parsing/parser.c \
# parsing/token_tools.c \
# parsing/token_tools1.c \
# parsing/token_tools2.c \
# parsing/token_tools3.c \
# parsing/token_tools4.c \
# parsing/token_tools5.c \
# tokenizer.c token_tools.c token_tools1.c token_tools2.c token_tools3.c token_tools4.c token_tools5.c\
# env_tok.c env_tok_tools.c env_str.c env_str_tools.c parser.c parser_tools.c parser_cmd.c parser_redir.c \
# exe.c exe_cmd.c exe_tools.c exe_heredoc.c exe_cmd_tools.c exe_cmd_tools2.c exe_cmd_tools3.c \
# exe_cmd_tools4.c exe_cmd_tools5.c exe_cmd_tools6.c exe_cmd_tools7.c exe_cmd_tools8.c
# SRCS		= $(addprefix $(SRC_PATH), $(SRC))
# SRCS		= $(addprefix $(SRC_PATH), $(SRC))

# Sources
SRC_PATH = src/
SRC = \
main.c main_loop.c signal.c signal_tools.c init.c \
env_utils.c \
ft_free.c \
mini_utils.c \
tokenizer.c token_tools.c token_tools1.c token_tools2.c token_tools3.c token_tools4.c token_tools5.c\
env_tok.c env_tok_tools.c env_str.c env_str_tools.c parser.c parser_tools.c parser_cmd.c parser_redir.c \
exe.c exe_cmd.c exe_tools.c exe_heredoc.c exec_utils.c exec_utils2.c exec_utils3.c \
exec_utils4.c exec_utils5.c exec_utils6.c exec_utils7.c exec_utils8.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH	= 	src/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))
# Target
NAME 		= minishell

# Libft
LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# Includes
INC			=	-I ./src \
				-I ./libft/ \
				-I /usr/local/opt/readline/include
RLPATH		=	/usr/local/opt/readline/lib/

HEADER		=	$(SRC_PATH)minishell.h \
				$(SRC_PATH)env.h \
				$(SRC_PATH)env_str.h \
				$(SRC_PATH)env_tok.h \
				$(SRC_PATH)parser.h \
				$(SRC_PATH)tokenizer.h \
				$(SRC_PATH)exe.h 
# Default rule: make all
all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)
# Rule to build the library
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INC) -L$(RLPATH) -lreadline
# Rule to compile object files
$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC) 

# Clean up object files
clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_PATH)
# Clean up object files and the library
fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)
# Rebuild everything
re: fclean all

# By default, just run 'make all'
.DEFAULT_GOAL := all