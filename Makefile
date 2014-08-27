# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmasson <mmasson@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/16 09:32:38 by mmasson           #+#    #+#              #
#    Updated: 2014/01/18 12:22:32 by mmasson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	src/main.c			\
			src/ft_init.c			\
			src/ft_hook.c			\
			src/ft_get_param.c			\
			src/ft_draw.c			\
			src/ft_keys.c			\
			src/ft_pixel_put_to_image.c	\
			src/ft_color.c			\
			src/ft_get_pattern.c		\
			src/ft_sky.c		\
			src/ft_copy.c 		\
			src/ft_tools.c 		\
			src/ft_printf.c 	\
			src/ft_print_format.c

OBJ	= $(SRC:.c=.o)

NAME = wolf3d

CFLAGS = -Iinclude/


all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n"
	@echo "					\033[1;31m<<< WOLF IN PROGRESS >>>"
	@./loading
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) -L/usr/X11/lib -lmlx -lXext -lX11 -lm
	@echo "\033[1;36m"
	@cat header
	@echo "\033[0m"
	@cat tuto
	@echo "\n"

clean:
	@echo "\n"
	@echo "					\033[1;31m<<< REMOVE OBJECT FILES >>>"
	@./loading
	rm -f $(OBJ)

fclean:	clean
	@echo "\n"
	@echo "					\033[1;31m<<< REMOVE OBJECT FILES AND EXEC >>>"
	@./loading
	rm -f $(NAME)

re:	fclean all

love:
	@echo 