# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schennal <schennal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 15:54:02 by schennal          #+#    #+#              #
#    Updated: 2024/03/13 16:58:36 by schennal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = libft.a

# SOURCES = \
# 	ft_isalpha.c \
# 	ft_isdigit.c\
# 	ft_isalnum.c \
# 	ft_isascii.c \
# 	ft_isprint.c \
# 	ft_strlen.c \
# 	ft_memset.c \
# 	ft_bzero.c \
# 	ft_memcpy.c \
# 	ft_strlcpy.c \
# 	ft_memmove.c \
# 	ft_strlcat.c \
# 	ft_toupper.c \
# 	ft_tolower.c \
# 	ft_strchr.c \
# 	ft_strrchr.c \
# 	ft_strncmp.c \
# 	ft_memchr.c \
# 	ft_memcmp.c \
# 	ft_strnstr.c \
# 	ft_atoi.c \
# 	ft_calloc.c \
# 	ft_strdup.c \
# 	ft_substr.c \
# 	ft_strjoin.c \
# 	ft_strmapi.c \
# 	ft_putchar_fd.c \
# 	ft_putstr_fd.c \
# 	ft_putendl_fd.c \
# 	ft_putnbr_fd.c \
# 	ft_strtrim.c \
# 	ft_striteri.c \
# 	ft_split.c \
# 	ft_itoa.c \
# 	get_next_line.c \
# 	get_next_line_utils.c \

# BONUS = \
# 	ft_lstnew.c \
# 	ft_lstadd_front.c \
# 	ft_lstsize.c \
# 	ft_lstlast.c \
# 	ft_lstadd_back.c \
# 	ft_lstdelone.c \
# 	ft_lstclear.c \
# 	ft_lstiter.c \
# 	ft_lstmap.c \


# OBJECTS = $(SOURCES:.c=.o)

# BOBJECTS = $(BONUS:.c=.o)

# CC = cc

# CFLAGS = -Wall -Wextra -Werror

# all: $(NAME)

# $(NAME): $(OBJECTS)
# 		ar -rcs $(NAME) $(OBJECTS)

# bonus : $(BOBJECTS)
# 		ar -rcs $(NAME) $(BOBJECTS)

# $(OBJECTS): %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(BOBJECTS): %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	rm -f $(OBJECTS) $(BOBJECTS)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all bonus clean fclean re

NAME = libft.a

SOURCES = \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_strlcpy.c \
	ft_memmove.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strmapi.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_strtrim.c \
	ft_striteri.c \
	ft_split.c \
	ft_itoa.c \
	get_next_line.c \
	get_next_line_utils.c

BONUS = \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

OBJECTS = $(SOURCES:.c=.o)

BOBJECTS = $(BONUS:.c=.o)

OBJS_ALL := $(OBJECTS) $(BOBJECTS)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: bonus

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

# Rule to compile object files
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJS_ALL)


# Clean up object files and the library
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

bonus: $(OBJS_ALL)
	ar -rcs $(NAME) $(OBJS_ALL)

# By default, just run 'make all'
.DEFAULT_GOAL := all
