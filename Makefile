NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = src/main.c \
	src/hooks.c \
	src/mouse.c \
	src/fractol.c \
	src/utils.c \
	src/draw.c

OBJS = $(SRCS:.c=.o)
MINILIBX_DIR = ./minilibx-linux
LIBFT_DIR = ./libft
INCLUDE = -I includes -I $(MINILIBX_DIR) -I $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MINILIBX_DIR)
	$(MAKE) -C $(LIBFT_DIR) bonus
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -L$(MINILIBX_DIR) -lft -lmlx -lX11 -lm -lXext

bonus: $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MINILIBX_DIR)
	$(RM) -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MINILIBX_DIR)
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
