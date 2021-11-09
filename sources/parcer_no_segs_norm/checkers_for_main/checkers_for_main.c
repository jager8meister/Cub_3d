/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_for_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:06:02 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/20 17:31:02 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parcer.h"

int	cub_exists(const char *fname)
{
	int	fd;
	int	fname_len;

	fname_len = ft_strlen(fname);
	fd = open(fname, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (0);
	}
	if (fname[fname_len - 1] != 'b' || fname[fname_len - 2] != 'u'
		|| fname[fname_len - 3] != 'c' || fname[fname_len - 4] != '.')
		return (0);
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while ((ptr1[i] || ptr2[i]) && i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}
