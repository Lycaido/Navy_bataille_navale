##
## Makefile for bootstrap in /home/Rev/CSFML/bootstrap
## 
## Made by Roméo Nahon
## Login	 <Rev@epitech.net>
## 
## Started on	Thu Nov	10 12:12:07 2016 Roméo Nahon
## Last update	Thu Nov	10 12:12:07 2016 Roméo Nahon
##

SRC = 	navy.c 			\
		signal.c		\
		check_code.c	\
		map.c			\
		special.c		\
		init.c			\
		draw.c			\
		mapanalyzer.c	\
		to_send.c		\
		permission.c	\
		player2.c		\
		player1.c		\

OBJ = $(SRC:.c=.o)

NAME = navy

##CFLAGS += -W -Wall -pedantic -ansi -Werror

all: $(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -Llib/my -lmy -o $(NAME)
	rm -f $(OBJ)

val: $(SRC)
	gcc -g3 $(SRC) -Llib/my -lmy -o $(NAME)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *~
	rm -f *#

re: fclean all

.PHONY: $(NAME) all clean
