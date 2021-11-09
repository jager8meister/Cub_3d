/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 20:55:52 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/20 17:43:38 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parcer.h"

void	t_map_data_filler(t_all_raw_map_info *data, t_map_data *map)
{
	map->ceilling = data->ceiling_color;
	map->floor = data->floor_color;
	map->textures.ea_path = data->ea_path;
	map->textures.no_path = data->no_path;
	map->textures.s_path = data->s_path;
	map->textures.so_path = data->so_path;
	map->textures.we_path = data->we_path;
	map->window = data->screen_size;
	map->map = data->map;
}

int	emptyness_checker(t_all_raw_map_info *data, int i, int j)
{
	return (((data->map.data[i][j] == ' ')
		&& (((((i - 1) >= 0) && (data->map.data[i - 1][j] == '0'))
			|| (((i + 1) < data->map.rows) && (data->map.data[i + 1][j] == '0'))
		|| (((j - 1) >= 0) && (data->map.data[i][j - 1] == '0'))
			|| (((j + 1) < data->map.width)
			&& (data->map.data[i][j + 1] == '0'))))));
}

int	spaces_check(t_all_raw_map_info *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.rows)
	{
		j = 0;
		while (j < data->map.width)
		{
			if (emptyness_checker(data, i, j))
				leave("Error\n0 near emptyness ");
			if (sprite_emptyness_checker(data, i, j))
				leave("Error\nSprite near emptyness ");
			j++;
		}
		i++;
	}
	return (1);
}

void	map_staff(t_all_raw_map_info *data, t_map_data *map)
{
	map_starting_point(data);
	empty_lines_in_map_checker(data);
	nonmapy_symbols_in_map(data);
	player_amount(data);
	map_filler(data);
	spaces_check(data);
	t_map_data_filler(data, map);
	free(data->raw_map_data);
}

int	parcer(char *path, t_map_data *map)
{
	t_all_raw_map_info	data;
	int					fd;
	int					dublicates;

	fd = open(path, O_RDONLY);
	all_raw_map_info_starter(&data);
	size_of_2d_arr(fd, &data);
	close(fd);
	all_raw_map_info_start_filler(&data);
	fd = open(path, O_RDONLY);
	filler(fd, data.raw_map_data, &data);
	close(fd);
	dublicates = double_values(&data);
	if (dublicates == 1)
		leave("Error\nDUPLICATES in cub file.");
	raw_data_fillers(&data);
	trash_checker(&data);
	map_staff(&data, map);
	return (0);
}
