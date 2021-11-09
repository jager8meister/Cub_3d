/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:33:58 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/11 17:16:58 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parcer.h"

int	player_amount(t_all_raw_map_info *data)
{
	int	index;
	int	j;
	int	player;

	index = data->map_start;
	j = 0;
	player = 0;
	while ((unsigned int)index < data->rows)
	{
		j = 0;
		while ((unsigned int)j < data->length)
		{
			if (player_letter(data, index, j))
			{
				if (++player >= 2)
					leave(ft_strjoin("Error\nSeveral players on the map : ",
							data->raw_map_data[index]));
			}
			j++;
		}
		index++;
	}
	if (player == 0)
		leave("Error\nNo players on the map");
	return (1);
}

void	map_data_creator(t_all_raw_map_info *data)
{
	int	index;

	index = 0;
	data->map.data = (char **)malloc(sizeof(char *)
			* (data->rows - data->map_start));
	while ((unsigned int)index < (data->rows - data->map_start))
	{
		data->map.data[index]
			= (char *)malloc(sizeof(char)
				* (data->length + 1));
		index++;
	}
}

void	map_data_empty_filler(t_all_raw_map_info *data)
{
	int	i;
	int	j;
	int	index;

	index = 0;
	i = data->map_start;
	while ((unsigned int)i < data->rows)
	{
		j = 0;
		while ((unsigned int)j < data->length + 1)
		{
			data->map.data[index][j] = '\0';
			j++;
		}
		index++;
		i++;
	}
}

void	map_data_raw_filler(t_all_raw_map_info *data)
{
	int	i;
	int	j;
	int	index;

	index = 0;
	i = data->map_start;
	while ((unsigned int)i < data->rows)
	{
		j = 0;
		while ((unsigned int)j < data->length)
		{
			data->map.data[index][j] = data->raw_map_data[i][j];
			if (data->raw_map_data[i][j] == '\0')
				data->map.data[index][j] = ' ';
			j++;
		}
		free(data->raw_map_data[i]);
		index++;
		i++;
	}
	data->map.rows = index;
	data->map.width = data->length;
}

void	map_filler(t_all_raw_map_info *data)
{
	map_data_creator(data);
	map_data_empty_filler(data);
	map_data_raw_filler(data);
}
