# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/20 14:08:06 by plisieck          #+#    #+#              #
#    Updated: 2015/02/21 20:18:59 by plisieck         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = {fdf,fdf2,fdf3,fdf4,fdf5,fdf6,fdf7,fdf8}.c
OBJ = {fdf,fdf2,fdf3,fdf4,fdf5,fdf6,fdf7,fdf8}.o
FLAGS = -Wall -Wextra -Werror
LIBS = /usr/X11/lib -lmlx -lXext -lX11

all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) -L $(LIBS) $(SRC)
	@make -C libft/
	@gcc -o $(NAME) $(FLAGS) -L $(LIBS) $(OBJ) libft/libft.a
	@echo "\033[33;32mDone !"


clean:
	@make -C ./libft clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C ./libft fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
