NAME				=	pipex

BONUS				=	pipex_bonus

LIBFT				=	./libft/libft.a

LIBFT_DIR			=	./libft/

SRC					=	./src/main.c ./src/parser.c \
						./src/print.c ./src/get_path.c \
						./src/destroy.c ./src/quote.c

SRC_BONUS			=	./src_bonus/main.c ./src_bonus/parser.c \
						./src_bonus/print.c ./src_bonus/get_path.c \
						./src_bonus/destroy.c ./src_bonus/quote.c \
						./src_bonus/get_cmd.c

CC					=	cc -Wall -Werror -Wextra

OBJ_DIR				=	obj

OBJ_DIR_B			=	obj_bonus

OBJ					=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir ${SRC}))

OBJ_BONUS			=	$(patsubst %.c, $(OBJ_DIR_B)/%.o, $(notdir ${SRC_BONUS}))

${shell mkdir -p ${OBJ_DIR}}

${shell mkdir -p ${OBJ_DIR_B}}

${OBJ_DIR}/%.o		:	./src/%.c
						@${CC} -o $@ -c $<

${OBJ_DIR_B}/%.o	:	./src_bonus/%.c
						@${CC} -o $@ -c $<

all					:	$(NAME)

bonus				:	$(BONUS)

$(NAME)				:	$(OBJ)
						@make --no-print-directory -C $(LIBFT_DIR)
						@$(CC) -o $@ $^ $(LIBFT)
						@rm -rf $(OBJ_DIR_B)
						@echo "Pipex :: Compilation successfully."

$(BONUS)			:	$(OBJ_BONUS)
						@make --no-print-directory -C $(LIBFT_DIR)
						@$(CC) -o $@ $^ $(LIBFT)
						@echo "Pipex_bonus :: Compilation successfully."

clean				:
						@make clean --no-print-directory -C ${LIBFT_DIR}
						@rm -rf $(OBJ_DIR) $(OBJ_DIR_B)
						@echo "Pipex :: Clean successfully."

fclean				:	clean
						@make fclean --no-print-directory -C ${LIBFT_DIR}
						@rm -f $(NAME) $(BONUS)
						@echo "Pipex :: Fclean successfully."

re					:	fclean
						@make --no-print-directory -C ./

.PHONY				:	all bonus clean fclean re
