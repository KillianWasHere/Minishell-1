##
## EPITECH PROJECT, 2025
## Makefile_bs_my_ls
## File description:
## compile the bootstrap for my_ls
##

NAME	=	mysh

SRC 	=	src/main.c	\
			src/Utils/str_utils.c	\
			src/Utils/my_put_nbr.c	\
			src/Utils/my_strcmp.c	\
			src/Utils/my_strcat.c	\
			src/Utils/my_revstr.c	\
			src/Utils/check_env_name.c	\
			src/Utils/check_space_tab.c	\
			src/get_words.c	\
			src/get_error.c	\
			src/my_exec.c	\
			src/free_things.c	\
			src/tty_shell.c	\
			src/Built_in/get_built_in.c	\
			src/Built_in/edit_env.c	\
			src/Built_in/remove_env.c	\
			src/Built_in/display_env.c	\
			src/Built_in/get_env.c	\
			src/Built_in/find_executable_in_path.c	\
			src/Built_in/cd.c	\

OBJ		=	$(SRC:.c=.o)

all: $(OBJ)
	epiclang $(SRC) -o $(NAME) -Wall -Wextra
	make clean

clean:
	rm -f *~
	rm -f *#

fclean: clean
	rm -f $(NAME)
	rm -f $(OBJ)

re:
	make fclean
	make all
