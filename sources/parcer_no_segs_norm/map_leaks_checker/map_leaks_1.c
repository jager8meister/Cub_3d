/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_leaks_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:37:39 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/11 17:00:34 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parcer.h"

char	**matrix_copy(t_map_char xxx)
{
	char	**result;
	int		i;
	char	*line;
	int		j;

	result = (char **)malloc(xxx.rows * sizeof(char *));
	i = 0;
	while (i < xxx.rows)
	{
		line = (char *)malloc(xxx.width + 1);
		j = 0;
		while (j < xxx.width)
		{
			line[j] = xxx.data[i][j];
			j++;
		}
		line[j] = '\0';
		result[i] = line;
		i++;
	}
	return (result);
}

void	player_finder(t_map_char xxx, int *i, int *j)
{
	int	exit;

	*i = 0;
	*j = 0;
	exit = 0;
	while (*i < xxx.rows && exit == 0)
	{
		*j = 0;
		while (*j < xxx.width && exit == 0)
		{
			if (xxx.data[*i][*j] == 'N' ||
				xxx.data[*i][*j] == 'S' ||
				xxx.data[*i][*j] == 'E' ||
				xxx.data[*i][*j] == 'W')
			{
				exit = 1;
				break ;
			}
			*j += 1;
		}
		if (exit == 0)
			*i += 1;
	}
}

void	ones_and_thirds_check(char **matrix, int x, int y, t_map_char xxx)
{
	if (matrix[x][y] != '1' && matrix[x][y] != '3')
	{
		matrix[x][y] = '3';
		cross_fillin(matrix, x, y, xxx);
	}
}

void	start_point_check(char **matrix, int x, int y, t_map_char xxx)
{
	if ((x >= 0 && x < xxx.rows) && (y >= 0 && y < xxx.width))
	{
		if (matrix[x][y] == '0')
		{
			matrix[x][y] = '3';
			cross_fillin(matrix, x, y, xxx);
		}
	}
}

void	cross_fillin(char **matrix,
int start_x, int start_y, t_map_char xxx)
{
	int	x;
	int	y;

	x = start_x - 1;
	y = start_y;
	start_point_check(matrix, x, y, xxx);
	while ((x >= (start_x - 1) && (x <= (start_x + 1)))
		&& (x >= 0 && x < xxx.rows) && (y >= 0 && y < xxx.width))
	{
		y = start_y;
		ones_and_thirds_check(matrix, x, y, xxx);
		x++;
	}
	y = start_y - 1;
	x = start_x;
	while ((y >= (start_y - 1) && (y <= (start_y + 1)))
		&& (y >= 0 && y < xxx.width) && (x >= 0 && x < xxx.rows))
	{
		x = start_x;
		ones_and_thirds_check(matrix, x, y, xxx);
		y++;
	}
}
