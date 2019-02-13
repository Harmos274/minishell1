##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make some files
##

NAME = ../libmy.a

SRC =	my_strconc.c \
		my_strlen.c \
		my_str_to_word_array.c \
		my_putstr.c \
		my_strcomp.c \
		my_strncpy.c \
		my_printab.c \
		my_alloc.c \
		my_tablen.c \
		supr_prefix.c \
		my_getnbr.c \
		my_itoa.c \
		my_str_isnum.c \
		my_compute_power_rec.c \
		my_printf/my_printf.c \
		my_printf/my_put_base_varg.c \
		my_printf/my_put_base.c \
		my_printf/my_put_nbr_varg.c \
		my_printf/my_put_nbr.c \
		my_printf/my_putchar_varg.c \
		my_printf/my_putchar.c \
		my_printf/my_putstr_scap_varg.c \
		my_printf/my_putstr_varg.c \
		my_printf/my_putstr.c \
		my_printf/my_strlen.c

OBJ = $(SRC:.c=.o)

CFLAGS = -W -Wall -Wextra -Werror -L. -lmy -I ../../include

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

clean:
	@rm -f $(OBJ)
	rm -f *.gcda
	rm -f *.gcno
	rm -f ./my_printf/*.gcno
	rm -f ./my_printf/*.gcda

fclean: clean
	rm -f libmy.a
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
