/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:09:42 by schiper           #+#    #+#             */
/*   Updated: 2025/03/28 23:42:39 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game_elements.h"
#include "mlx.h"
#include "so_long.h"

char	**copy_game_board(char **game_board)
{
	int		i;
	int		j;
	char	**copy;

	i = 0;
	while (game_board[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (game_board[i])
	{
		j = 0;
		copy[i] = malloc(sizeof(char) * (ft_strlen1(game_board[i]) + 1));
		while (game_board[i][j])
		{
			copy[i][j] = game_board[i][j];
			j++;
		}
		copy[i][j] = '\0';
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

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
		i++;
	}
	return (game_elements);
}

void	game_printer(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->x)
	{
		y = 0;
		while (y < game->y)
		{
			render_map(game, x * IMG_PXL, y * IMG_PXL);
			y++;
		}
		x++;
	}
}

void	print_movements(t_game game)
{
	write(1, "\r", 1);
	write(1, "\x1b[33;01m", 9);
	ft_printf("%d ", game.move);
	write(1, "\x1b[0m", 5);
	write(1, " movements", 11);
	write(1, "\n", 1);
}

int	get_game_board_size(char **game_board)
{
	int	x;

	x = 0;
	while (game_board[x])
		x++;
	return (x);
}
