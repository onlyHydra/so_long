/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visuals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:13:27 by schiper           #+#    #+#             */
/*   Updated: 2025/03/29 00:12:19 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game_elements.h"
#include "mlx.h"
#include "so_long.h"

t_sprites	*image_to_sprite(void *mlx, char *path)
{
	t_sprites	*sprite;

	sprite = malloc(sizeof(t_sprites));
	sprite->sprite = mlx_xpm_file_to_image(mlx, path, &sprite->width,
			&sprite->height);
	if (sprite->sprite == NULL)
	{
		ft_printf("Error: Failed to load image from path: %s\n", path);
		free(sprite);
		return (NULL);
	}
	return (sprite);
}

void	update_sprites(t_game game, int x, int y, int dir)
{
	mlx_put_image_to_window(game.mlx, game.wnd, game.assets.empty_space->sprite,
		game.player.y * IMG_PXL, game.player.x * IMG_PXL);
	game.game_board[game.player.x][game.player.y] = EMPTY_SPACE;
	game.game_board[x][y] = START_POINT;
	game.player.x = x;
	game.player.y = y;
	if (dir == UP)
		mlx_put_image_to_window(game.mlx, game.wnd,
			game.assets.player_up->sprite, y * IMG_PXL, x * IMG_PXL);
	else if (dir == DOWN)
		mlx_put_image_to_window(game.mlx, game.wnd,
			game.assets.player_down->sprite, y * IMG_PXL, x * IMG_PXL);
	else if (dir == LEFT)
		mlx_put_image_to_window(game.mlx, game.wnd,
			game.assets.player_left->sprite, y * IMG_PXL, x * IMG_PXL);
	else if (dir == RIGHT)
		mlx_put_image_to_window(game.mlx, game.wnd,
			game.assets.player_right->sprite, y * IMG_PXL, x * IMG_PXL);
	print_movements(game);
}

void	render_map(t_game *game, int x, int y)
{
	int	type;

	type = game->game_board[y / IMG_PXL][x / IMG_PXL];
	if (type == 'C' || type == 'P' || type == 'E' || type == '0')
		mlx_put_image_to_window(game->mlx, game->wnd,
			game->assets.empty_space->sprite, x, y);
	if (type == 'C')
		mlx_put_image_to_window(game->mlx, game->wnd,
			game->assets.collectible->sprite, x, y);
	else if (type == 'P')
		mlx_put_image_to_window(game->mlx, game->wnd,
			game->assets.player_down->sprite, x, y);
	else if (type == 'E')
		mlx_put_image_to_window(game->mlx, game->wnd,
			game->assets.end_point->sprite, x, y);
	else if (type == '1')
		mlx_put_image_to_window(game->mlx, game->wnd, game->assets.wall->sprite,
			x, y);
}

void	ft_win(t_game *game)
{
	game->exit = 1;
	mlx_clear_window(game->mlx, game->wnd);
	mlx_string_put(game->mlx, game->wnd, game->x / 2 * IMG_PXL, game->y / 2
		* IMG_PXL, 0xFFFA9E, "YOU WON");
	write(1, "\n", 1);
	write(1, "\x1b[32;01m", 9);
	write(1, "🏆🏆YOU WON!!🏆🏆\n", 27);
	write(1, "\x1b[0m", 5);
}
