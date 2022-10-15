NAME	=	miniRT

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
	rm -rf $(NAME) libft.a

re: fclean all

$(NAME): $(OBJ_DIR) $(OBJS)
	make -C ./libft/
	mv ./libft/libft.a ./
	$(CC) $(CFLAGS) $(OBJS) libft.a $(IMLX) -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< $(IMLX) -o $@ $(INCLUDE)

$(OBJ_DIR):
	mkdir -p $@

git:
	git add .
	git commit -m "$(m)"
	git push

.PHONY:	all clean fclean re git