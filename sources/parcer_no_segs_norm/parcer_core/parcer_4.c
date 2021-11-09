#include "../parcer.h"

int	sprite_emptyness_checker(t_all_raw_map_info *data, int i, int j)
{
	return (((data->map.data[i][j] == ' ')
		&& (((((i - 1) >= 0) && (data->map.data[i - 1][j] == '2'))
			|| (((i + 1) < data->map.rows) && (data->map.data[i + 1][j] == '2'))
		|| (((j - 1) >= 0) && (data->map.data[i][j - 1] == '2'))
			|| (((j + 1) < data->map.width)
			&& (data->map.data[i][j + 1] == '2'))))));
}
