# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 20:16:19 by omoudni           #+#    #+#              #
#    Updated: 2022/03/30 18:24:28 by omoudni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX_DIR = mlx_linux/
SRC_DIR = src/
OBJ_DIR = bin/
INC_DIR = includes/

SRCS = atof.c \
	   free.c \
	   main.c \
	   split.c \
	   utils_init.c \
	   file_2_cloud.c \
	   file_2_cloud_2.c \
	   init_free.c \
	   init_free_2.c \
	   open_store.c \
	   utils_parsing.c \
	   mat_calc.c \
	   mat_calc_2.c \
	   set_r_mat.c \
	   set_stp_mats.c \
	   utils_display.c \
	   utils_display_2.c \
	   display.c \
	   get_color.c \
	   set_p_mat.c \
	   utils_draw_line.c \
	   utils_draw_line_2.c \
	   utils_draw_line_3.c \
	   utils_draw_line_4.c \
	   utils_draw_line_5.c \
	   interact.c \
	   interact_2.c \
	   interact_3.c \
	   draw_menu.c

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:%.c=%.o))

FDF = fdf

CC = gcc
FLAGS = -Werror -Wextra -Wall -g -fsanitize=address
LINKS = -lXext -lX11 -lm -lz
INCPATH = -I$(INC_DIR) -I$(MLX_DIR)
LIBPATH = -L$(MLX_DIR)
MLX_LIB = libmlx_Linux.a 

all: $(FDF)

MLX:
	make -C mlx_linux

$(FDF): $(OBJS) MLX
	gcc $(OBJS) $(FLAGS) $(LIBPATH) -l:$(MLX_LIB) -lXext -lX11 -lm -lz -o $(FDF)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(INCPATH) $(FLAGS) -o $@ -c $<

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(FDF)

bonus: all

re: fclean all

.PHONY: all clean fclean re mlx libft
