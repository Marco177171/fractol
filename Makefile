# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohassyao <ohassyao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 16:00:27 by ohassyao          #+#    #+#              #
#    Updated: 2022/10/25 15:51:39 by ohassyao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

GREENGREEN = \033[38;5;46m
RESET = \033[0m
C_LMGN = \033[95m
T_BLK = \033[5m
T_NRM = \033[25m
T_CLR = \033[K
C_YLW = \033[33m
C_GRN = \033[32m
C_LYLW = \033[93m
C_LGRN = \033[92m
C_LMGN = \033[95m
C_END = \033[0m

SRC=  src/main.c src/draw.c src/errors.c src/fractol.c src/init.c src/hook.c src/utility.c \
		src/color.c

PRINTF = ft_printf

LIBFT = libft

HDRS = mlx/

MLX = ./libmlx.dylib

OBJ = $(SRC:.c=.o)

RM = rm -f

CC		=	clang  -g  -Wall -Wextra -Werror
CFLAGS	=

LIBS = -framework OpenGL -lm -framework AppKit

NB = $(words $(FILES))

%.o: %.c
	@$(CC) -I ${HDRS} -c $< -o $@

$(NAME): $(OBJ)
		@make -C ./ft_printf
		@make -C ./libft
		@make -C ./mlx
		@mv mlx/libmlx.dylib .
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) $(LIBS) ft_printf/ft_printf.a libft/libft.a
		@echo "$(C_LGRN)➜ [$(NAME)] Program has been Compiled Successfully !$(C_END)"


all: $(NAME)
	make clean

clean:
	@${RM} $(OBJ)
	@echo "$(C_LMGN)➜ [$(NAME)] Objects have been cleaned Successfully !$(C_END)"

fclean:
	${RM} $(NAME) ${OBJ}
	@rm libmlx.dylib
	@make -C ./mlx clean
	@make -C ./ft_printf fclean
	@make -C ./libft fclean
	@echo "$(C_LMGN)➜ [$(NAME)] Library has been deleted Successfully !$(C_END)"


re: fclean $(NAME)

run: all


.PHONY: all clean fclean re reb
