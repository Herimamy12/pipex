NAME	=	pipex

SRC		=	./src/main.c ./src/parser.c

CC		=	cc -Wall -Werror -Wextra

OBJ		=	$(SRC:.c=.o)

%o		:	%.c
			$(CC) -o $@ -c $<

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			$(CC) -o $@ $^

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re