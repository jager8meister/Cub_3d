/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcin_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 20:48:31 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/20 17:44:44 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parcer.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static void	lil_check(t_all_raw_map_info *data, t_size_of_2d_arr prog_data)
{
	if (data->rows <= 8)
		leave("Error\nNot enough information ");
	if (prog_data.ll_num != (long long)data->rows)
		leave("Error\nToo many rows");
}

static void	is_line_printable(char *line)
{
	int		i;
	char	*error_line;

	i = 0;
	error_line = "Error\nUnallowed symbols in map (tabs and other staff)";
	while (line[i] != '\0')
	{
		if (!ft_isprint(line[i]))
			leave(error_line);
		i++;
	}
}

static void	addin_ones(t_size_of_2d_arr *prog_data, t_all_raw_map_info *data)
{
	data->rows += 1;
	prog_data->ll_num += 1;
}

void	size_of_2d_arr(int fd, t_all_raw_map_info *data)
{
	t_size_of_2d_arr	prog_data;

	prog_data.line = NULL;
	data->rows = 0;
	prog_data.tmp_length = 0;
	prog_data.k = get_next_line(fd, &prog_data.line);
	prog_data.ll_num = 0;
	while ((prog_data.k) > 0)
	{
		is_line_printable(prog_data.line);
		addin_ones(&prog_data, data);
		prog_data.tmp_length = ft_strlen(prog_data.line);
		if ((unsigned int)prog_data.tmp_length > data->length)
			data->length = prog_data.tmp_length;
		free(prog_data.line);
		prog_data.k = get_next_line(fd, &prog_data.line);
	}
	if (prog_data.k == -1)
		leave("Error\n.cub file is directory ");
	if (prog_data.line != NULL)
	{
		addin_ones(&prog_data, data);
		free(prog_data.line);
	}
	lil_check(data, prog_data);
}
