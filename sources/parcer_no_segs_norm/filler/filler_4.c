/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:46:35 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/19 20:41:00 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parcer.h"

int	get_size_path(char *str, int start)
{
	int	rtn;

	rtn = 0;
	while (ft_isprint(str[start + rtn]) && str[start + rtn - 1] != 'm')
		rtn++;
	return (rtn);
}

int	check_line_format_path(char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] != 'N' && str[i] != 'S' && str[i] != 'W'
		&& str[i] != 'E')
		return (0);
	i++;
	if (str[i] != 'O' && str[i] != 'E' && str[i] != 'A'
		&& !is_space(str[i]))
		return (0);
	i++;
	while (is_space(str[i]))
		i++;
	if (str[i] != '.' && str[i + 1] != '/')
		return (0);
	while (ft_isprint(str[i]) && !is_space(str[i]) && str[i] != '\0')
		i++;
	if (!is_space(str[i]) && str[i] != '\0')
		return (0);
	while (is_space(str[i]))
		i++;
	return (str[i] == '\0');
}

static void	i_value(int f_c_pos, char *line, int *i)
{
	if (line[f_c_pos + 1] == ' ')
		*i = f_c_pos + 2;
	else
		*i = f_c_pos + 3;
}

// static void check_line_before_path(char *line, )
// {

// }

int	path_from_string(char *line,
t_first_chars *fc, int f_c_pos, t_all_raw_map_info *win_infos)
{
	char	*path;
	int		i;

	i_value(f_c_pos, line, &i);
	while (is_space(line[i]))
		i++;
	path = ft_substr(line, i, get_size_path(line, i));
	if (line[ft_strlen(line) - 1] != 'm')
		leave(ft_strjoin("Error\nPath doesn't end with .xpm : ", line));
	if (!(path) || !file_exists(path))
		leave(ft_strjoin("Error\nInvalid Path : ", line));
	if (fc->c0 == 'N' && fc->c1 == 'O')
		win_infos->no_path = path;
	else if (fc->c0 == 'S' && fc->c1 == 'O')
		win_infos->so_path = path;
	else if (fc->c0 == 'W' && fc->c1 == 'E')
		win_infos->we_path = path;
	else if (fc->c0 == 'E' && fc->c1 == 'A')
		win_infos->ea_path = path;
	else if (fc->c0 == 'S' && fc->c1 == ' ')
		win_infos->s_path = path;
	free(line);
	return (1);
}

void	no_filler(t_all_raw_map_info *data)
{
	t_first_chars	fc;
	int				i;

	i = 0;
	fc.c0 = 'N';
	fc.c1 = 'O';
	while ((unsigned int)i < data->rows)
	{
		if (is_substr_in_str(data->raw_map_data[i], "NO ") == 1)
		{
			path_from_string(data->raw_map_data[i], &fc,
				char_index(data->raw_map_data[i], 'O'), data);
			break ;
		}
		else
			i++;
	}
}
