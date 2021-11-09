/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_map_creator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:35:23 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/11 16:58:40 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parcer.h"

void	char_unit_to_int(t_map_char xxx,
t_map_to_draw *result, int i, int j)
{
	if (xxx.data[i][j] == 'N')
		result->integer_map[i][j] = 3;
	else if (xxx.data[i][j] == 'E')
		result->integer_map[i][j] = 4;
	else if (xxx.data[i][j] == 'S')
		result->integer_map[i][j] = 5;
	else if (xxx.data[i][j] == 'W')
		result->integer_map[i][j] = 6;
	else
		result->integer_map[i][j] = (int)(xxx.data[i][j] - '0');
}

void	transitter(t_map_char xxx, t_map_to_draw *result)
{
	int		i;
	int		j;

	result->integer_map = (int **)malloc(xxx.rows * sizeof(int *));
	result->rows = xxx.rows;
	result->width = xxx.width;
	i = 0;
	while (i < xxx.rows)
	{
		result->integer_map[i] = (int *)malloc(xxx.width * sizeof(int));
		j = 0;
		while (j < xxx.width)
		{
			char_unit_to_int(xxx, result, i, j);
			j++;
		}
		i++;
	}
}
