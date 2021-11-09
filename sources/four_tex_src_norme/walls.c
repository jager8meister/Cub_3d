/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:09:57 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/11 15:38:27 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../textures.h"

void	wall_render_struct_starter(t_wall_render_struct *data,
t_playa *param)
{
	data->camera_x = 2 * data->x / (double)param->window_width - 1;
	data->ray_dir_x = param->dir_x + param->plane_x * data->camera_x;
	data->ray_dir_y = param->dir_y + param->plane_y * data->camera_x;
	data->map_x = (int)(param->pos_x);
	data->map_y = (int)(param->pos_y);
	if (data->ray_dir_y == 0)
		data->delta_dist_x = 0;
	else
	{
		if (data->ray_dir_x == 0)
			data->delta_dist_x = 1;
		else
			data->delta_dist_x = fabs(1 / data->ray_dir_x);
	}
	if (data->ray_dir_x == 0)
		data->delta_dist_y = 0;
	else
	{
		if (data->ray_dir_y == 0)
			data->delta_dist_y = 1;
		else
			data->delta_dist_y = fabs(1 / data->ray_dir_y);
	}
	data->hit = 0;
}

void	wall_render_hit_loop(t_wall_render_struct *data, t_playa *param)
{
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (param->map->data[data->map_x][data->map_y] > 0)
			data->hit = 1;
	}
}

void	buffer_wall_sides_finder(t_wall_render_struct *data,
t_playa *param, t_walls *walls)
{
	if (data->side == 0 && (data->map_x < param->pos_x))
		data->color
			= walls->wall_n.texture_image.data[walls->wall_n.img_height
			* data->texy + data->texx];
	if (data->side == 0 && (data->map_x >= param->pos_x))
		data->color
			= walls->wall_s.texture_image.data[walls->wall_s.img_height
			* data->texy + data->texx];
	if (data->side == 1 && (data->map_y < param->pos_y))
		data->color
			= walls->wall_w.texture_image.data[walls->wall_w.img_height
			* data->texy + data->texx];
	if (data->side == 1 && (data->map_y >= param->pos_y))
		data->color
			= walls->wall_e.texture_image.data[walls->wall_e.img_height
			* data->texy + data->texx];
}

void	buffer_wall_filler(t_wall_render_struct *data,
t_playa *param, t_walls *walls)
{
	data->y = data->draw_start;
	while (data->y < data->draw_end)
	{
		data->texy = (int)data->texpos & (data->tex_height - 1);
		data->texpos += data->step;
		data->color = walls->wall_w.texture_image.data[walls->wall_w.img_height
			* data->texy + data->texx];
		buffer_wall_sides_finder(data, param, walls);
		param->buffer[data->y][data->x] = data->color;
		data->y++;
	}
}

void	cardinal_points_wall(t_wall_render_struct *data,
t_playa *param, t_walls *walls)
{
	if (data->side == 0 && (data->map_x < param->pos_x))
	{
		data->tex_width = walls->wall_n.img_width;
		data->tex_height = walls->wall_n.img_height;
	}
	if (data->side == 0 && (data->map_x >= param->pos_x))
	{
		data->tex_width = walls->wall_s.img_width;
		data->tex_height = walls->wall_s.img_height;
	}
	if (data->side == 1 && (data->map_y < param->pos_y))
	{
		data->tex_width = walls->wall_w.img_width;
		data->tex_height = walls->wall_w.img_height;
	}
	if (data->side == 1 && (data->map_y >= param->pos_y))
	{
		data->tex_width = walls->wall_e.img_width;
		data->tex_height = walls->wall_e.img_height;
	}
}
