/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:50:13 by schiper           #+#    #+#             */
/*   Updated: 2025/03/25 16:11:10 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/game_elements.h"
#include "header/so_long.h"

static int	move_resume(int dir)
{
	if (dir == UP)
		return (0);
	if (dir == DOWN)
		return (1);
	if (dir == LEFT)
		return (2);
	if (dir == RIGHT)
		return (3);
	return (4);
}

static int	check_tile(t_game *game, int x, int y)
{
	if (game->game_board[y][x] == WALL)
		return (0);
	if (game->game_board[y][x] == END_POINT && game->collectibles == 0)
		return (2);
	if (game->game_board[y][x] == COLLECTIBLE)
	{
		game->game_board[y][x] = EMPTY_SPACE;
		game->collectibles--;
	}
	return (1);
}

void	move(t_game *game, int dir)
{
	int	player_x;
	int	player_y;
	int	move_status;

	player_x = game->player.x + game->x_movement[move_resume(dir)];
	player_y = game->player.y + game->y_movement[move_resume(dir)];
	if (player_x == game->player.x && player_y == game->player.y)
		return ;
	move_status = check_tile(game, player_x, player_y);
	if (move_status == 0)
		return ;
	update_sprites(game, game->player.x, game->player.y, dir);
	game->player.x = player_x;
	game->player.y = player_y;
	game->move++;
	if (move_status == 2)
	{
		ft_win(game);
		return ;
	}
}
