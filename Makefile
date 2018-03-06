# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbondare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/17 16:27:13 by vbondare          #+#    #+#              #
#    Updated: 2017/11/17 16:27:16 by vbondare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

SRC = cone.c cylinder.c fong_shadow.c init.c intersection.c lambert.c \
light.c list_func.c main.c menu.c normal.c plane.c raytrace.c scene.c \
sphere.c vector_func.c vector_func1.c 

LIB = libft/libft.a

FLAGS = -Wall -Wextra -Werror

.phony: all re clean fclean

all:
	@make -C libft/
	@cc -o $(NAME) $(FLAGS) $(SRC) $(LIB) -lmlx -framework OpenGl -framework AppKit

clean:
	@/bin/rm -rf $(NAME)

fclean: clean 
	@make fclean -C libft/

re: clean all