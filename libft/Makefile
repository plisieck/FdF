# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 14:17:09 by plisieck          #+#    #+#              #
#    Updated: 2015/02/22 15:25:36 by plisieck         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
GCCW = gcc -Wall -Wextra -Werror
SRC = ft_isascii.c ft_memcmp.c ft_strchr.c ft_strlen.c ft_strrchr.c 		\
	  ft_atoi.c ft_isdigit.c ft_memcpy.c ft_strcmp.c ft_strncat.c 			\
	  ft_strstr.c ft_bzero.c ft_isprint.c ft_memmove.c ft_strcpy.c 			\
	  ft_strncmp.c ft_tolower.c ft_isalnum.c ft_memccpy.c ft_memset.c 		\
	  ft_strdup.c ft_strncpy.c ft_toupper.c ft_isalpha.c ft_memchr.c 		\
	  ft_strcat.c ft_strlcat.c ft_strnstr.c ft_strsplit.c ft_itoa.c			\
	  ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c 		\
	  ft_striter.c ft_striteri.c ft_strmap.c ft_putchar.c ft_putstr.c 		\
	  ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c 		\
	  ft_strtrim.c ft_putnbr.c ft_putendl.c ft_putchar_fd.c 				\
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstadd.c ft_lstdel.c \
	  {ft_lstdelone,ft_lstiter,ft_lstmap,ft_lstnew,ft_isspace,ft_sort_ascii,ft_revtab,ft_power,ft_length_of_int,ft_nb_of_char,ft_isupper,ft_islower,get_next_line}.c

OBJECT = ft_isascii.o ft_memcmp.o ft_strchr.o ft_strlen.o ft_strrchr.o 		\
	  ft_atoi.o ft_isdigit.o ft_memcpy.o ft_strcmp.o ft_strncat.o 			\
	  ft_strstr.o ft_bzero.o ft_isprint.o ft_memmove.o ft_strcpy.o 			\
	  ft_strncmp.o ft_tolower.o ft_isalnum.o ft_memccpy.o ft_memset.o 		\
	  ft_strdup.o ft_strncpy.o ft_toupper.o ft_isalpha.o ft_memchr.o 		\
	  ft_strcat.o ft_strlcat.o ft_strnstr.o ft_strsplit.o ft_itoa.o			\
	  ft_memalloc.o ft_memdel.o ft_strnew.o ft_strdel.o ft_strclr.o 		\
	  ft_striter.o ft_striteri.o ft_strmap.o ft_putchar.o ft_putstr.o 		\
	  ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strsub.o ft_strjoin.o 		\
	  ft_strtrim.o ft_putnbr.o ft_putendl.o ft_putchar_fd.o 				\
	  ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_lstadd.o ft_lstdel.o \
	  {ft_lstdelone,ft_lstiter,ft_lstmap,ft_lstnew,ft_isspace,ft_sort_ascii,ft_revtab,ft_power,ft_length_of_int,ft_nb_of_char,ft_isupper,ft_islower,get_next_line}.o

all: $(NAME)

$(NAME):
	@echo "Compiling..."
	@$(GCCW) -c $(SRC)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)

clean :
	@rm -f $(OBJECT)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
