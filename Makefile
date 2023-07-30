NAME = so_long
NAMEB = so_long_bonus
SRC = so_long.c \
	utils.c \
	moves.c \
	path.c \
	checkmap.c \
	mlx.c \
	ft_exit.c \
	get_next_line.c \
	get_next_line_utils.c

SRC_B = so_long_bonus.c \
		utils.c \
		moves.c \
		checkmap_b.c \
		moves_b.c \
		mlx_b.c \
		mlx.c \
		path.c \
		enemy_mv.c \
		utils_b.c \
		ft_exit.c \
		get_next_line.c \
		get_next_line_utils.c 
		
CC = cc
CFLAGS = -Wall -Wextra -Werror
FT_P = ./ft_printf/libftprintf.a
MLX = -lmlx -framework OpenGL -framework Appkit

OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./ft_printf
	$(CC) $(CFLAGS) $(OBJ) $(FT_P) $(MLX) -o $@

bonus : $(NAMEB)

 $(NAMEB) : $(OBJ_B)
	make -C ./ft_printf
	$(CC) $(CFLAGS) $(OBJ_B) $(FT_P) $(MLX) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $<
	
clean :
	make clean -C ./ft_printf
	rm -f $(OBJ) $(OBJ_B)

fclean : clean
	make fclean -C ./ft_printf
	rm -f $(NAME) $(NAMEB)

re : fclean all

.PHONY : all clean fclean re bonus