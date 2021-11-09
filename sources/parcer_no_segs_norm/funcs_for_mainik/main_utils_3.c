/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:24:35 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/17 21:01:45 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_for_main.h"

void	player_starter_data(t_playa *param,
		t_map_to_draw int_map, t_map_data map)
{
	param->map = (t_map *)malloc(sizeof(t_map));
	param->map->data = int_map.integer_map;
	param->map->rows = int_map.rows;
	param->map->width = int_map.width;
	param->color_floor = map.floor;
	param->color_ceiling = map.ceilling;
	param->window_height = map.window.height;
	param->window_width = map.window.width;
	param->wall_e_path = map.textures.ea_path;
	param->wall_n_path = map.textures.no_path;
	param->wall_s_path = map.textures.so_path;
	param->wall_w_path = map.textures.we_path;
	param->sprite_path = map.textures.s_path;
	param->zbuffer = (double *)malloc(sizeof(double) * param->window_width);
	param->texture_height = 64;
	param->texture_width = 64;
	param->plane_x = 0;
	param->plane_y = 0.66;
	param->dir_x = -1;
	param->dir_y = 0;
}

void	player_image_creation(t_playa *param)
{
	param->mlx_ptr = mlx_init();
	param->img.img = mlx_new_image(param->mlx_ptr,
			param->window_width, param->window_height);
	param->img.addr = mlx_get_data_addr(param->img.img,
			&(param->img.bits_per_pixel), &(param->img.line_length),
			&(param->img.endian));
}

void	player_creation(t_playa *param,
		t_map_to_draw int_map, t_map_data map)
{
	player_starter_data(param, int_map, map);
	free(param->buffer);
	player_buffer_creation(param);
	amount_of_sprites(param);
	free(param->sprite_order);
	free(param->sprite_distance);
	free(param->sprite);
	sprites_array(param);
	player_finder_on_integer_map(param);
	player_image_creation(param);
}

int	player_direction_finder(t_playa *param)
{
	int	player_direction;
	int	i;
	int	j;

	player_direction = 0;
	i = 0;
	while (i < param->map->rows)
	{
		j = 0;
		while (j < param->map->width)
		{
			if (param->map->data[i][j] > 2)
			{
				player_direction = param->map->data[i][j];
				param->map->data[i][j] = 0;
			}
			j++;
		}
		i++;
	}
	return (player_direction);
}

void	start_rotation(t_playa *param)
{
	int	player_direction;

	player_direction = player_direction_finder(param);
	if (player_direction == 4)
		rotate_to_the_right(param, M_PI_2 * 2);
	if (player_direction == 5)
		rotate_to_the_left(param, M_PI * 2);
	if (player_direction == 6)
		rotate_to_the_left(param, M_PI_2 * 2);
}
