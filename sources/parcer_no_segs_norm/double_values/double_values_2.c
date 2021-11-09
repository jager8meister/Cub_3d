/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_values_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:00:07 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/11 18:44:09 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parcer.h"

void	we_path_check_filler(t_double_values_struct *d_v,
t_all_raw_map_info *data)
{
	if (d_v->we_path_check == 0)
	{
		d_v->we_path_check = we_path_check_func(data->raw_map_data[d_v->i]);
		data->we_line_index = d_v->i;
	}
}

void	ea_path_check_filler(t_double_values_struct *d_v,
t_all_raw_map_info *data)
{
	if (d_v->ea_path_check == 0)
	{
		d_v->ea_path_check = ea_path_check_func(data->raw_map_data[d_v->i]);
		data->ea_line_index = d_v->i;
	}
}

void	s_check_filler(t_double_values_struct *d_v,
t_all_raw_map_info *data)
{
	if (d_v->s_check == 0)
	{
		d_v->s_check = s_check_func(data->raw_map_data[d_v->i]);
		data->s_line_index = d_v->i;
	}
}
