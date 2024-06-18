##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile to compil the -lmy
##

SRC		=	my_getnbr.c 				\
			my_intlen.c 				\
			my_put_nbr.c 				\
			my_putchar.c 				\
			my_putstr.c 				\
			my_strlen.c 				\
			my_strcmp.c 				\
			my_strdup.c 				\
			my_str_to_word_array.c 		\
			my_strncpy.c 				\
			my_nbr_ispair.c 			\
			mini_printf.c 				\
			pf.c

OBJ 	= 	$(SRC:.c=.o)

NAME	= 	libnavy.a

CFLAGS 	=	-Wall -Wshadow -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
		@$(AR) rc $(NAME) $(OBJ)
		@echo -e "\e[1;36m{ libnavy.a ready and my.h duplicated !! }\e[00;37m"

clean:
		@rm -f $(OBJ)
		@rm -f *~
		@echo -e "\e[1;33m[ Useless files have been deleted ]\e[00;37m"

fclean: clean
		@$(RM) $(NAME)
		@echo -e "\e[1;33m[ libnavy.a has been deleted ]\e[00;37m"

re: fclean all
