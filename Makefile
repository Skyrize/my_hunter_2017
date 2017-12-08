##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## all clean fclean re
##

SRC	=	main.c	\
		init.c	\
		init2.c	\
		analyse_events.c	\
		sprite_move.c	\
		shot_hit.c	\
		gettime_and_destroyer.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

GFLAGS	=	-lc_graph_prog -L./lib/my -lmy

all:	prepare_lib $(NAME)

prepare_lib:
	make -C lib/my

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(GFLAGS) -lm -Wall -Werror -Wextra

clean:
	make clean -C lib/my
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
