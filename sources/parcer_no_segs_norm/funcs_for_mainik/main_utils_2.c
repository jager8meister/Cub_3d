/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:22:17 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/11 16:02:37 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_for_main.h"

void	amount_of_sprites(t_playa *param)
{
	int	i;
	int	j;

	i = 0;
	param->num_sprites = 0;
	while (i < param->map->rows)
	{
		j = 0;
		while (j < param->map->width)
		{
			if (param->map->data[i][j] == 2)
				param->num_sprites += 1;
			j++;
		}
		i++;
	}
}

void	sprites_array_loop(t_playa *param)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	while (i < param->map->rows)
	{
		j = 0;
		while (j < param->map->width)
		{
			if (param->map->data[i][j] == 2)
			{
				param->sprite[index].x = i;
				param->sprite[index].y = j;
				index++;
				param->map->data[i][j] = 0;
			}
			j++;
		}
		i++;
	}
}

void	sprites_array(t_playa *param)
{
	param->sprite_order = (int *)malloc(sizeof(int)
			* param->num_sprites);
	param->sprite_distance = (double *)malloc(sizeof(double)
			* param->num_sprites);
	param->sprite = (t_sprite *)malloc(sizeof(t_sprite)
			* param->num_sprites);
	sprites_array_loop(param);
}

void	player_buffer_creation(t_playa *param)
{
	int	i;

	param->buffer = (unsigned int **)malloc(sizeof(unsigned int *)
			* param->window_height);
	i = 0;
	while (i < param->window_height)
	{
		param->buffer[i] = (unsigned int *)malloc(sizeof(unsigned int)
				* param->window_width);
		i++;
	}
}

void	player_finder_on_integer_map(t_playa *param)
{
	int	i;
	int	j;

	i = 0;
	while (i < param->map->rows)
	{
		j = 0;
		while (j < param->map->width)
		{
			if (param->map->data[i][j] > 2)
			{
				param->pos_x = (double)i + 0.5;
				param->pos_y = (double)j + 0.5;
				break ;
			}
			j++;
		}
		i++;
	}
}
