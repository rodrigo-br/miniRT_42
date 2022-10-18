NAME	= miniRT

LIBFT_PATH	= ./libs/libft
LIBFT 	= $(LIBFT_PATH)/libft.a

MINILIBX_PATH	= ./libs/minilibx
MINILIBX		= $(MINILIBX_PATH)/libmlx.a

OBJ_DIR	= ./obj
OBJS	= $(MAIN:%.c=$(OBJ_DIR)/%.o)

HEADER_PATH		= ./inc
HEADER_FILES	= structs.h minirt.h

MAIN	= main.c $(SRCS) $(PARSER)
SRCS	= tuple.c errors.c operations.c ft_atod.c ft_is_a_double.c ft_is_all_digit.c
PARSER	= parser.c check_light.c checkers.c check_ambient.c check_camera.c

IFLAGS	= -I $(HEADER_PATH)
LDFLAGS	= -L$(LIBFT_PATH) -lft -L$(MINILIBX_PATH) -lmlx -lXext -lX11 -lm
CFLAGS	= -Wall -Wextra -Werror

VPATH	= ./src ./parser
VPATH	+= ./inc

ifdef DEBUG
	CFLAGS += -g3
endif

all: $(NAME)

clean:
	rm -rf obj
	make clean -C $(LIBFT_PATH)
	make clean -C $(MINILIBX_PATH)

fclean: clean
	rm -rf $(NAME) $(MINILIBX)
	make fclean -C $(LIBFT_PATH)

re:  fclean all

$(LIBFT):
	make -C $(LIBFT_PATH)

$(MINILIBX):
	make -C $(MINILIBX_PATH)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

$(OBJ_DIR)/%.o: %.c $(HEADER_FILES) Makefile | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

git:
	git add .
	git commit -m "$(m)"
	git push

test: all
	make run -C tests

.PHONY:	all clean fclean re git test
