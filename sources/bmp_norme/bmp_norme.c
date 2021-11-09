/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_norme.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:04:09 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/15 19:04:25 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../textures.h"

static void	ft_bzero(void *s, size_t n)
{
	unsigned char	*result;

	result = (unsigned char *)s;
	while (n--)
		*result++ = '\0';
}

void	take_screenshot(t_data *all, t_playa *param)
{
	int		fd;
	char	bitmap[54];

	fd = open("screenshot.bmp", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	if (!fd)
		exit(-1);
	if (fd < 0)
		exit(-1);
	ft_bzero(bitmap, 54);
	bitmap[0] = 'B';
	bitmap[1] = 'M';
	*((int *)(bitmap + 2)) = param->window_height
		* param->window_width * 4 + 54;
	*(int *)(bitmap + 10) = 54;
	*(int *)(bitmap + 14) = 40;
	*(int *)(bitmap + 18) = param->window_width;
	*(int *)(bitmap + 22) = param->window_height;
	*(bitmap + 26) = 1;
	*(bitmap + 28) = 32;
	write(fd, bitmap, 54);
	write_img(fd, all, param);
}

void	write_img(int fd, t_data *all, t_playa *param)
{
	int	x;
	int	y;
	int	color;

	y = param->window_height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < param->window_width)
		{
			color = *(unsigned int *)(all->addr
					+ (y * all->line_length)
					+ x * (all->bits_per_pixel / 8));
			write(fd, &color, 4);
			x++;
		}
		y--;
	}
	close(fd);
}
