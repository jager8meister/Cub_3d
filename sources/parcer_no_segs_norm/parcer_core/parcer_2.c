/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:32:44 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/20 17:10:48 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parcer.h"

int	trash_checker(t_all_raw_map_info *data)
{
	int	i;
	int	map_start;

	i = 0;
	map_start = index_after_all_info(data);
	if (map_start == (int)data->rows)
		leave("Error\nNo map.");
	while ((unsigned int)i <= data->rows && i < map_start)
	{
		if (non_important_index_check(data, i) == 1)
		{
			if (str_trash_checker(data->raw_map_data[i]))
			{
				leave(ft_strjoin("Error\nTrash in line ",
						data->raw_map_data[i]));
				return (0);
			}
			free(data->raw_map_data[i]);
		}
		i++;
	}
	return (1);
}

void	map_starting_point(t_all_raw_map_info *data)
{
	int	start;

	start = index_after_all_info(data);
	while ((unsigned int)start < data->rows)
	{
		if (data->raw_map_data[start][0] != '\0')
			break ;
		if (data->raw_map_data[start])
			free(data->raw_map_data[start]);
		start++;
	}
	data->map_start = start;
	if (data->map_start == (int)data->rows)
		leave("Error\nNo map.");
}

int	empty_lines_in_map_checker(t_all_raw_map_info *data)
{
	int	i;

	i = data->map_start;
	while ((unsigned int)i < data->rows)
	{
		if (data->raw_map_data[i][0] == '\0')
			leave("Error\nEmpty line in map.");
		i++;
	}
	return (1);
}

int	player_letter(t_all_raw_map_info *data, int index, int j)
{
	return (data->raw_map_data[index][j] == 'N'
				|| data->raw_map_data[index][j] == 'S'
				|| data->raw_map_data[index][j] == 'E'
				|| data->raw_map_data[index][j] == 'W');
}

int	nonmapy_symbols_in_map(t_all_raw_map_info *data)
{
	int	index;
	int	j;

	index = data->map_start;
	j = 0;
	while ((unsigned int)index < data->rows)
	{
		j = 0;
		while ((unsigned int)j < data->length)
		{
			if (data->raw_map_data[index][j] != ' '
				&& data->raw_map_data[index][j] != '\0'
				&& data->raw_map_data[index][j] != '1'
				&& data->raw_map_data[index][j] != '2'
				&& data->raw_map_data[index][j] != '0'
				&& !player_letter(data, index, j))
			{
				leave(ft_strjoin("Error\nTrash in map : ",
						data->raw_map_data[index]));
			}
			j++;
		}
		index++;
	}
	return (1);
}
