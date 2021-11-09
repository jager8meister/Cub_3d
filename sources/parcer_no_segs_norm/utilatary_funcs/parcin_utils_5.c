#include "../parcer.h"

void	emptyness_filler(char **raw_map_data,
t_all_raw_map_info *data, int i, int *j)
{
	while ((unsigned int)*j < data->length)
	{
		raw_map_data[i][*j] = '\0';
		*j += 1;
	}
	raw_map_data[i][*j] = '\0';
}

int	is_substr_in_str(char *str, char *sub_str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str != NULL && sub_str != NULL)
	{
		while (str[i] != '\0')
		{
			if ((str[i] != ' ') && (str[i] != sub_str[0]))
				return (0);
			j = 0;
			while (sub_str[j] != '\0' && (str[i + j] == sub_str[j]))
				j++;
			if (sub_str[j] == '\0')
				return (1);
			i++;
		}
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t		length;
	long long	ll_num;

	length = 0;
	ll_num = 0;
	while (s[length])
	{
		length++;
		ll_num++;
	}
	if (ll_num != (long long)length)
		leave("Error\nLine is too big.");
	return (length);
}
