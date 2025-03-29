/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:05:52 by schiper           #+#    #+#             */
/*   Updated: 2025/03/29 14:06:39 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game_elements.h"
#include "get_next_line_bonus.h"
#include "mlx.h"
#include "so_long.h"

int	same_size(char **game_board)
{
	int	i;
	int	prev_len;
	int	curr_len;

	prev_len = ft_strlen(game_board[0]);
	if (game_board[0][prev_len - 1] == '\n')
		prev_len--;
	i = 1;
	while (game_board[i])
	{
		curr_len = ft_strlen(game_board[i]);
		if (game_board[i][curr_len - 1] == '\n')
			curr_len--;
		if (curr_len != prev_len)
			return (1);
		i++;
	}
	return (0);
}

int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		ft_close(game);
	else if (keycode == UP && game->exit == 0)
		move(game, UP);
	else if (keycode == LEFT && game->exit == 0)
		move(game, LEFT);
	else if (keycode == DOWN && game->exit == 0)
		move(game, DOWN);
	else if (keycode == RIGHT && game->exit == 0)
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
	int		fd;
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error:\n Wrong number of arguments\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\n File does not exist", 2);
		close(fd);
		return (1);
	}
	game = initialise_all(fd);
	close(fd);
	if (game.game_board == NULL)
		return (1);
	game_loop2(&game);
	return (0);
}
