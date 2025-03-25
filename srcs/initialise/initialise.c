/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:29:19 by schiper           #+#    #+#             */
/*   Updated: 2025/03/25 19:38:13 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_elements.h"
#include "get_next_line_bonus.h"
#include "mlx.h"
#include "so_long.h"

static void	update_movements(t_game **game)
{
	(*game)->x_movement[0] = -1;
	(*game)->x_movement[1] = +1;
	(*game)->x_movement[2] = 0;
	(*game)->x_movement[3] = -0;
	(*game)->x_movement[4] = 0;
	(*game)->y_movement[0] = 0;
	(*game)->y_movement[1] = 0;
	(*game)->y_movement[2] = -1;
	(*game)->y_movement[3] = +1;
	(*game)->y_movement[4] = 0;
}

t_game	initialise_all(char *str)
{
	int				freg_vector[256];
	char			**game_board;
	t_game_elements	*game_elements;
	t_game			game;

	game.mlx = mlx_init();
	game.settings = load_settings();
	game.assets = load_assets(game.mlx, &(game.settings));
	game_board = create_gameboard(str, &freg_vector);
	validate_game_board(game_board, freg_vector, game_elements);
	game.game_board = game_board;
	game.player = load_player(game.game_board);
	game.move = 0;
	game.collectibles = freg_vector[COLLECTIBLE];
	game.exit = 0;
	update_movements(&game);
	return (game);
}
