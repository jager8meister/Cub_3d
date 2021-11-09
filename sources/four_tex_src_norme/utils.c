/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:03:06 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/11 15:31:31 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../textures.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_buffer(t_playa *param, t_data *image)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < param->window_height)
	{
		x = 0;
		while (x < param->window_width)
		{
			my_mlx_pixel_put(image, x, y, param->buffer[y][x]);
			x++;
		}
		y++;
	}
}

int	event_destroy_window(void)
{
	exit(0);
}
