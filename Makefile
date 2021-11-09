# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/05 19:21:59 by tsidney           #+#    #+#              #
#    Updated: 2021/04/20 18:28:01 by tsidney          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = gcc
HEADER =	sources/textures.h\
			sources/parcer_no_segs_norm/header_for_main.h\
			mlx/mlx.h\
			sources/parcer_no_segs_norm/parcer.h\
			sources/parcer_no_segs_norm/structs.h
CF =  -Wall -Werror -Wextra -c -I
SRCS =	sources/bmp_norme/bmp_norme.c\
		sources/four_tex_src_norme/main_functions.c\
		sources/four_tex_src_norme/moves.c\
		sources/four_tex_src_norme/rotations.c\
		sources/four_tex_src_norme/sprites_src.c\
		sources/four_tex_src_norme/sprites_src_2.c\
		sources/four_tex_src_norme/up_and_down.c\
		sources/four_tex_src_norme/utils.c\
		sources/four_tex_src_norme/walls.c\
		sources/four_tex_src_norme/walls_2.c\
		sources/four_tex_src_norme/walls_3.c\
		sources/parcer_no_segs_norm/mainik.c\
		sources/parcer_no_segs_norm/mainik_2.c\
		sources/parcer_no_segs_norm/checkers_for_main/checkers_for_main.c\
		sources/parcer_no_segs_norm/double_values/double_values.c\
		sources/parcer_no_segs_norm/double_values/double_values_1.c\
		sources/parcer_no_segs_norm/double_values/double_values_2.c\
		sources/parcer_no_segs_norm/double_values/double_values_3.c\
		sources/parcer_no_segs_norm/filler/filler.c\
		sources/parcer_no_segs_norm/filler/filler_1.c\
		sources/parcer_no_segs_norm/filler/filler_2.c\
		sources/parcer_no_segs_norm/filler/filler_3.c\
		sources/parcer_no_segs_norm/filler/filler_4.c\
		sources/parcer_no_segs_norm/filler/filler_5.c\
		sources/parcer_no_segs_norm/funcs_for_mainik/main_utils.c\
		sources/parcer_no_segs_norm/funcs_for_mainik/main_utils_2.c\
		sources/parcer_no_segs_norm/funcs_for_mainik/main_utils_3.c\
		sources/parcer_no_segs_norm/gnl/get_next_line.c\
		sources/parcer_no_segs_norm/gnl/get_next_line_utils.c\
		sources/parcer_no_segs_norm/map_leaks_checker/integer_map_creator.c\
		sources/parcer_no_segs_norm/map_leaks_checker/map_leaks.c\
		sources/parcer_no_segs_norm/map_leaks_checker/map_leaks_1.c\
		sources/parcer_no_segs_norm/map_leaks_checker/map_leaks_2.c\
		sources/parcer_no_segs_norm/parcer_core/parcer.c\
		sources/parcer_no_segs_norm/parcer_core/parcer_1.c\
		sources/parcer_no_segs_norm/parcer_core/parcer_2.c\
		sources/parcer_no_segs_norm/parcer_core/parcer_3.c\
		sources/parcer_no_segs_norm/parcer_core/parcer_4.c\
		sources/parcer_no_segs_norm/utilatary_funcs/parcin_utils.c\
		sources/parcer_no_segs_norm/utilatary_funcs/parcin_utils_1.c\
		sources/parcer_no_segs_norm/utilatary_funcs/parcin_utils_2.c\
		sources/parcer_no_segs_norm/utilatary_funcs/parcin_utils_3.c\
		sources/parcer_no_segs_norm/utilatary_funcs/parcin_utils_4.c\
		sources/parcer_no_segs_norm/utilatary_funcs/parcin_utils_5.c

MLX = ./liba/libmlx.a
LIBS = -lmlx -framework OpenGL -framework AppKit
OBJS = ${SRCS:.c=.o}
%.o: %.c $(HEADER)
	$(CC) $(CF) -c $< -o $@
$(NAME) : $(OBJS)
	$(CC) $(MLX) -Wall -Werror -Wextra $(LIBS) $^ -o $@
all:	$(NAME)
clean:
	@rm -f $(OBJS)
	@echo "library cleaned"
fclean: clean
	@rm -f $(NAME)
	@echo "library fully cleaned"
re: fclean all
.PHONY: re all clean fclean
