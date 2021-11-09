/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_for_main.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsidney <tsidney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:15:17 by tsidney           #+#    #+#             */
/*   Updated: 2021/04/20 16:52:59 by tsidney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_FOR_MAIN_H
# define HEADER_FOR_MAIN_H

# include "parcer.h"
# include "../textures.h"
// # include "../../mlx/mlx.h"

void		amount_of_sprites(t_playa *param);
void		sprites_array_loop(t_playa *param);
void		sprites_array(t_playa *param);
void		player_buffer_creation(t_playa *param);
void		player_finder_on_integer_map(t_playa *param);
void		player_starter_data(t_playa *param,
				t_map_to_draw int_map, t_map_data map);
void		player_image_creation(t_playa *param);
void		player_creation(t_playa *param,
				t_map_to_draw int_map, t_map_data map);
void		player_win_adding(t_playa *param);
int			player_direction_finder(t_playa *param);
void		start_rotation(t_playa *param);
void		mainik_mlx_hooks(t_playa *playerok);
void		image_drawer(t_playa *param);
void		game_start(t_playa *param);
void		map_freesher(t_map_data *map);
void		map_freesher_int(t_map_to_draw *map);
// void		resolution_second_check(t_playa *param);
#endif
