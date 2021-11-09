/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_src_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:07:46 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/11 15:23:02 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../textures.h"

void	sprites_dr_texy_and_color(t_sprites_render_struct *data,
t_playa *param, t_texture sprite_texture)
{
	data->d = (data->y_pos - data->v_move_screen) * 256
		- param->window_height * 128 + data->sprite_height * 128;
	data->texy = ((data->d * param->texture_height)
			/ data->sprite_height) / 256;
	data->color = sprite_texture.texture_image.data[param->texture_width
		* data->texy + data->texx];
}

void	sprites_drawer(t_sprites_render_struct *data,
t_playa *param, t_texture sprite_texture)
{
	data->line = data->draw_start_x;
	while (data->line < data->draw_end_x)
	{
		data->texx = (int)(256 * (data->line
					- (-data->sprite_width / 2 + data->sprite_screen_x))
				* param->texture_width / data->sprite_width) / 256;
		if (data->transform_y > 0 && data->line > 0
			&& data->line < param->window_width
			&& data->transform_y < param->zbuffer[data->line])
		{
			data->y_pos = data->draw_start_y;
			while (data->y_pos < data->draw_end_y)
			{
				sprites_dr_texy_and_color(data, param, sprite_texture);
				if ((data->color & 0x00FFFFFF) != 0)
					param->buffer[data->y_pos][data->line] = data->color;
				data->y_pos++;
			}
		}
		data->line++;
	}
}

void	sprites_render(t_playa *param, t_texture sprite_texture)
{
	t_sprites_render_struct	data;

	data.sprite_num = 0;
	while (data.sprite_num < param->num_sprites)
	{
		sprites_render_start_data(&data, param);
		sprites_render_draw_starts(&data, param);
		sprites_drawer(&data, param, sprite_texture);
		data.sprite_num++;
	}
}

void	sprite_arr_filler(t_playa *param)
{
	int	i;

	i = 0;
	while (i < param->num_sprites)
	{
		param->sprite_order[i] = i;
		param->sprite_distance[i] = ((param->pos_x - param->sprite[i].x)
				* (param->pos_x - param->sprite[i].x)
				+ (param->pos_y - param->sprite[i].y)
				* (param->pos_y - param->sprite[i].y));
		i++;
	}
}
