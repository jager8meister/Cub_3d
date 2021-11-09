/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcin_utils_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 20:50:41 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/11 17:28:17 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parcer.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

void	leave(char *msg)
{
	ft_putstr_fd(msg, 1);
	if (msg[0])
		write(1, "\n", 1);
	exit(0);
}

int	char_index(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*substring;

	if (!s)
		return (NULL);
	substring = (char *)malloc(sizeof(*s) * (len + 1));
	if (!substring)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			substring[j] = s[i];
			j++;
		}
		i++;
	}
	substring[j] = 0;
	return (substring);
}
