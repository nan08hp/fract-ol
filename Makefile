NAME = ./fract-ol
CC = gcc
CFLAGS = -g #-Wall -Wextra -Werror
SRCS =	src/main.c \
		src/complex.c \
		src/hooks.c \
		src/fractol.c
OBJS = $(SRCS:.c=.o)
#LIBFT = ./libft/libft.a
#LIBFT_DIR = ./libft
MINILIBX_DIR = ./minilibx-linux
#INCLUDE = -I ./includes -I ./minilibx

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	#@make -C $(LIBFT_DIR) bonus
	#@make -C $(MINILIBX_DIR)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT) -L$(MINILIBX_DIR) -lmlx -lX11 -lm -lXext #-fsanitize=address

clean:
	#@make clean -C $(LIBFT_DIR)
	#@make clean -C $(MINILIBX_DIR)
	rm -f $(OBJS)

fclean: clean
	#@make fclean -C $(LIBFT_DIR)
	#@make clean -C $(MINILIBX_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

