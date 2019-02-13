##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make some files
##

NAME_T_LIB = test_t_lib

ALL_MY_FILES = ../sources/my_exec.c \
				../sources/env_shell.c \
				../sources/env_shell_two.c \
				../sources/call_me.c \
				../sources/bi_command.c \
				../sources/built_in.c \
				../sources/bi_cd_fn.c \
				../sources/bi_setenv_fn.c \
				../sources/bi_unsetenv_fn.c \
				../lib/my/my_strconc.c \
				../lib/my/my_strlen.c \
				../lib/my/my_str_to_word_array.c \
				../lib/my/my_putstr.c \
				../lib/my/my_strcomp.c \
				../lib/my/my_strncpy.c \
				../lib/my/my_printab.c \
				../lib/my/my_alloc.c \
				../lib/my/my_tablen.c \
				../lib/my/supr_prefix.c \
				../lib/my/my_getnbr.c \
				../lib/my/my_itoa.c \
				../lib/my/my_str_isnum.c \
				../lib/my/my_compute_power_rec.c \
				../lib/my/my_printf/my_printf.c \
				../lib/my/my_printf/my_put_base_varg.c \
				../lib/my/my_printf/my_put_base.c \
				../lib/my/my_printf/my_put_nbr_varg.c \
				../lib/my/my_printf/my_put_nbr.c \
				../lib/my/my_printf/my_putchar_varg.c \
				../lib/my/my_printf/my_putstr_scap_varg.c \
				../lib/my/my_printf/my_putstr_varg.c \
				../lib/my/my_printf/my_putchar.c \
				../lib/my/my_printf/my_putstr.c \
				../lib/my/my_printf/my_strlen.c

SRC_T_LIB =		./t_lib/critest_str_to_wordarr.c \
				./t_lib/critest_strconc.c \
				./t_lib/critest_supr_prefix.c \
				./t_lib/critest_printf.c

OBJ_T_LIB = 	$(SRC_T_LIB:.c=.o)

OBJ_FILES = 	$(ALL_MY_FILES:.c=.o)

NAME_T_SRC = 	test_t_src

SRC_T_SRC =  	./t_src/critest_binary_path.c

OBJ_T_SRC = 	$(SRC_T_SRC:.c=.o)

CFLAGS = 		-W -Wall -Wextra -Werror -lcriterion -I ../include -g3 --coverage

PRE_RULE_LIB = 	a

PRE_RULE_SRC = 	b

all: $(PRE_RULE_LIB) $(NAME_T_LIB) $(PRE_RULE_SRC) $(NAME_T_SRC)

$(PRE_RULE_LIB):
	@echo -e "\e[34m\n\tCRITERION LIB :\n\e[0m"

$(PRE_RULE_SRC):
	@echo -e "\e[34m\n\tCRITERION SOURCES :\n\e[0m"

$(NAME_T_LIB): $(OBJ_T_LIB) $(OBJ_FILES)
	@echo -e "\n"
	@gcc -o $(NAME_T_LIB) $(OBJ_T_LIB) $(OBJ_FILES) $(CFLAGS)
	@./$(NAME_T_LIB)

$(NAME_T_SRC) : $(OBJ_T_SRC) $(OBJ_FILES)
	@echo -e "\n"
	@gcc -o $(NAME_T_SRC) $(OBJ_T_SRC) $(OBJ_FILES) $(CFLAGS)
	@./$(NAME_T_SRC)

clean:
	rm -f $(OBJ_T_LIB)
	rm -f $(OBJ_T_SRC)
	rm -f ./t_lib/*.gcda
	rm -f ./t_lib/*.gcno
	rm -f ./t_src/*.gcda
	rm -f ./t_src/*.gcno
	rm -f core*
	rm -f vgcore*

fclean: clean
	rm -f $(NAME_T_LIB)
	rm -f $(NAME_T_SRC)

re: fclean all

.PHONY: all clean fclean re
