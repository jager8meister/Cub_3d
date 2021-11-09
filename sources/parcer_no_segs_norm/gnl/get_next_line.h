/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:54:17 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/11 16:56:21 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl
{
	char		*buffer;
	char		*new_line;
	int			symbols_was_read;
	char		*tmp;
}				t_gnl;

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(const char *str, int n);
int		error_free(char **str1, char **str2);
char	*ft_sub_nstr(char const *s);
char	*new_line_func(char *old_data, char **line, int *symbols_was_read);

#endif
