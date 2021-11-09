/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:38:54 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/11 15:59:16 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parcer.h"

void	so_filler(t_all_raw_map_info *data)
{
	t_first_chars	fc;
	int				i;

	i = 0;
	fc.c0 = 'S';
	fc.c1 = 'O';
	while ((unsigned int)i < data->rows)
	{
		if (is_substr_in_str(data->raw_map_data[i], "SO ") == 1)
		{
			path_from_string(data->raw_map_data[i], &fc,
				char_index(data->raw_map_data[i], 'O'), data);
			break ;
		}
		else
			i++;
	}
}

void	we_filler(t_all_raw_map_info *data)
{
	t_first_chars	fc;
	int				i;

	i = 0;
	fc.c0 = 'W';
	fc.c1 = 'E';
	while ((unsigned int)i < data->rows)
	{
		if (is_substr_in_str(data->raw_map_data[i], "WE ") == 1)
		{
			path_from_string(data->raw_map_data[i], &fc,
				char_index(data->raw_map_data[i], 'E'), data);
			break ;
		}
		else
			i++;
	}
}

void	ea_filler(t_all_raw_map_info *data)
{
	t_first_chars	fc;
	int				i;

	i = 0;
	fc.c0 = 'E';
	fc.c1 = 'A';
	while ((unsigned int)i < data->rows)
	{
		if (is_substr_in_str(data->raw_map_data[i], "EA ") == 1)
		{
			path_from_string(data->raw_map_data[i], &fc,
				char_index(data->raw_map_data[i], 'A'), data);
			break ;
		}
		else
			i++;
	}
}

void	s_filler(t_all_raw_map_info *data)
{
	t_first_chars	fc;
	int				i;

	i = 0;
	fc.c0 = 'S';
	fc.c1 = ' ';
	while ((unsigned int)i < data->rows)
	{
		if (is_substr_in_str(data->raw_map_data[i], "S ") == 1)
		{
			path_from_string(data->raw_map_data[i], &fc,
				char_index(data->raw_map_data[i], 'S'), data);
			break ;
		}
		else
			i++;
	}
}

void	raw_data_fillers(t_all_raw_map_info *data)
{
	res_filler(data);
	f_filler(data);
	c_filler(data);
	no_filler(data);
	so_filler(data);
	we_filler(data);
	ea_filler(data);
	s_filler(data);
}
