/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:08:08 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/12 16:44:41 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_for_main.h"

void	player_win_adding(t_playa *param)
{
	param->win_ptr = mlx_new_window(param->mlx_ptr,
			param->window_width, param->window_height, "Cub3D");
}

int	playa_flags(int key, t_playa *param)
{
	if (key == 13)
		param->move_forward = 1;
	if (key == 1)
		param->move_back = 1;
	if (key == 0)
		param->move_right = 1;
	if (key == 2)
		param->move_left = 1;
	if (key == 124)
		param->rotate_to_the_right = 1;
	if (key == 123)
		param->rotate_to_the_left = 1;
	if (key == 53)
		param->escape = 1;
	return (1);
}

int	playa_flags_release(int key, t_playa *param)
{
	if (key == 13)
		param->move_forward = 0;
	if (key == 1)
		param->move_back = 0;
	if (key == 0)
		param->move_right = 0;
	if (key == 2)
		param->move_left = 0;
	if (key == 124)
		param->rotate_to_the_right = 0;
	if (key == 123)
		param->rotate_to_the_left = 0;
	if (key == 53)
		param->escape = 0;
	return (1);
}

int	draw_frame(t_playa *param)
{
	t_walls		walls;
	t_texture	sprite_texture;

	key_handler(param);
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	draw_image(&walls, &sprite_texture, &param->img, param);
	mlx_put_image_to_window(param->mlx_ptr,
		param->win_ptr, param->img.img, 0, 0);
	mlx_do_sync(param->mlx_ptr);
	free(walls.wall_e.texture_image.data);
	free(walls.wall_n.texture_image.data);
	free(walls.wall_s.texture_image.data);
	free(walls.wall_w.texture_image.data);
	free(sprite_texture.texture_image.data);
	return (1);
}

void	mainik_mlx_hooks(t_playa *playerok)
{
	playerok->move_forward = 0;
	playerok->move_left = 0;
	playerok->move_right = 0;
	playerok->move_back = 0;
	mlx_hook(playerok->win_ptr, 2, 1L << 0, playa_flags, playerok);
	mlx_hook(playerok->win_ptr, 3, 1L << 0, playa_flags_release, playerok);
	mlx_hook(playerok->win_ptr, 17, 1L << 17,
		event_destroy_window, playerok);
	mlx_loop_hook(playerok->mlx_ptr, draw_frame, playerok);
	mlx_loop(playerok->mlx_ptr);
}
