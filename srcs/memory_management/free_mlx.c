/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:23:12 by schiper           #+#    #+#             */
/*   Updated: 2025/03/25 18:04:57 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/game_elements.h"
#include "imports/minilibx-linux/mlx.h"

void	free_assets(void *mlx, t_assets *assets)
{
	free_sprite(mlx, assets->player_up);
	free_sprite(mlx, assets->player_down);
	free_sprite(mlx, assets->player_left);
	free_sprite(mlx, assets->player_right);
	free_sprite(mlx, assets->wall);
	free_sprite(mlx, assets->collectible);
	free_sprite(mlx, assets->empty_space);
	free_sprite(mlx, assets->end_point);
	free(assets);
}

void	free_double_array(void **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_sprite(void *mlx, t_sprites *sprite)
{
	mlx_destroy_image(mlx, sprite->sprite);
	free(sprite);
}

int	ft_close(t_game *game)
{
	mlx_destroy_window(game->mlx, game->wnd);
	free_double_array(game->game_board);
	free_assets(game->mlx, &(game->assets));
	mlx_destroy_display(game->mlx);
	return (0);
}
