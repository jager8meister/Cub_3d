#include "header_for_main.h"
// #include "../../mlx/mlx_g_s_s.h"
// #include "../../mlx/mlx.h"

void	image_drawer(t_playa *param)
{
	t_walls		walls;
	t_texture	sprite_texture;
	t_data		img;

	data_starter(param, &walls, &sprite_texture);
	img.img = mlx_new_image(param->mlx_ptr,
			param->window_width, param->window_height);
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length,
			&img.endian);
	wall_render(param, &walls);
	draw_buffer(param, &img);
	draw_image(&walls, &sprite_texture, &img, param);
	take_screenshot(&img, param);
}

void	game_start(t_playa *param)
{
	player_win_adding(param);
	mainik_mlx_hooks(param);
}

void	map_freesher(t_map_data *map)
{
	int	i;

	i = map->map.rows - 1;
	while (i >= 0)
	{
		free(map->map.data[i]);
		i--;
	}
	free(map->map.data);
}

void	map_freesher_int(t_map_to_draw *map)
{
	int	i;

	i = map->rows - 1;
	while (i >= 0)
	{
		free(map->integer_map[i]);
		i--;
	}
	free(map->integer_map);
}
