NAME = fract-ol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = src/main.c \
	src/hooks.c \
	src/fractol.c \
	src/utils.c \
	src/draw.c

OBJS = $(SRCS:.c=.o)
MINILIBX_DIR = ./minilibx-linux
LIBFT_DIR = ./libft
INCLUDE = -I ./include -I ./minilibx_linux

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(MINILIBX_DIR)
	@make -C $(LIBFT_DIR) bonus
	$(CC) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -L$(MINILIBX_DIR) -lft -lmlx -lX11 -lm -lXext

bonus: $(NAME)

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MINILIBX_DIR)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make clean -C $(MINILIBX_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
