##
## EPITECH PROJECT, 2019
## make
## File description:
## make
## 

SRC =	getenv.c \
		my_mapcpy.c \
		main.c \
		lib.c \
		my_get.c \
		clean_str.c \
		error_handling.c \
		builtin.c \
		str_to_word_tab.c \
		path_handling.c \
		check_exec.c

SRC1 =	test.c \
		lib.c \
		getenv.c \
		error_handling.c \
		str_to_word_tab.c \
		my_mapcpy.c \
		path_handling.c

OBJ =	$(SRC:.c=.o)

OBJ1 =	$(SRC1:.c=.o)

NAME	=	mysh

NAME1	=	test

all:	$(NAME)
test:	$(NAME1)
curl:
	curl parrot.live

$(NAME):	$(OBJ)
	gcc $(SRC) -o $(NAME)
$(NAME1):	$(OBJ1)
	gcc $(SRC1) -o $(NAME1)

clean:
	rm -f $(OBJ) $(OBJ1)

fclean: clean
	rm -f $(NAME) $(NAME1)

re: fclean all
