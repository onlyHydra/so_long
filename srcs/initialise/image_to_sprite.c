/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:54:32 by schiper           #+#    #+#             */
/*   Updated: 2025/03/23 15:15:56 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/game_elements.h"
#include "imports/minilibx-linux/mlx.h"

static t_sprites	*image_to_sprite(void *mlx, char *path)
{
	t_sprites	*sprite;

	sprite = malloc(sizeof(t_sprites));
	sprite->sprite = mlx_pnq_file_to_image(mlx, path, &sprite->width,
			&sprite->height);
	return (sprite);
}

void	free_sprite(void *mlx, t_sprites *sprite)
{
	mlx_destroy_image(mlx, sprite->sprite);
	free(sprite);
}

void	load_assets(void *mlx, t_assets *assets, t_settings *settings)
{
	assets->player_up = image_to_sprite(mlx, settings->player_up_path);
	assets->player_down = image_to_sprite(mlx, settings->player_down_path);
	assets->player_left = image_to_sprite(mlx, settings->player_left_path);
	assets->player_right = image_to_sprite(mlx, settings->player_right_path);
	assets->wall = image_to_sprite(mlx, settings->wall_path);
	assets->collectible = image_to_sprite(mlx, settings->collectible_path);
	assets->empty_space = image_to_sprite(mlx, settings->empty_space_path);
	assets->end_point = image_to_sprite(mlx, settings->end_point_path);
	assets->enemy = image_to_sprite(mlx, settings->enemy_path);
}
