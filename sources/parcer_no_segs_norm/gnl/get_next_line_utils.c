/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:54:05 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/11 16:09:48 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*result;
	int		i;

	i = 0;
	result = malloc((sizeof(char)
				* ((ft_strchr(s1, '\0') - s1) + (ft_strchr(s2, '\0') - s2) + 1)));
	if ((!s1 && s2) || !(result))
		return (NULL);
	while (s1 && *s1 != '\0' && ++i)
		*result++ = *s1++;
	while (s2 && *s2 != '\0' && ++i)
		*result++ = *s2++;
	*result = '\0';
	return (result - i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*result;
	char	symbol;

	result = (char *)s;
	symbol = (char)c;
	while (*result && !(*result == symbol))
		result++;
	if (*result == symbol)
		return (result);
	return (NULL);
}

int	error_free(char **str1, char **str2)
{
	if (*str1)
	{
		free(*str1);
		*str1 = NULL;
	}
	if (*str2)
	{
		free(*str2);
		*str2 = NULL;
	}
	return (-1);
}

char	*ft_sub_nstr(char const *str)
{
	size_t	j;
	size_t	len;
	char	*substring;

	if (!str)
		return (NULL);
	len = 0;
	while ((str[len] != '\n') && (str[len] != '\0'))
		len++;
	substring = (char *)malloc(sizeof(*str) * (len + 1));
	if (!substring)
		return (NULL);
	j = 0;
	while (str[j] && (j < len))
	{
		substring[j] = str[j];
		j++;
	}
	substring[j] = '\0';
	return (substring);
}

char	*new_line_func(char *old_data, char **line, int *symbols_was_read)
{
	char	*new_line;
	char	*tmp;

	new_line = NULL;
	*symbols_was_read = 1;
	*line = ft_sub_nstr("");
	if (old_data)
	{
		tmp = *line;
		*line = ft_sub_nstr(old_data);
		free(tmp);
		new_line = ft_strchr(old_data, '\n');
		if (new_line)
		{
			*new_line++ = '\0';
			while (*new_line)
				*old_data++ = *new_line++;
			*old_data = '\0';
		}
	}
	return (new_line);
}
