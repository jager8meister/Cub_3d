/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:01:55 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/11 15:20:35 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../textures.h"

void	rotate_to_the_right(t_playa *param, double rotation_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = param->dir_x;
	param->dir_x = param->dir_x * cos(-rotation_speed * 0.5)
		- param->dir_y * sin(-rotation_speed * 0.5);
	param->dir_y = old_dir_x * sin(-rotation_speed * 0.5)
		+ param->dir_y * cos(-rotation_speed * 0.5);
	old_plane_x = param->plane_x;
	param->plane_x = param->plane_x * cos(-rotation_speed * 0.5)
		- param->plane_y * sin(-rotation_speed * 0.5);
	param->plane_y = old_plane_x * sin(-rotation_speed * 0.5)
		+ param->plane_y * cos(-rotation_speed * 0.5);
}

void	rotate_to_the_left(t_playa *param, double rotation_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = param->dir_x;
	param->dir_x = param->dir_x * cos(rotation_speed * 0.5)
		- param->dir_y * sin(rotation_speed * 0.5);
	param->dir_y = old_dir_x * sin(rotation_speed * 0.5)
		+ param->dir_y * cos(rotation_speed * 0.5);
	old_plane_x = param->plane_x;
	param->plane_x = param->plane_x * cos(rotation_speed * 0.5)
		- param->plane_y * sin(rotation_speed * 0.5);
	param->plane_y = old_plane_x * sin(rotation_speed * 0.5)
		+ param->plane_y * cos(rotation_speed * 0.5);
}
