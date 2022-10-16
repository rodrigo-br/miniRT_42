NAME	=	miniRT
LIBFT_P	=	libft/
LIBFT 	=	$(LIBFT_P)libft.a

IMLX	= -Imlx -Lmlx -lmlx -lXext -lX11 -lm
CFLAGS	=	-Wall -Wextra -Werror -g3
OBJ_DIR	=	obj
OBJS	=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

SRCS	=	$(MAIN)
MAIN	=	main.c 

VPATH	=	src
HEADER	=	minirt.h libft/libft.h
INCLUDE	=	-I ./

all: $(NAME)

clean:
	make clean -C ./libft
	rm -rf obj

fclean: clean
	rm -rf $(NAME) $(LIBFT)

re:  fclean all

$(LIBFT):
	make -C $(LIBFT_P)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(IMLX) -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< $(IMLX) -o $@ $(INCLUDE)

$(OBJ_DIR):
	mkdir -p $@

git:
	git add .
	git commit -m "$(m)"
	git push

.PHONY:	all clean fclean re git