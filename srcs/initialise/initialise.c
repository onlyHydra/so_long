/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:29:19 by schiper           #+#    #+#             */
/*   Updated: 2025/03/28 23:04:04 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_elements.h"
#include "get_next_line_bonus.h"
#include "mlx.h"
#include "so_long.h"

static void	update_movements(t_game *game)
{
	game->x_movement[0] = -1;
	game->x_movement[1] = +1;
	game->x_movement[2] = 0;
	game->x_movement[3] = -0;
	game->x_movement[4] = 0;
	game->y_movement[0] = 0;
	game->y_movement[1] = 0;
	game->y_movement[2] = -1;
	game->y_movement[3] = +1;
	game->y_movement[4] = 0;
}

t_game	initialise_all(char *str)
{
	int				*freg_vector;
	t_game_elements	game_elements;
	t_game			game;

	game.mlx = mlx_init();
	game.settings = load_settings();
	game.assets = load_assets(game.mlx, &game.settings);
	game.game_board = create_gameboard(str);
	game_elements = load_elements(game.game_board);
	validate_game_board(game.game_board, &game_elements);
	game.player = load_player(game.game_board);
	game.move = 0;
	freg_vector = populate_freg_vector(game.game_board);
	game.collectibles = freg_vector[COLLECTIBLE];
	free(freg_vector);
	game.exit = 0;
	game.x = ft_strlen(game.game_board[0]) - 1;
	game.y = get_game_board_size(game.game_board);
	update_movements(&game);
	return (game);
}
