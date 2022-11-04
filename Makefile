NAME	= miniRT

LIBFT_PATH	= ./libs/libft
LIBFT 	= $(LIBFT_PATH)/libft.a

MINILIBX_PATH	= ./libs/minilibx
MINILIBX		= $(MINILIBX_PATH)/libmlx.a

OBJ_DIR	= ./obj
OBJS	= $(MAIN:%.c=$(OBJ_DIR)/%.o)

HEADER_PATH		= ./inc
HEADER_FILES	= structs.h minirt.h

MAIN	= main.c $(PARSER) $(TUPLE) $(COLOR) $(CANVAS) $(MATRIX) $(RAY) \
		$(SHAPE) $(LIGHT) $(UTILS) $(WORLD) $(CAMERA) $(MLX)
PARSER	= parser.c parser_checkers.c parser_ambient.c parser_camera.c parser_light.c \
		parser_shape.c parser_sphere.c parser_plane.c parser_cylinder.c parser_error.c \
		scene_to_world.c
TUPLE	= tuple_constructors.c tuple_operations.c tuple_checkers.c tuple_manipulators.c
COLOR	= color_constructor.c color_operations.c patterns.c
CANVAS	= canvas_constructor.c canvas_destructor.c write_to_canvas.c
MATRIX	= matrix_constructor.c matrix_checker.c matrix_operations.c \
		matrix_transformations.c matrix_rotations.c matrix_view_transform.c
UTILS 	= destructors.c radians.c
RAY		= ray_constructor.c ray_destructor.c ray_operations.c ray_intersection.c \
		ray_intersection_list.c
SHAPE	= shape_constructor.c shape_destructor.c shape_setters.c \
		sphere.c plane.c cylinder.c cone.c cylinder_intersect.c cone_intersect.c
LIGHT	= material_constructor.c material_destructor.c reflection.c lighting.c \
		is_shadowed.c
WORLD	= world_constructor.c world_destructor.c world_computations.c
CAMERA	= camera_constructor.c camera_destructor.c ray_for_pixel.c camera_setter.c \
		render.c
MLX		= setup.c hooks.c

DIRS	= . tuple color canvas matrix ray shape parser transformations light utils world camera mlx
IFLAGS	= -I $(HEADER_PATH)
LDFLAGS	= -L$(LIBFT_PATH) -lft -L$(MINILIBX_PATH) -lmlx -lXext -lX11 -lm
CFLAGS	= -Wall -Wextra -Werror

VPATH	= $(addprefix ./src/, $(DIRS))
VPATH	+= $(HEADER_PATH)

ifdef DEBUG
	CFLAGS += -g3
else
	CFLAGS += -O3 -ffast-math
endif

all: $(NAME)

clean:
	rm -rf obj
	make clean -C $(LIBFT_PATH)
	make clean -C $(MINILIBX_PATH)
	make clean -C tests

fclean: clean
	rm -rf $(NAME) $(MINILIBX)
	make fclean -C $(LIBFT_PATH)
	make fclean -C tests

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

test_vall: all
	make val -C tests

.PHONY:	all clean fclean re git test
