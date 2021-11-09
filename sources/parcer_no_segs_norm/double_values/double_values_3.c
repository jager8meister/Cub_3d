/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_values_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:01:12 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/11 15:43:06 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parcer.h"

void	f_check_filler(t_double_values_struct *d_v,
t_all_raw_map_info *data)
{
	if (d_v->f_check == 0)
	{
		d_v->f_check = f_check_func(data->raw_map_data[d_v->i]);
		data->f_line_index = d_v->i;
	}
}

void	c_check_filler(t_double_values_struct *d_v,
t_all_raw_map_info *data)
{
	if (d_v->c_check == 0)
	{
		d_v->c_check = c_check_func(data->raw_map_data[d_v->i]);
		data->c_line_index = d_v->i;
	}
}
