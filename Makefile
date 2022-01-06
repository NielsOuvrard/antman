##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## un makefile de qualité
##

all:
		@cp ./lib/my/my.h include/my.h
		@gcc -c lib/my/*.c
		@ar rc lib/my/libmy.a *.o
		@gcc -o antman_ -g src_antman/*.c -I./include/ -L./lib/my/ -lmy -g3
		@gcc -o giantman_ -g src_giantman/*.c -I./include/ -L./lib/my/ -lmy -g3
		mv antman_ antman/antman
		mv giantman_ giantman/giantman
		@make clean

clean:
		@rm -f *.o

fclean: clean
		@rm antman/antman
		@rm giantman/giantman

re:	fclean all

auteur:
	echo $(USER) > auteur
