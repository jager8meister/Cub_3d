/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:26:49 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/19 21:33:21 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

// # include <mlx.h>
# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_map
{
	int				**data;
	int				width;
	int				rows;
}				t_map;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}				t_data;

typedef struct s_img
{
	void			*ptr;
	int				*data;
	int				width;
	int				height;
	int				size_l;
	int				bpp;
	int				endian;
}				t_img;

typedef struct s_sprite
{
	double			x;
	double			y;
}				t_sprite;

typedef struct s_playa
{
	int				window_height;
	int				window_width;
	int				angle_orig;
	void			*mlx_ptr;
	void			*win_ptr;
	t_map			*map;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	unsigned int	**buffer;
	double			*zbuffer;
	int				num_sprites;
	int				*sprite_order;
	double			*sprite_distance;
	t_sprite		*sprite;
	int				texture_width;
	int				texture_height;
	unsigned int	color_floor;
	unsigned int	color_ceiling;
	char			*wall_n_path;
	char			*wall_s_path;
	char			*wall_e_path;
	char			*wall_w_path;
	char			*sprite_path;
	t_data			img;
	int				move_forward;
	int				move_back;
	int				move_left;
	int				move_right;
	int				rotate_to_the_left;
	int				rotate_to_the_right;
	int				escape;
}				t_playa;

typedef struct s_texture
{
	int				img_width;
	int				img_height;
	char			*texture_path;
	t_img			texture_image;
}				t_texture;

typedef struct s_walls
{
	t_texture		wall_n;
	t_texture		wall_s;
	t_texture		wall_e;
	t_texture		wall_w;
}				t_walls;

typedef struct s_sort_sprites_struct
{
	int				tmp;
	double			tmp_d;
	int				i;
	int				j;
	int				was_exit;
}				t_sort_sprites_struct;

typedef struct s_wall_render_struct
{
	int				x;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				tex_num;
	double			wallx;
	int				tex_width;
	int				tex_height;
	int				texx;
	double			step;
	double			texpos;
	int				y;
	int				texy;
	unsigned int	color;
}				t_wall_render_struct;

typedef struct s_sprites_render_struct
{
	int				sprite_num;
	double			sprite_x;
	double			sprite_y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				sprite_screen_x;
	double			u_div;
	double			v_div;
	double			v_move;
	int				v_move_screen;
	int				sprite_height;
	int				draw_start_y;
	int				draw_end_y;
	int				sprite_width;
	int				draw_start_x;
	int				draw_end_x;
	int				line;
	int				texx;
	int				y_pos;
	int				d;
	int				texy;
	unsigned int	color;
}				t_sprites_render_struct;

typedef struct s_everything
{
	t_walls			walls;
	t_texture		sprite_texture;
	t_data			img;
	t_playa			*param;
}				t_everything;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			draw_buffer(t_playa *param, t_data *image);
int				draw_image_on_everything(t_everything *all_data);
void			sort_sprites_data_swap(t_sort_sprites_struct *data,
					double *dist, int *order);
void			sort_sprites(int *order, double *dist, int amount);
void			texture_starter(t_texture *parameter, void *mlx_ptr);
void			move_forward(t_playa *param, double move_speed);
void			move_backward(t_playa *param, double move_speed);
void			move_to_the_right(t_playa *param, double move_speed);
void			move_to_the_left(t_playa *param, double move_speed);
void			rotate_to_the_right(t_playa *param, double rotation_speed);
void			rotate_to_the_left(t_playa *param, double rotation_speed);
void			key_handler(t_playa *param);
void			wall_render_struct_starter(t_wall_render_struct *data,
					t_playa *param);
void			raydirs_xy_checker(t_wall_render_struct *data, t_playa *param);
void			wall_render_hit_loop(t_wall_render_struct *data,
					t_playa *param);
void			data_start_points_wallx(t_wall_render_struct *data,
					t_playa *param);
void			cardinal_points_wall(t_wall_render_struct *data,
					t_playa *param, t_walls *walls);
void			tex_x_start(t_wall_render_struct *data, t_playa *param);
void			buffer_floor_filler(t_wall_render_struct *data,
					t_playa *param);
void			buffer_wall_sides_finder(t_wall_render_struct *data,
					t_playa *param, t_walls *walls);
void			buffer_wall_filler(t_wall_render_struct *data,
					t_playa *param, t_walls *walls);
void			buffer_ceiling_filler(t_wall_render_struct *data,
					t_playa *param);
void			wall_render_loop_core(t_wall_render_struct *data,
					t_playa *param, t_walls *walls);
void			wall_render(t_playa *param, t_walls *walls);
void			sprite_arr_filler(t_playa *param);
void			walls_starter(t_playa *param, t_walls *walls);
void			sprites_render_start_data(t_sprites_render_struct *data,
					t_playa *param);
void			sprites_render_draw_starts(t_sprites_render_struct *data,
					t_playa *param);
void			sprites_dr_texy_and_color(t_sprites_render_struct *data,
					t_playa *param, t_texture sprite_texture);
void			sprites_drawer(t_sprites_render_struct *data,
					t_playa *param, t_texture sprite_texture);
void			sprites_render(t_playa *param, t_texture sprite_texture);
void			data_starter(t_playa *param,
					t_walls *walls, t_texture *sprite_texture);
int				deal_key(int key, t_playa *param);
int				event_destroy_window(void);
char			*ft_strjoin(char *s1, char const *s2);
void			draw_image(t_walls *walls, t_texture *sprite_texture,
					t_data *img, t_playa *param);
void			take_screenshot(t_data *all, t_playa *param);
void			write_img(int fd, t_data *all, t_playa *param);

#endif
