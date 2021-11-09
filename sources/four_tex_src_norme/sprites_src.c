/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_src.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:03:53 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/13 18:39:35 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../textures.h"

void	sort_sprites_data_swap(t_sort_sprites_struct *data,
double *dist, int *order)
{
	data->tmp = order[data->i];
	order[data->i] = order[data->j];
	order[data->j] = data->tmp;
	data->tmp_d = dist[data->i];
	dist[data->i] = dist[data->j];
	dist[data->j] = data->tmp_d;
	data->was_exit = 1;
}

void	sort_sprites(int *order, double *dist, int amount)
{
	t_sort_sprites_struct	data;

	data.tmp = 0;
	data.tmp_d = 0;
	data.i = 0;
	while (data.i <= (amount - 1))
	{
		data.j = data.i + 1;
		data.was_exit = 0;
		while (data.j < amount)
		{
			if (dist[data.i] < dist[data.j])
			{
				sort_sprites_data_swap(&data, dist, order);
				break ;
			}
			data.j++;
		}
		if (!data.was_exit)
			data.i++;
	}
}

void	sprites_render_start_data(t_sprites_render_struct *data,
t_playa *param)
{
	data->sprite_x
		= param->sprite[param->sprite_order[data->sprite_num]].x
		- param->pos_x + 0.5;
	data->sprite_y
		= param->sprite[param->sprite_order[data->sprite_num]].y
		- param->pos_y + 0.5;
	data->inv_det
		= 1.0 / (param->plane_x * param->dir_y
			- param->dir_x * param->plane_y);
	data->transform_x = data->inv_det
		* (param->dir_y * data->sprite_x - param->dir_x * data->sprite_y);
	data->transform_y = data->inv_det
		* (-param->plane_y * data->sprite_x
			+ param->plane_x * data->sprite_y);
	data->sprite_screen_x = (int)((param->window_width / 2)
			* (1 + data->transform_x / data->transform_y));
	data->u_div = 1;
	data->v_div = 1;
	data->v_move = 0.0;
	data->v_move_screen = (int)(data->v_move / data->transform_y);
	data->sprite_height = abs((int)(param->window_height
				/ (data->transform_y))) / data->v_div;
	data->draw_start_y = -data->sprite_height / 2
		+ param->window_height / 2 + data->v_move_screen;
}

void	sprites_render_draw_starts(t_sprites_render_struct *data,
t_playa *param)
{
	if (data->draw_start_y < 0)
		data->draw_start_y = 0;
	data->draw_end_y
		= data->sprite_height / 2
		+ param->window_height / 2 + data->v_move_screen;
	if (data->draw_end_y >= param->window_height)
		data->draw_end_y = param->window_height - 1;
	data->sprite_width = abs((int)(param->window_height
				/ (data->transform_y))) / data->u_div;
	data->draw_start_x = -data->sprite_width / 2
		+ data->sprite_screen_x;
	if (data->draw_start_x < 0)
		data->draw_start_x = 0;
	data->draw_end_x = data->sprite_width / 2 + data->sprite_screen_x;
	if (data->draw_end_x >= param->window_width)
		data->draw_end_x = param->window_width - 1;
}
