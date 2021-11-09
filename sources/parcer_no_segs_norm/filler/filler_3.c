/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:45:22 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/13 18:56:28 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parcer.h"

void	f_filler(t_all_raw_map_info *data)
{
	int	i;

	i = 0;
	while ((unsigned int)i < data->rows)
	{
		if (is_substr_in_str(data->raw_map_data[i], "F ") == 1)
		{
			color_from_string(data->raw_map_data[i], 'F',
				char_index(data->raw_map_data[i], 'F'), data);
			break ;
		}
		else
			i++;
	}
}

void	c_filler(t_all_raw_map_info *data)
{
	int	i;

	i = 0;
	while ((unsigned int)i < data->rows)
	{
		if (is_substr_in_str(data->raw_map_data[i], "C ") == 1)
		{
			color_from_string(data->raw_map_data[i], 'C',
				char_index(data->raw_map_data[i], 'C'), data);
			break ;
		}
		else
			i++;
	}
}

int	get_num_color(char *line, int *i)
{
	int	color;
	int	length;

	color = ft_atoi(&line[*i]);
	if (line[*i] == '0' && color != 0)
		leave("Error\n0 in color parameter.");
	if (color < 0 || color > 255)
		leave("Error\nInvalid rgb parameter");
	length = 0;
	while (ft_isdigit(line[*i]))
	{
		*i += 1;
		length++;
	}
	*i += 1;
	if (length >= 4)
		leave("Error\nInvalid rgb parameter");
	if (length == 0)
		leave("Error\nEmpty parameter");
	return (color);
}

int	get_color_from_rgb(int r, int g, int b)
{
	int	rgb;

	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 8) + b;
	return (rgb);
}
