NAME			=	pipex

SRC				=	./src/main.c ./src/parser.c

CC				=	cc -Wall -Werror -Wextra

OBJ_DIR			=	obj

OBJ				=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir ${SRC}))

${shell mkdir -p ${OBJ_DIR}}

${OBJ_DIR}/%.o	:	./src/%.c
					${CC} ${CFLAGS} -o $@ -c $<

all				:	$(NAME)

$(NAME)			:	$(OBJ)
					$(CC) -o $@ $^

clean			:
					rm -rf $(OBJ_DIR)
					clear

fclean			:	clean
					rm -f $(NAME)
					clear

re				:	fclean all

test			:	all
					clear
					./$(NAME) file1 "ls -l -a -t" "cat -e" file2

false			:	all
					clear
					./$(NAME) file file

.PHONY			:	all clean fclean re