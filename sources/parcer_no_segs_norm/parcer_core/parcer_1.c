/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:31:49 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/11 17:09:30 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parcer.h"

void	all_raw_map_info_starter(t_all_raw_map_info *data)
{
	data->length = 0;
	data->rows = 0;
}

void	all_raw_map_info_start_filler(t_all_raw_map_info *data)
{
	int	i;

	data->raw_map_data = (char **)malloc(sizeof(char *) * data->rows);
	i = 0;
	while ((unsigned int)i < data->rows)
	{
		data->raw_map_data[i] = (char *)malloc(sizeof(char) * data->length + 1);
		i++;
	}
}

int	str_trash_checker(char *str)
{
	int	i;

	i = 0;
	while ((size_t)i < ft_strlen(str))
	{
		if (str[i] != ' ' && str[i] != '\0')
			return (1);
		i++;
	}
	return (0);
}

int	index_after_all_info(t_all_raw_map_info *data)
{
	int	map_index;

	map_index = 0;
	if (data->r_line_index >= map_index)
		map_index = data->r_line_index + 1;
	if (data->no_line_index >= map_index)
		map_index = data->no_line_index + 1;
	if (data->so_line_index >= map_index)
		map_index = data->so_line_index + 1;
	if (data->we_line_index >= map_index)
		map_index = data->we_line_index + 1;
	if (data->ea_line_index >= map_index)
		map_index = data->ea_line_index + 1;
	if (data->s_line_index >= map_index)
		map_index = data->s_line_index + 1;
	if (data->f_line_index >= map_index)
		map_index = data->f_line_index + 1;
	if (data->c_line_index >= map_index)
		map_index = data->c_line_index + 1;
	return (map_index);
}

int	non_important_index_check(t_all_raw_map_info *data, int i)
{
	if (i != data->r_line_index
		&& i != data->no_line_index
		&& i != data->so_line_index
		&& i != data->we_line_index
		&& i != data->ea_line_index
		&& i != data->s_line_index
		&& i != data->f_line_index
		&& i != data->c_line_index)
		return (1);
	return (0);
}
