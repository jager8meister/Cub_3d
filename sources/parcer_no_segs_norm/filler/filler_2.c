/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:44:29 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/18 17:41:32 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parcer.h"

static void	digit_parameter_finder(char *line, int *i)
{
	while (is_space(line[*i]) || line[*i] == ',')
		*i += 1;
}

static void	color_finder(char *line, int *i, int *color)
{
	digit_parameter_finder(line, i);
	*color = get_num_color(line, i);
}

static void	aftermath_check(char *line, int *i)
{
	while (line[*i] != '\0')
	{
		if (!is_space(line[*i]))
			leave("Error\nTrash in rgb string");
		*i += 1;
	}
}

static void	rgb_param_valid(char *str, int first_char_pos)
{
	int	i;
	int	amount_of_params;

	i = first_char_pos + 1;
	amount_of_params = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
		{
			amount_of_params++;
			while (ft_isdigit(str[i]))
				i++;
			while (str[i] == ' ')
				i++;
			if (str[i] != ',' && amount_of_params < 3)
				leave("Error\nNo comma between rgb parameters.");
		}
		i++;
	}
}

int	color_from_string(char *line, int c,
	int first_char_pos, t_all_raw_map_info *win_infos)
{
	int	rgb;
	int	r;
	int	g;
	int	b;
	int	i;

	rgb = 0;
	r = 0;
	g = 0;
	b = 0;
	if (!check_line_format_rgb(line, c, first_char_pos))
		return (0);
	i = first_char_pos + 1;
	while (is_space(line[i]))
		i++;
	r = get_num_color(line, &i);
	color_finder(line, &i, &g);
	color_finder(line, &i, &b);
	rgb = get_color_from_rgb(r, g, b);
	aftermath_check(line, &i);
	color_thrower(win_infos, rgb, c);
	rgb_param_valid(line, first_char_pos);
	free(line);
	return (1);
}
