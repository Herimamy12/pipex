CC				=	cc -Wall -Wextra -Werror

NAME			=	libft.a 

SRCS			=	ft_atoi.c ft_isdigit.c ft_memmove.c ft_split.c ft_strlcpy.c \
					ft_strtrim.c ft_bzero.c ft_isprint.c ft_memset.c ft_strchr.c \
					ft_strlen.c ft_substr.c ft_calloc.c ft_itoa.c ft_putchar_fd.c \
					ft_strdup.c ft_strmapi.c ft_tolower.c ft_isalnum.c ft_memchr.c \
					ft_putendl_fd.c ft_striteri.c ft_strncmp.c  ft_toupper.c \
					ft_isalpha.c ft_memcmp.c  ft_putnbr_fd.c  ft_strjoin.c  ft_strnstr.c \
					ft_isascii.c ft_memcpy.c  ft_putstr_fd.c  ft_strlcat.c  ft_strrchr.c \
					ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstmap_bonus.c \
					ft_lstsize_bonus.c ft_lstnew_bonus.c ft_lstclear_bonus.c \
					ft_lstlast_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c \
					get_next_line_bonus.c get_next_line_utils_bonus.c \
					ft_printf.c ft_utils.c ft_utilstwo.c ft_utilsthree.c

OBJ_DIR = obj/

.SILENT			:

OBJ				=	$(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

$(OBJ_DIR)/%.o	:	%.c
					@mkdir -p $(addprefix $(OBJ_DIR), src)
					$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

all				:	$(NAME)

$(NAME)			:	$(OBJ)
					ar rsc $@ $^

clean			:
					rm -rf $(OBJ_DIR)

fclean			:	clean
					rm -f $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re
