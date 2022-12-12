# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 18:15:47 by jorsanch          #+#    #+#              #
#    Updated: 2022/11/03 13:30:27 by jorsanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	  ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
	  ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	  ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
	  ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	  ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_putnbrbase.c \
	  ft_uitoa.c ft_flags.c ft_magic.c ft_printf.c ft_printtools.c

FLAGS = -Wall -Werror -Wextra

all: $(NAME) clean

$(NAME): clean
	gcc -c $(FLAGS) $(SRC)
	ar -crs $(NAME) *.o		

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
