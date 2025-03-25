/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:54:32 by schiper           #+#    #+#             */
/*   Updated: 2025/03/25 19:38:01 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_elements.h"
#include "mlx.h"

t_entity	load_player(char **game_board)
{
	t_entity	player;
	int			i;
	int			j;

	i = 0;
	while (game_board[i])
	{
		j = 0;
		while (game_board[i][j])
		{
			if (game_board[i][j] == START_POINT)
			{
				player.x = i;
				player.y = j;
			}
			j++;
		}
		i++;
	}
	return (player);
}

t_settings	load_settings(void)
{
	t_settings	settings;

	settings.empty_space_path = "";
	settings.wall_path = "";
	settings.collectible_path = "";
	settings.end_point_path = "";
	settings.player_down_path = "";
	settings.player_up_path = "";
	settings.player_left_path = "";
	settings.player_right_path = "";
	return (settings);
}

t_assets	load_assets(void *mlx, t_settings *settings)
{
	t_assets	assets;

	assets.player_up = image_to_sprite(mlx, settings->player_up_path);
	assets.player_down = image_to_sprite(mlx, settings->player_down_path);
	assets.player_left = image_to_sprite(mlx, settings->player_left_path);
	assets.player_right = image_to_sprite(mlx, settings->player_right_path);
	assets.wall = image_to_sprite(mlx, settings->wall_path);
	assets.collectible = image_to_sprite(mlx, settings->collectible_path);
	assets.empty_space = image_to_sprite(mlx, settings->empty_space_path);
	assets.end_point = image_to_sprite(mlx, settings->end_point_path);
	return (assets);
}
