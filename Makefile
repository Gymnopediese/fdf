# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 14:57:19 by albaud            #+#    #+#              #
#    Updated: 2022/11/04 10:33:55 by albaud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
MAIN 		= main.c init.c maths.c input.c colors/gradient0.c colors/gradient1.c colors/gradient2.c colors/gradient3.c colors/gradient4.c colors/gradient5.c colors/gradient6.c colors/gradient7.c colors/gradient8.c colors/gradient9.c
LIB 		= koflibc/libft.a
CC			= /usr/bin/gcc
CFLAGS		= -Wall -Wextra -Werror
MINILIBX	= -I /Library/Developer/CommandLineTools/SDKs/MacOSX12.1.sdk/usr/include -I  /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit
SANITIZE	= -fsanitize=address -static-libsan

.c.o 	:
		${CC} ${CFLAGS} -I /usr/X11/include -c $< -o ${<:.c=.o}

all		: ${NAME}

$(NAME)	: ${LIB}
		${CC} ${CFLAGS} ${MINILIBX} -o ${NAME} ${MAIN} ${LIB}

$(LIB)	: 
		make -C koflibc

clean	:
		rm -f ${OBJS}
fclean	:	clean
		rm -f ${NAME} 
re:		fclean all

lclean	: fclean
		rm -f ${LIB}
relib	: lclean all

leak	: fclean ${LIB}
		${CC} ${CFLAGS} ${SANITIZE} ${MINILIBX} -o ${NAME} ${MAIN} ${LIB}
