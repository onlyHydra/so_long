/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:05:52 by schiper           #+#    #+#             */
/*   Updated: 2025/03/29 00:14:03 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game_elements.h"
#include "get_next_line_bonus.h"
#include "mlx.h"
#include "so_long.h"

int	ft_key_hook(int keycode, t_game *game)
{
	ft_printf("keycode: %d\n", keycode);
	if (keycode == ESC)
		ft_close(game);
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

/** TO DO
 *  initialise all elements
 */

static void	game_loop2(t_game *game)
{
	game->wnd = mlx_new_window(game->mlx, game->x * IMG_PXL, game->y * IMG_PXL,
			"so_long");
	game_printer(game);
	mlx_key_hook(game->wnd, ft_key_hook, game);
	mlx_hook(game->wnd, 17, 0L, ft_close, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error:\n Wrong number of arguments\n");
		return (1);
	}
	game = initialise_all(argv[1]);
	game_loop2(&game);
	return (0);
}
