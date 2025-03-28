/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:10:42 by schiper           #+#    #+#             */
/*   Updated: 2025/03/28 21:46:35 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_elements.h"
#include "get_next_line.h"
#include "mlx.h"
#include "so_long.h"

int	game_loop(t_game *game)
{
	while (game->exit == 0)
	{
		game_printer(game);
	}
	return (0);
}
