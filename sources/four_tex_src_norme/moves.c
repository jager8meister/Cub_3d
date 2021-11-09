/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:00:50 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/11 15:18:56 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../textures.h"

void	move_forward(t_playa *param, double move_speed)
{
	if (param->map->data[(int)(param->pos_x
			+ (param->dir_x * 0.5))][(int)(param->pos_y)] == 0)
		param->pos_x += param->dir_x * move_speed * 0.5;
	if (param->map->data[(int)(param->pos_x)][(int)(param->pos_y
	+ param->dir_y * 0.5)] == 0)
		param->pos_y += param->dir_y * move_speed * 0.5;
}

void	move_backward(t_playa *param, double move_speed)
{
	if (param->map->data[(int)(param->pos_x
			- (param->dir_x * 0.5))][(int)(param->pos_y)] == 0)
		param->pos_x -= param->dir_x * move_speed * 0.5;
	if (param->map->data[(int)(param->pos_x)][(int)(param->pos_y
	- (param->dir_y * 0.5))] == 0)
		param->pos_y -= param->dir_y * move_speed * 0.5;
}

void	move_to_the_right(t_playa *param, double move_speed)
{
	double	left_dir_x;
	double	left_dir_y;

	left_dir_x = param->dir_x * cos(-(M_PI / 2))
		- param->dir_y * sin(-(M_PI / 2));
	left_dir_y = param->dir_x * sin(-(M_PI / 2))
		+ param->dir_y * cos(-(M_PI / 2));
	if (param->map->data[(int)(param->pos_x
			- (left_dir_x * 0.5))][(int)(param->pos_y)] == 0)
		param->pos_x -= left_dir_x * move_speed * 0.5;
	if (param->map->data[(int)(param->pos_x)][(int)(param->pos_y
		- (left_dir_y * 0.5))] == 0)
		param->pos_y -= left_dir_y * move_speed * 0.5;
}

void	move_to_the_left(t_playa *param, double move_speed)
{
	double	left_dir_x;
	double	left_dir_y;

	left_dir_x = param->dir_x * cos((M_PI / 2))
		- param->dir_y * sin((M_PI / 2));
	left_dir_y = param->dir_x * sin((M_PI / 2))
		+ param->dir_y * cos((M_PI / 2));
	if (param->map->data[(int)(param->pos_x
			- (left_dir_x * 0.5))][(int)(param->pos_y)] == 0)
		param->pos_x -= left_dir_x * move_speed * 0.5;
	if (param->map->data[(int)(param->pos_x)][(int)(param->pos_y
	- (left_dir_y * 0.5))] == 0)
		param->pos_y -= left_dir_y * move_speed * 0.5;
}
