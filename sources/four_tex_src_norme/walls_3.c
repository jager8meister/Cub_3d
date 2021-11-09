/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:19:19 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/13 18:47:39 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../textures.h"
#include "../parcer_no_segs_norm/parcer.h"

void	texture_starter(t_texture *parameter, void *mlx_ptr)
{
	parameter->texture_image.ptr = mlx_xpm_file_to_image(mlx_ptr,
			parameter->texture_path,
			&parameter->img_width, &parameter->img_height);
	if (parameter->texture_image.ptr == NULL)
		leave("Error\nUnable to open xpm file.");
	parameter->texture_image.data
		= (int *)mlx_get_data_addr(parameter->texture_image.ptr,
			&parameter->texture_image.bpp,
			&parameter->texture_image.size_l, &parameter->texture_image.endian);
}

void	walls_starter(t_playa *param, t_walls *walls)
{
	walls->wall_n.texture_path = param->wall_n_path;
	texture_starter(&walls->wall_n, param->mlx_ptr);
	walls->wall_s.texture_path = param->wall_s_path;
	texture_starter(&walls->wall_s, param->mlx_ptr);
	walls->wall_e.texture_path = param->wall_e_path;
	texture_starter(&walls->wall_e, param->mlx_ptr);
	walls->wall_w.texture_path = param->wall_w_path;
	texture_starter(&walls->wall_w, param->mlx_ptr);
}
