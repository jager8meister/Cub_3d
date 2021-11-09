/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_values_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:54:08 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/11 15:42:22 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parcer.h"

void	d_v_zeros(t_double_values_struct *d_v)
{
	d_v->screen_check = 0;
	d_v->no_path_check = 0;
	d_v->so_path_check = 0;
	d_v->we_path_check = 0;
	d_v->ea_path_check = 0;
	d_v->s_check = 0;
	d_v->f_check = 0;
	d_v->c_check = 0;
	d_v->i = 0;
}

int	doubles_check(t_double_values_struct d_v, t_all_raw_map_info *data)
{
	if (((d_v.screen_check == 1)
			&& (screen_check_func(data->raw_map_data[d_v.i]) == 1))
		|| ((d_v.no_path_check == 1)
			&& (no_path_check_func(data->raw_map_data[d_v.i]) == 1))
		|| ((d_v.so_path_check == 1)
			&& (so_path_check_func(data->raw_map_data[d_v.i]) == 1))
		|| ((d_v.we_path_check == 1)
			&& (we_path_check_func(data->raw_map_data[d_v.i]) == 1))
		|| ((d_v.ea_path_check == 1)
			&& (ea_path_check_func(data->raw_map_data[d_v.i]) == 1))
		|| ((d_v.s_check == 1)
			&& (s_check_func(data->raw_map_data[d_v.i]) == 1))
		|| ((d_v.f_check == 1)
			&& (f_check_func(data->raw_map_data[d_v.i]) == 1))
		|| ((d_v.c_check == 1)
			&& (c_check_func(data->raw_map_data[d_v.i]) == 1)))
		return (1);
	return (0);
}

void	screen_check_filler(t_double_values_struct *d_v,
t_all_raw_map_info *data)
{
	if (d_v->screen_check == 0)
	{
		d_v->screen_check = screen_check_func(data->raw_map_data[d_v->i]);
		data->r_line_index = d_v->i;
	}
}

void	no_path_check_filler(t_double_values_struct *d_v,
t_all_raw_map_info *data)
{
	if (d_v->no_path_check == 0)
	{
		d_v->no_path_check = no_path_check_func(data->raw_map_data[d_v->i]);
		data->no_line_index = d_v->i;
	}
}

void	so_path_check_filler(t_double_values_struct *d_v,
t_all_raw_map_info *data)
{
	if (d_v->so_path_check == 0)
	{
		d_v->so_path_check = so_path_check_func(data->raw_map_data[d_v->i]);
		data->so_line_index = d_v->i;
	}
}
