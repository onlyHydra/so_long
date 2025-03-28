/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:05:52 by schiper           #+#    #+#             */
/*   Updated: 2025/03/26 21:13:15 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game_elements.h"
#include "get_next_line_bonus.h"
#include "mlx.h"
#include "so_long.h"

int	ft_key_hook(int keycode, t_game *game)
{
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

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error:\n Wrong number of arguments\n");
		return (1);
	}
	game = initialise_all(argv[1]);
	game.wnd = mlx_new_window(game.mlx, game.x * IMG_PXL, game.y * IMG_PXL,
			"so_long");
	mlx_hook(game.wnd, 17, 1L << 2, ft_close, &game);
	mlx_key_hook(game.wnd, ft_key_hook, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
