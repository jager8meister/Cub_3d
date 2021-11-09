/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcin_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 00:25:53 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/11 17:27:12 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parcer.h"

int	we_path_check_func(char *str)
{
	char	*we_path;

	we_path = "WE ";
	return (is_substr_in_str(str, we_path));
}

int	ea_path_check_func(char *str)
{
	char	*ea_path;

	ea_path = "EA ";
	return (is_substr_in_str(str, ea_path));
}

int	s_check_func(char *str)
{
	char	*s;

	s = "S ";
	return (is_substr_in_str(str, s));
}

int	f_check_func(char *str)
{
	char	*f;

	f = "F ";
	return (is_substr_in_str(str, f));
}

int	c_check_func(char *str)
{
	char	*c;

	c = "C ";
	return (is_substr_in_str(str, c));
}
