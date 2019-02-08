##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make some files
##

RULE = RULE

$(RULE):
	@echo -e "\e[1;34m\nLIB MAKEFILE : \n\e[0m"
	make -C ./lib/my/ --no-print-directory
	@echo -e "\e[1;34m\nSOURCES MAKEFILE : \n\e[0m"
	make -C ./sources --no-print-directory

all: $(RULE)

clean:
	@echo -e "\e[2;32m\nCLEANING : \n\e[0m"
	make clean -C ./lib/my/ --no-print-directory
	make clean -C ./sources/ --no-print-directory
	rm -f vgcore*
	rm -f core*

fclean: clean
	@echo -e "\e[2;32m\nTOTAL CLEANING : \n\e[0m"
	make fclean -C ./lib/my/ --no-print-directory
	make fclean -C ./sources/ --no-print-directory

re: fclean all

.PHONY: all clean fclean re
