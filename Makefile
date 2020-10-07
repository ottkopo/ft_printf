#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/17 15:41:09 by okoponen          #+#    #+#              #
#    Updated: 2020/09/07 14:30:54 by okoponen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SRC = srcs/ft_printf.c srcs/field_width.c srcs/precision.c srcs/parse_integer.c\
	srcs/flags.c srcs/cast_number.c srcs/extras.c srcs/parse_char.c \
	srcs/parse_string.c srcs/parse_pointer.c srcs/parse_percent.c\
	srcs/parse_hexadecimal.c srcs/parse_unsigned_int.c srcs/parse_octal.c\
	srcs/ft_ftoa.c srcs/parse_float.c

OBJ = ft_printf.o field_width.o precision.o parse_integer.o flags.o\
	cast_number.o extras.o parse_char.o parse_string.o parse_pointer.o\
	parse_percent.o parse_hexadecimal.o parse_unsigned_int.o parse_octal.o\
	ft_ftoa.o parse_float.o

LIBFT = ./libft/libft.a

.PHONY : all clean fclean re ft_printf

all : $(NAME)

$(NAME) :
	@ make -C libft/ fclean && make -C libft/
	@ cp $(LIBFT) $(NAME)
	@ gcc -Wall -Wextra -Werror -c $(SRC)
	@ ar rc $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)
	make clean -C libft/

fclean : clean
	rm -f $(NAME)
	rm -f $(OBJ)
	make fclean -C libft/

re : fclean all

test :
	@ cp $(LIBFT) $(NAME)
	@ gcc -Wall -Wextra -Werror -c $(SRC)
	@ ar rc $(NAME) $(OBJ)
	@ make clean
	gcc -Wall -Werror -Wextra -o ft_printf libftprintf.a main.c libft/libft.a -I includes -I libft