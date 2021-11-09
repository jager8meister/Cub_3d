/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:11:45 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/11 15:33:21 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../textures.h"

void	data_start_points_wallx(t_wall_render_struct *data,
t_playa *param)
{
	if (data->side == 0)
		data->perp_wall_dist = (data->map_x
				- param->pos_x + (1 - data->step_x) / 2) / data->ray_dir_x;
	else
		data->perp_wall_dist = (data->map_y
				- param->pos_y + (1 - data->step_y) / 2) / data->ray_dir_y;
	data->line_height = (int)(param->window_height / data->perp_wall_dist);
	data->draw_start = -data->line_height / 2
		+ param->window_height / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + param->window_height / 2;
	if (data->draw_end >= param->window_height)
		data->draw_end = param->window_height - 1;
	data->tex_num = param->map->data[data->map_x][data->map_y] - 1;
	if (data->side == 0)
		data->wallx = param->pos_y + data->perp_wall_dist * data->ray_dir_y;
	else
		data->wallx = param->pos_x + data->perp_wall_dist * data->ray_dir_x;
	data->wallx -= floor((data->wallx));
}

void	tex_x_start(t_wall_render_struct *data, t_playa *param)
{
	data->texx = (int)(data->wallx * (double)(data->tex_width));
	if (data->side == 0 && data->ray_dir_x > 0)
		data->texx = data->tex_width - data->texx - 1;
	if (data->side == 1 && data->ray_dir_y < 0)
		data->texx = data->tex_width - data->texx - 1;
	data->step = 1.0 * data->tex_height / data->line_height;
	data->texpos = (data->draw_start - param->window_height / 2
			+ data->line_height / 2) * data->step;
}

void	raydirs_xy_checker(t_wall_render_struct *data, t_playa *param)
{
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (param->pos_x - data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + 1.0
				- param->pos_x) * data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (param->pos_y - data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + 1.0
				- param->pos_y) * data->delta_dist_y;
	}
}

void	wall_render_loop_core(t_wall_render_struct *data,
t_playa *param, t_walls *walls)
{
	wall_render_struct_starter(data, param);
	raydirs_xy_checker(data, param);
	wall_render_hit_loop(data, param);
	data_start_points_wallx(data, param);
	cardinal_points_wall(data, param, walls);
	tex_x_start(data, param);
	buffer_floor_filler(data, param);
	buffer_wall_filler(data, param, walls);
	buffer_ceiling_filler(data, param);
}

void	wall_render(t_playa *param, t_walls *walls)
{
	t_wall_render_struct	data;

	data.x = 0;
	while (data.x < param->window_width)
	{
		wall_render_loop_core(&data, param, walls);
		param->zbuffer[data.x] = data.perp_wall_dist;
		data.x++;
	}
}
