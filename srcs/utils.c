/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:09:42 by schiper           #+#    #+#             */
/*   Updated: 2025/03/26 21:14:57 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game_elements.h"
#include "so_long.h"

t_game_elements	load_elements(char **game_board)
{
	t_game_elements	game_elements;
	int				i;
	int				j;

	i = 0;
	while (game_board[i])
	{
		j = 0;
		while (game_board[i][j])
		{
			if (game_board[i][j] == START_POINT)
			{
				game_elements.start_point_x = i;
				game_elements.start_point_y = j;
			}
			if (game_board[i][j] == END_POINT)
			{
				game_elements.end_point_x = i;
				game_elements.end_point_y = j;
			}
			j++;
		}
	}
	return (game_elements);
}

void	game_printer(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->y)
	{
		while (x < game->x)
		{
			render_map(game, x * IMG_PXL, y * IMG_PXL);
			x++;
		}
		x = 0;
		y++;
	}
}

void	print_movements(t_game *game)
{
	write(1, "\r", 1);
	write(1, "\x1b[33;01m", 9);
	ft_printf("%d", game->move);
	write(1, "\x1b[0m", 5);
	write(1, " movements", 11);
}

int	get_game_board_size(char **game_board)
{
	int	x;

	x = 0;
	while (game_board[x])
		x++;
	return (x);
}
