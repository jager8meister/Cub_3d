/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainik.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:20:12 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/20 18:17:47 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_for_main.h"

static void	argc_check(int argc, char **argv)
{
	if (argc >= 4)
		leave("Error\nToo many args passed");
	if (argc == 3)
	{
		if (ft_strncmp(argv[1], "--save", ft_strlen("--save")) == 0
			&& ft_strlen(argv[1]) == ft_strlen("--save"))
			leave("Error\nWrong position of --save parameter.");
	}
}

static int	save_check(char **argv)
{
	if (ft_strncmp(argv[2], "--save", ft_strlen("--save")) == 0
		&& ft_strlen(argv[2]) == ft_strlen("--save"))
		return (1);
	else
		leave("Error\nWrong second arg");
	return (0);
}

int	main(int argc, char **argv)
{
	t_map_data		map;
	int				will_be_saved;
	t_map_to_draw	int_map;
	t_playa			player;

	will_be_saved = 0;
	argc_check(argc, argv);
	if (argc > 1 && argc < 4)
	{
		if (!cub_exists(argv[1]))
			leave("Error\n.cub filename is invalid");
		parcer(argv[1], &map);
		map_leaks_check(&map);
		transitter(map.map, &int_map);
		if ((argc > 2) && (save_check(argv)))
			will_be_saved = 1;
		player_creation(&player, int_map, map);
		map_freesher(&map);
		start_rotation(&player);
		if (will_be_saved == 1)
			image_drawer(&player);
		else
			game_start(&player);
	}
}
