# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tales <tales@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 17:36:37 by tlima-de          #+#    #+#              #
#    Updated: 2024/06/01 17:49:09 by tales            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_split.c \
	ft_printf.c \
	print_pointer.c \
	print_unsigned.c \
	print_string.c \
	print_int.c \
	print_char.c \
	print_hex.c \
	get_next_line_utils.c \
	get_next_line.c \

	

	
NAME	=	libft.a
OBJS	=	${SRC:.c=.o}
CC	=	cc
RM	=	rm -f

CFLAGS =	-Wall -Wextra -Werror

.c.o:
	@ ${CC}  ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	@ ar rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
		@ ${RM} ${OBJS}

fclean:	clean
				@ ${RM} ${NAME}

re:			fclean all
