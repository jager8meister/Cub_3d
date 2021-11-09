/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:01:33 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/11 18:48:08 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parcer.h"

int	double_values(t_all_raw_map_info *data)
{
	t_double_values_struct	d_v;

	d_v_zeros(&d_v);
	while ((unsigned int)d_v.i < data->rows)
	{
		if (doubles_check(d_v, data) == 1)
			leave("Error\nDublicates in cub file");
		screen_check_filler(&d_v, data);
		no_path_check_filler(&d_v, data);
		so_path_check_filler(&d_v, data);
		we_path_check_filler(&d_v, data);
		ea_path_check_filler(&d_v, data);
		s_check_filler(&d_v, data);
		f_check_filler(&d_v, data);
		c_check_filler(&d_v, data);
		d_v.i++;
	}
	return (0);
}
