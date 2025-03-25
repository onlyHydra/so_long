/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:10:42 by schiper           #+#    #+#             */
/*   Updated: 2025/03/25 17:45:12 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_elements.h"
#include "imports/get_next_line/get_next_line_bonus.h"
#include "imports/minilibx-linux/mlx.h"
#include "so_long.h"

int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		ft_exit(game);
	else if (keycode == UP)
		move(game, UP);
	else if (keycode == LEFT)
		move(game, LEFT);
	else if (keycode == DOWN)
		move(game, DOWN);
	else if (keycode == RIGHT)
		move(game, RIGHT);
	return (0);
}

void	game_loop(t_game *game)
{
	while (game->exit == 0)
	{
		game_printer(game);
		mlx_hook(game->wnd, 17, 1L << 2, ft_close, game);
		mlx_key_hook(game->wnd, ft_key_hook, game);
	}
}
