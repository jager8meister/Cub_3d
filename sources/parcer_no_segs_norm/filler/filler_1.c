/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:40:50 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/20 17:06:59 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parcer.h"

int	get_size(char *str, int start)
{
	int	rtn;
	int	length;

	rtn = 0;
	length = 0;
	if (str[start] == '0')
	{
		leave("Error\n0 in the begining of digit.");
	}
	while (ft_isdigit(str[start]))
	{
		length += 1;
		rtn = (rtn * 10) + (str[start++] - '0');
	}
	if (length > 5)
		rtn = 5120;
	return (rtn);
}

int	check_line_format_res(char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	if (!str || str[i] != 'R' || str[i + 1] != ' ')
		return (0);
	i = i + 1;
	while (is_space(str[i]))
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	if (!is_space(str[i]))
		return (0);
	while (is_space(str[i]))
		i++;
	while (ft_isdigit(str[i]))
		i++;
	while (is_space(str[i]))
		i++;
	if (!is_space(str[i]) && str[i] != '\0')
		return (0);
	return (1);
}

static void	resolution_filler(t_window *win_infos, int www, int hhh)
{
	if (win_infos->width > www)
		win_infos->width = www;
	if (win_infos->height > hhh)
		win_infos->height = hhh;
}

int	window_size_from_string(char *line, t_window *win_infos)
{
	int	i;
	int	www;
	int	hhh;

	if (!check_line_format_res(line))
		leave(ft_strjoin("Error\nWin Line format : ", line));
	i = 0;
	while (is_space(line[i]))
		i++;
	i += 1;
	while (is_space(line[i]))
		i++;
	win_infos->width = get_size(line, i);
	while (ft_isdigit(line[i]))
		i++;
	while (is_space(line[i]))
		i++;
	win_infos->height = get_size(line, i);
	mlx_get_screen_size(&www, &hhh);
	resolution_filler(win_infos, www, hhh);
	if ((win_infos->height < 70) || (win_infos->width < 70))
		leave("Error\nToo low values of resolution");
	free(line);
	return (1);
}

void	res_filler(t_all_raw_map_info *data)
{
	int	i;

	i = 0;
	while ((unsigned int)i < data->rows)
	{
		if ((is_substr_in_str(data->raw_map_data[i], "R ") == 1))
		{
			window_size_from_string(data->raw_map_data[i], &data->screen_size);
			break ;
		}
		else
			i++;
	}
}
