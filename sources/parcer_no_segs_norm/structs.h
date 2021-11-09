/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 20:22:47 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/18 17:57:05 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_map_char
{
	char			**data;
	int				width;
	int				rows;
}				t_map_char;

typedef struct s_widnow
{
	int		width;
	int		height;
}				t_window;

typedef struct s_textures_path
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*s_path;
}				t_textures_path;

typedef struct s_map_data
{
	t_window			window;
	t_textures_path		textures;
	unsigned int		floor;
	unsigned int		ceilling;
	t_map_char			map;
}				t_map_data;

typedef struct s_all_raw_map_info
{
	char			**raw_map_data;
	unsigned int	rows;
	unsigned int	length;
	int				r_line_index;
	int				no_line_index;
	int				so_line_index;
	int				we_line_index;
	int				ea_line_index;
	int				s_line_index;
	int				f_line_index;
	int				c_line_index;
	t_window		screen_size;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	char			*s_path;
	int				map_start;
	t_map_char		map;
}				t_all_raw_map_info;

typedef struct s_double_values_struct
{
	int		screen_check;
	int		no_path_check;
	int		so_path_check;
	int		we_path_check;
	int		ea_path_check;
	int		s_check;
	int		f_check;
	int		c_check;
	char	*line;
	int		i;
}				t_double_values_struct;

typedef struct s_first_chars
{
	int					c0;
	int					c1;
}				t_first_chars;

typedef struct s_map_to_draw
{
	int		**integer_map;
	int		width;
	int		rows;
}				t_map_to_draw;

typedef struct s_size_of_2d_arr
{
	int			tmp_length;
	char		*line;
	int			k;
	long long	ll_num;
}				t_size_of_2d_arr;
#endif
