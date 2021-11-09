/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_leaks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:35:49 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/20 18:09:16 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parcer.h"

int	angle_1(char **matrix, t_map_char xxx, int *i, int *j)
{
	*i = 0;
	*j = 0;
	while (*j < xxx.width)
	{
		if (matrix[*i][*j] == '3')
			return (0);
		*j += 1;
	}
	*j -= 1;
	while (*i < xxx.rows)
	{
		if (matrix[*i][*j] == '3')
			return (0);
		*i += 1;
	}
	*i -= 1;
	return (1);
}

int	angle_2(char **matrix, int *i, int *j)
{
	while (*j >= 0)
	{
		if (matrix[*i][*j] == '3')
			return (0);
		*j -= 1;
	}
	while (*i >= 0)
	{
		if (matrix[*i][*j] == '3')
			return (0);
		*i -= 1;
	}
	return (1);
}

int	leak_source(char **matrix, t_map_char xxx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (angle_1(matrix, xxx, &i, &j) == 0)
		return (0);
	if (angle_2(matrix, &i, &j) == 0)
		return (0);
	return (1);
}

static void	zero_edge_check(t_map_data *map)
{
	int		i;

	i = 0;
	while (i < map->map.rows)
	{
		if (map->map.data[i][0] == '0')
			leave("Error\n0 near edge.");
		if (map->map.data[i][0] == '2')
			leave("Error\nSprite near edge.");
		i++;
	}
}

int	map_leaks_check(t_map_data *map)
{
	char	**matrix;
	int		player_x;
	int		player_y;
	int		i;

	matrix = matrix_copy(map->map);
	player_finder(map->map, &player_x, &player_y);
	matrix[player_x][player_y] = '0';
	cross_fillin(matrix, player_x, player_y, map->map);
	i = 0;
	while (i < map->map.rows)
	{
		map_leaks_check_wid_loop(map, matrix, i);
		i++;
	}
	zero_edge_check(map);
	if (!leak_source(matrix, map->map))
		leave("Error\nmap is invalid ");
	matrix_freesher(map, matrix);
	return (1);
}
