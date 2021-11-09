#include "../parcer.h"

static void	commas_check(char *str)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
			res++;
		i++;
	}
	if (res != 2)
		leave("Error\nWrong amount of commas in rgb line");
}

int	check_line_format_rgb(char *str, int c,
	int first_char_pos)
{
	int	i;

	if (!str || str[first_char_pos] != c
		|| !is_space(str[first_char_pos + 1]))
		return (0);
	i = first_char_pos + 1;
	while (is_space(str[i]))
		i++;
	while (ft_isdigit(str[i]) || str[i] == ',' || is_space(str[i]))
		i++;
	while (is_space(str[i]))
		i++;
	if (str[i] != '\0' || ft_isdigit(str[i]))
		leave(ft_strjoin("Error\nColor string format :", str));
	commas_check(str);
	return (1);
}

void	color_thrower(t_all_raw_map_info *win_infos, int rgb, char c)
{
	if (c == 'F')
		win_infos->floor_color = rgb;
	else if (c == 'C')
		win_infos->ceiling_color = rgb;
}

int	file_exists(const char *fname)
{
	int	fd;
	int	fname_len;

	fname_len = ft_strlen(fname);
	fd = open(fname, O_RDONLY);
	if ((fd) == -1)
	{
		close(fd);
		return (0);
	}
	if (fname[fname_len - 1] != 'm' || fname[fname_len - 2] != 'p'
		|| fname[fname_len - 3] != 'x' || fname[fname_len - 4] != '.')
		return (0);
	return (1);
}
