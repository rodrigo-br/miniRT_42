NAME	= miniRT_tests

HEADER	= tests.h unity.h unity_internals.h
SRCS	= unity.c tests.c test_tuple_operations.c pre_parser_errors.c parser.c \
		ft_atod.c check_light.c ft_is_all_digit.c ft_is_a_double.c checkers.c \
		check_ambient.c

MINIRT_HEADER	= structs.h minirt.h
MINIRT_SRCS		= tuple.c operations.c errors.c test_parser.c test_atod.c \
				test_check_light.c test_check_ambient.c

LIBFT_PATH	= ../libs/libft
LIBFT 	= $(LIBFT_PATH)/libft.a

MINILIBX_PATH	= ../libs/minilibx
MINILIBX		= $(MINILIBX_PATH)/libmlx.a

OBJ_DIR	= ./obj
OBJS	= $(SRCS:%.c=$(OBJ_DIR)/%.o) $(MINIRT_SRCS:%.c=$(OBJ_DIR)/%.o)

CFLAGS	= -Wall -Wextra -g3
IFLAGS	= -I. -Iunity -I../inc
LDFLAGS	= -L$(LIBFT_PATH) -lft -L$(MINILIBX_PATH) -lmlx -lXext -lX11 -lm

VPATH_MINRT	= ../src ../parser
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
	./$(NAME)

.PHONY:	all clean fclean re run
