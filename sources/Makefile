##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make some files
##
CC	= gcc

NAME = ../mysh

SRC = my_exec.c \
	env_shell.c \
	env_shell_two.c \
	call_me.c \
	bi_command.c \
	built_in.c \
	bi_cd_fn.c \
	bi_setenv_fn.c \
	bi_unsetenv_fn.c \
	main.c

OBJ = $(SRC:.c=.o)

CFLAGS = -W -Wall -Wextra -Werror -I ../include

LDFLAGS = -L ../lib/ -lmy 


$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

all: $(NAME)

clean:
	@rm -f $(OBJ)
	rm -f *.gcda
	rm -f *.gcno

fclean: clean
	rm -f libmy.a
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
