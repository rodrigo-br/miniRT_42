NAME	= miniRT_tests

HEADER	= tests.h unity.h unity_internals.h
SRCS	= unity.c tests.c test_tuple_operations.c pre_parser_errors.c

MINIRT_HEADER	= minirt.h
MINIRT_SRCS		= tuple.c operations.c errors.c

LIBFT_PATH	= ../libs/libft
LIBFT 	= $(LIBFT_PATH)/libft.a

MINILIBX_PATH	= ../libs/minilibx
MINILIBX		= $(MINILIBX_PATH)/libmlx.a

OBJ_DIR	= ./obj
OBJS	= $(SRCS:%.c=$(OBJ_DIR)/%.o) $(MINIRT_SRCS:%.c=$(OBJ_DIR)/%.o)

CFLAGS	= -Wall -Wextra
IFLAGS	= -I. -Iunity -I../inc
LDFLAGS	= -L$(LIBFT_PATH) -lft -L$(MINILIBX_PATH) -lmlx -lXext -lX11 -lm

VPATH_MINRT	= ../src
VPATH	= $(VPATH_MINRT) unity

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re:  fclean all

$(NAME): $(OBJS) $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

$(OBJ_DIR)/%.o: %.c $(HEADER_FILES) Makefile | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

run: all
	./$(NAME) 2>/dev/null

.PHONY:	all clean fclean re run