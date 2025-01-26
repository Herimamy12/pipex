NAME			=	pipex

LIBFT			=	./libft/libft.a

LIBFT_DIR		=	./libft/

SRC				=	./src/main.c ./src/parser.c ./src/print.c \
					./src/get_path.c destroy.c

CC				=	gcc -Wall -Werror -Wextra -g

OBJ_DIR			=	obj

OBJ				=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir ${SRC}))

# .SILENT			:

${shell mkdir -p ${OBJ_DIR}}

${OBJ_DIR}/%.o	:	./src/%.c
					${CC} ${CFLAGS} -o $@ -c $<

all				:	$(NAME)

$(NAME)			:	$(OBJ)
					make -C $(LIBFT_DIR)
					$(CC) -o $@ $^ $(LIBFT)

clean			:
					make clean -C ${LIBFT_DIR}
					rm -rf $(OBJ_DIR)
					clear

fclean			:	clean
					make fclean -C ${LIBFT_DIR}
					rm -f $(NAME)
					clear

re				:	fclean
					make -C ./

test			:	all
					clear
					./$(NAME) file1 "ls" "cat -e" file2

testv			:	all
					clear
					valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME) file1 "ls" "cat -e" file2

false			:	all
					clear
					./$(NAME) file file

.PHONY			:	all clean fclean re test testv
