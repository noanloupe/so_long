NAME		=	so_long

FILES		=	error.c\
				main.c\
				movements.c\
				parsing.c\
				parsing_error.c\
				pathfinding.c\
				set_struct.c\
				utils.c\
				utils2.c\
				window.c\
				window_error.c\

SRCS		=	$(addprefix srcs/, $(FILES))

OBJ			=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

### LIB INCLUDES ###

LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a


PRINTF_DIR	=	ft_printf
PRINTF		=	$(PRINTF_DIR)/libftprintf.a


GNL_DIR		=	gnl
GNL			=	$(GNL_DIR)/gnl.a


MLX_DIR		=	mlx
MLX_PATH	=	$(MLX_DIR)/libmlx.a
MLX			=	-Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit $(MLX_PATH)


### RULES ###


$(NAME):		$(OBJ)
				@echo "Making mlx..."
				@make -C $(MLX_DIR)
				@echo "Mlx done."
				@echo "Making libft..."
				@make -C $(LIBFT_DIR)
				@echo "Libft done."
				@echo "Making printf..."
				@make -C $(PRINTF_DIR)
				@echo "Printf done."
				@echo "Making gnl..."
				@make -C $(GNL_DIR)
				@echo "Gnl done.\n"
				@cc $(CFLAGS) -g -fsanitize=address $(OBJ) $(LIBFT) $(PRINTF) $(GNL) $(MLX) -o $(NAME)

.c.o:
				@cc $(CFLAGS) -g -c $< -o $(<:.c=.o)

all:			$(NAME)

clean:
				@echo "Cleaning..."
				@make clean -C $(LIBFT_DIR)
				@make clean -C $(GNL_DIR)
				@make clean -C $(PRINTF_DIR)
				@make clean -C $(MLX_DIR)
				@rm -f $(OBJ)
				@echo "Cleaned."

fclean:			clean
				@make fclean -C $(LIBFT_DIR)
				@make fclean -C $(GNL_DIR)
				@make fclean -C $(PRINTF_DIR)
				@rm -f $(NAME)

re :			fclean $(NAME)
	
.PHONY: all clean fclean re 
