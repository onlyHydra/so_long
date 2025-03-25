/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:23:12 by schiper           #+#    #+#             */
/*   Updated: 2025/03/25 16:27:54 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/game_elements.h"
#include "imports/minilibx-linux/mlx.h"

void	free_sprite(void *mlx, t_sprites *sprite)
{
	mlx_destroy_image(mlx, sprite->sprite);
	free(sprite);
}

int	ft_close(t_game *game)
{
	mlx_destroy_window(game->mlx, game->wnd);
	ft_free_array(game->game_board);
	return (0);
}
