##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile to compil the -lmy
##

SRC		=	main.c		\
			parsing.c 	\
			hub.c		\
			protocol.c	\
			display.c	\
			ending.c

OBJ 	= 	$(SRC:.c=.o)

NAME	= 	my_navy

CFLAGS 	=	-I ./include

LDFLAGS 	=	-L ./lib/navy -lnavy

CC 		= 	gcc

all:	$(NAME)

./lib/navy/libnavy.a:
		@$(MAKE) -C ./lib/navy
		@cp lib/navy/navy.h ./include

$(NAME):	./lib/navy/libnavy.a $(OBJ)
		@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)
		@echo -e "\e[1;36m{ Binary is ready !! }\e[00;37m"

clean:
		@$(MAKE) clean -C ./lib/navy
		@rm -f $(OBJ)
		@rm -f *o
		@echo -e "\e[1;33m[ temp files deleted ]\e[00;37m"

fclean: clean
		@$(MAKE) fclean -C ./lib/navy
		@$(RM) $(NAME) ./include/navy.h
		@echo -e "\e[1;33m[ Binary removed ]\e[00;37m"

re: fclean all
