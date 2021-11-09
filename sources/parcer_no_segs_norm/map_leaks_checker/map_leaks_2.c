/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_leaks_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:37:40 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/11 17:01:33 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parcer.h"

void	matrix_freesher(t_map_data *map, char **matrix)
{
	int	i;

	i = 0;
	while (i < map->map.rows)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	map_leaks_check_wid_loop(t_map_data *map, char **matrix, int i)
{
	int	j;

	j = 0;
	while (j < map->map.width)
	{
		if (matrix[i][j] != '3')
			map->map.data[i][j] = '1';
		j++;
	}
}
