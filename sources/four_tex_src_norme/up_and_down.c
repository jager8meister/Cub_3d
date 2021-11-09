/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_and_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:17:27 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/11 19:31:49 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../textures.h"

void	buffer_floor_filler(t_wall_render_struct *data,
t_playa *param)
{
	data->y = data->draw_end;
	while (data->y < param->window_height)
	{
		param->buffer[data->y][data->x] = param->color_floor;
		data->y++;
	}
}

void	buffer_ceiling_filler(t_wall_render_struct *data,
t_playa *param)
{
	data->y = 0;
	while (data->y < data->draw_start)
	{
		param->buffer[data->y][data->x] = param->color_ceiling;
		data->y++;
	}
}
