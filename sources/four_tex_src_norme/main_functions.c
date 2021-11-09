/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:20:33 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/11 15:16:17 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../textures.h"

void	key_handler(t_playa *param)
{
	double	move_speed;
	double	rotation_speed;

	move_speed = 0.2;
	rotation_speed = 0.1;
	if (param->move_forward == 1)
		move_forward(param, move_speed);
	if (param->move_back == 1)
		move_backward(param, move_speed);
	if (param->move_right == 1)
		move_to_the_right(param, move_speed);
	if (param->move_left == 1)
		move_to_the_left(param, move_speed);
	if (param->rotate_to_the_right == 1)
		rotate_to_the_right(param, rotation_speed);
	if (param->rotate_to_the_left == 1)
		rotate_to_the_left(param, rotation_speed);
	if (param->escape == 1)
	{
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		exit(0);
	}
}

void	data_starter(t_playa *param,
t_walls *walls, t_texture *sprite_texture)
{
	walls_starter(param, walls);
	sprite_texture->texture_path = param->sprite_path;
	texture_starter(sprite_texture, param->mlx_ptr);
}

void	draw_image(t_walls *walls,
t_texture *sprite_texture, t_data *img, t_playa *param)
{
	data_starter(param, walls, sprite_texture);
	wall_render(param, walls);
	sprite_arr_filler(param);
	sort_sprites(param->sprite_order,
		param->sprite_distance, param->num_sprites);
	sprites_render(param, *sprite_texture);
	draw_buffer(param, img);
}

int	deal_key(int key, t_playa *param)
{
	t_walls		walls;
	t_texture	sprite_texture;

	printf("deal key %d %d\n", param->move_forward, param->move_left);
	key_handler(param);
	if (key == 53)
	{
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		exit(0);
	}
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
	return (0);
}
