/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:29:19 by schiper           #+#    #+#             */
/*   Updated: 2025/03/29 13:55:16 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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

static void	get_out(t_game game)
{
	free_double_array(game.game_board);
	free_assets(game.mlx, &game.assets);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
	exit(0);
}

t_game	initialise_all(int fd)
{
	int				*freg_vector;
	t_game_elements	game_elements;
	t_game			game;

	game.mlx = mlx_init();
	game.settings = load_settings();
	game.assets = load_assets(game.mlx, &game.settings);
	game.game_board = create_gameboard(fd);
	game_elements = load_elements(game.game_board);
	game.player = load_player(game.game_board);
	game.move = 0;
	freg_vector = populate_freg_vector(game.game_board);
	game.collectibles = freg_vector[COLLECTIBLE];
	free(freg_vector);
	game.exit = 0;
	game.x = ft_strlen(game.game_board[0]) - 1;
	game.y = get_game_board_size(game.game_board);
	update_movements(&game);
	if (validate_game_board(game.game_board, &game_elements) != 0)
		get_out(game);
	return (game);
}
