# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaboulan <yaboulan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 23:51:20 by yaboulan          #+#    #+#              #
#    Updated: 2023/11/18 23:51:21 by yaboulan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wall -Wextra -Werror 
SRCS = ft_point.c ft_printf.c ft_putchar.c ft_puthexa.c ft_putstr.c\
ft_strchr.c
BSRCS = ${SRCS:.c=.o}
NAME = libft.a

all:${NAME}

${NAME}:${BSRCS}
	ar rc ${NAME} ${BSRCS}

clean :
	rm -rf ${BSRCS}

fclean: clean
	rm -rf ${NAME}
re : fclean all

.PHONY : all clean fclean re