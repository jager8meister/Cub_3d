/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:53:50 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/11 16:54:37 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	new_line_finder(char **buffer, char **new_line, char **old_data)
{
	*new_line = ft_strchr(*buffer, '\n');
	if ((*new_line))
	{
		*(*new_line)++ = '\0';
		if (*old_data)
			free(*old_data);
		*old_data = ft_strjoin("", *new_line);
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*old_data;
	t_gnl		all_data;

	all_data.buffer = malloc((10 + 1) * sizeof(char));
	if ((fd < 0 || 10 < 1 || !line || !(all_data.buffer)))
		return (-1);
	all_data.new_line
		= new_line_func(old_data, line, &all_data.symbols_was_read);
	while (!all_data.new_line && (all_data.symbols_was_read))
	{
		all_data.symbols_was_read = read(fd, all_data.buffer, 10);
		if (all_data.symbols_was_read < 0)
			return (error_free(&old_data, &all_data.buffer));
		all_data.buffer[all_data.symbols_was_read] = '\0';
		new_line_finder(&all_data.buffer, &all_data.new_line, &old_data);
		all_data.tmp = *line;
		*line = ft_strjoin(*line, all_data.buffer);
		if (all_data.tmp)
			free(all_data.tmp);
	}
	free(all_data.buffer);
	if (!all_data.symbols_was_read && old_data)
		error_free(&old_data, &old_data);
	return (all_data.symbols_was_read || all_data.new_line);
}
