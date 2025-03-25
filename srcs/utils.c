/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:09:42 by schiper           #+#    #+#             */
/*   Updated: 2025/03/25 17:12:35 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/game_elements.h"
#include "imports/ft_printf/header/ft_printf.h"

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
			game_type(game, x * IMG_PXL, y * IMG_PXL);
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
