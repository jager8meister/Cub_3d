/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcin_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 20:49:09 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/11 17:26:16 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parcer.h"

int	raw_map_filler(char **raw_map_data, char *line, int i)
{
	int	j;

	j = 0;
	while (line[j] != '\0')
	{
		raw_map_data[i][j] = line[j];
		j++;
	}
	return (j);
}

void	filler(int fd, char **raw_map_data, t_all_raw_map_info *data)
{
	char	*line;
	int		i;
	int		j;

	line = NULL;
	i = 0;
	j = 0;
	while (get_next_line(fd, &line) != 0)
	{
		j = raw_map_filler(raw_map_data, line, i);
		emptyness_filler(raw_map_data, data, i, &j);
		i++;
		free(line);
	}
	if (line != NULL)
	{
		j = raw_map_filler(raw_map_data, line, i);
		emptyness_filler(raw_map_data, data, i, &j);
		i++;
		free(line);
	}
}

int	screen_check_func(char *str)
{
	char	*screen;

	screen = "R ";
	return (is_substr_in_str(str, screen));
}

int	no_path_check_func(char *str)
{
	char	*no_path;

	no_path = "NO ";
	return (is_substr_in_str(str, no_path));
}

int	so_path_check_func(char *str)
{
	char	*so_path;

	so_path = "SO ";
	return (is_substr_in_str(str, so_path));
}
