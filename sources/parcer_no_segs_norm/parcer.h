/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:26:49 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/20 16:51:56 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCER_H
# define PARCER_H

// # include <mlx.h>
# include "../../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "gnl/get_next_line.h"
# include "structs.h"

int			ft_isprint(int c);
void		d_v_zeros(t_double_values_struct *d_v);
int			doubles_check(t_double_values_struct d_v, t_all_raw_map_info *data);
void		screen_check_filler(t_double_values_struct *d_v,
				t_all_raw_map_info *data);
void		no_path_check_filler(t_double_values_struct *d_v,
				t_all_raw_map_info *data);
void		so_path_check_filler(t_double_values_struct *d_v,
				t_all_raw_map_info *data);
void		we_path_check_filler(t_double_values_struct *d_v,
				t_all_raw_map_info *data);
void		ea_path_check_filler(t_double_values_struct *d_v,
				t_all_raw_map_info *data);
void		s_check_filler(t_double_values_struct *d_v,
				t_all_raw_map_info *data);
void		f_check_filler(t_double_values_struct *d_v,
				t_all_raw_map_info *data);
void		c_check_filler(t_double_values_struct *d_v,
				t_all_raw_map_info *data);
int			double_values(t_all_raw_map_info *data);
void		all_raw_map_info_starter(t_all_raw_map_info *data);
void		all_raw_map_info_start_filler(t_all_raw_map_info *data);
void		leave(char *msg);
int			get_size(char *str, int start);
int			check_line_format_res(char *str);
int			window_size_from_string(char *line, t_window *win_infos);
void		res_filler(t_all_raw_map_info *data);
int			is_space(int c);
int			minus_check(char c);
int			border_error(long long x, int sign);
int			ft_atoi(const char *str);
int			check_line_format_rgb(char *str, int c,
				int first_char_pos);
int			get_color_from_rgb(int r, int g, int b);
int			get_num_color(char *line, int *i);
int			color_from_string(char *line, int c,
				int first_char_pos, t_all_raw_map_info *win_infos);
int			char_index(char *str, char c);
void		f_filler(t_all_raw_map_info *data);
void		c_filler(t_all_raw_map_info *data);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			get_size_path(char *str, int start);
int			check_line_format_path(char *str);
int			file_exists(const char *fname);
int			path_from_string(char *line,
				t_first_chars *fc, int f_c_pos, t_all_raw_map_info *win_infos);
void		no_filler(t_all_raw_map_info *data);
void		so_filler(t_all_raw_map_info *data);
void		we_filler(t_all_raw_map_info *data);
void		ea_filler(t_all_raw_map_info *data);
void		s_filler(t_all_raw_map_info *data);
int			str_trash_checker(char *str);
int			index_after_all_info(t_all_raw_map_info *data);
int			non_important_index_check(t_all_raw_map_info *data, int i);
int			trash_checker(t_all_raw_map_info *data);
void		map_starting_point(t_all_raw_map_info *data);
int			empty_lines_in_map_checker(t_all_raw_map_info *data);
int			player_letter(t_all_raw_map_info *data, int index, int j);
int			nonmapy_symbols_in_map(t_all_raw_map_info *data);
int			player_amount(t_all_raw_map_info *data);
void		map_data_creator(t_all_raw_map_info *data);
void		map_data_empty_filler(t_all_raw_map_info *data);
void		map_data_raw_filler(t_all_raw_map_info *data);
void		map_filler(t_all_raw_map_info *data);
void		raw_data_fillers(t_all_raw_map_info *data);
void		t_map_data_filler(t_all_raw_map_info *data, t_map_data *map);
int			dublicate_error(t_all_raw_map_info *data);
int			spaces_check(t_all_raw_map_info *data);
int			parcer(char *path, t_map_data *map);
char		**matrix_copy(t_map_char xxx);
void		player_finder(t_map_char xxx, int *i, int *j);
void		cross_fillin(char **matrix,
				int start_x, int start_y, t_map_char xxx);
void		ones_and_thirds_check(char **matrix, int x, int y, t_map_char xxx);
void		start_point_check(char **matrix, int x, int y, t_map_char xxx);
int			angle_1(char **matrix, t_map_char xxx, int *i, int *j);
int			angle_2(char **matrix, int *i, int *j);
int			leak_source(char **matrix, t_map_char xxx);
int			map_leaks_check(t_map_data *map);
void		char_unit_to_int(t_map_char xxx,
				t_map_to_draw *result, int i, int j);
void		transitter(t_map_char xxx, t_map_to_draw *result);
int			cub_exists(const char *fname);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		map_staff(t_all_raw_map_info *data, t_map_data *map);
int			is_substr_in_str(char *str, char *sub_str);
size_t		ft_strlen(const char *s);
int			ft_isdigit(char c);
void		emptyness_filler(char **raw_map_data,
				t_all_raw_map_info *data, int i, int *j);
void		filler(int fd, char **raw_map_data, t_all_raw_map_info *data);
int			no_path_check_func(char *str);
int			so_path_check_func(char *str);
int			screen_check_func(char *str);
int			we_path_check_func(char *str);
int			ea_path_check_func(char *str);
int			s_check_func(char *str);
int			f_check_func(char *str);
int			c_check_func(char *str);
void		size_of_2d_arr(int fd, t_all_raw_map_info *data);
int			raw_map_filler(char **raw_map_data, char *line, int i);
void		matrix_freesher(t_map_data *map, char **matrix);
void		map_leaks_check_wid_loop(t_map_data *map, char **matrix, int i);
void		color_thrower(t_all_raw_map_info *win_infos, int rgb, char c);
int			sprite_emptyness_checker(t_all_raw_map_info *data, int i, int j);

#endif
