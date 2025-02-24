NAME			=	pipex

LIBFT			=	./libft/libft.a

LIBFT_DIR		=	./libft/

SRC				=	./src/main.c ./src/parser.c ./src/print.c \
					./src/get_path.c ./src/destroy.c ./src/get_cmd.c \
					./src/quote.c

CC				=	gcc -Wall -Werror -Wextra -g

OBJ_DIR			=	obj

OBJ				=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir ${SRC}))

.SILENT			:

${shell mkdir -p ${OBJ_DIR}}

${OBJ_DIR}/%.o	:	./src/%.c
					${CC} -o $@ -c $<

all				:	$(NAME)

$(NAME)			:	$(OBJ)
					make --no-print-directory -C $(LIBFT_DIR)
					$(CC) -o $@ $^ $(LIBFT)
					echo "Pipex :: Compilation successfully."

clean			:
					make clean --no-print-directory -C ${LIBFT_DIR}
					rm -rf $(OBJ_DIR)
					echo "Pipex :: Clean successfully."

fclean			:	clean
					make fclean --no-print-directory -C ${LIBFT_DIR}
					rm -f $(NAME) file
					echo "Pipex :: Fclean successfully."

re				:	fclean
					make --no-print-directory -C ./

.PHONY			:	all clean fclean re
