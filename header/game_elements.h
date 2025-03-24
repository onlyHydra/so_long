/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_elements.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:33:22 by schiper           #+#    #+#             */
/*   Updated: 2025/03/24 13:11:12 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(GAME_ELEMENTS_H)
# define GAME_ELEMENTS_H

# define START_POINT 'P'
# define END_POINT 'E'
# define COLLECTIBLE 'C'
# define EMPTY_SPACE '0'
# define WALL '1'

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53

typedef struct s_game_elements
{
	int			start_point_x;
	int			start_point_y;
	int			end_point_x;
	int			end_point_y;
}				t_game_elements;

typedef struct s_entity
{
	int			x;
	int			y;
}				t_entity;

typedef struct s_sprites
{
	void		*sprite;
	int			width;
	int			height;
}				t_sprites;

typedef struct s_assets
{
	t_sprites	*player_up;
	t_sprites	*player_down;
	t_sprites	*player_left;
	t_sprites	*player_right;
	t_sprites	*wall;
	t_sprites	*collectible;
	t_sprites	*empty_space;
	t_sprites	*end_point;
	t_sprites	*enemy;
}				t_assets;

typedef struct s_settings
{
	char		*player_up_path;
	char		*player_down_path;
	char		*player_left_path;
	char		*player_right_path;
	char		*wall_path;
	char		*collectible_path;
	char		*empty_space_path;
	char		*end_point_path;
	char		*enemy_path;
	int			map_width;
	int			map_height;
	int			tile_size;
	int			collectibles;
	int			enemy;
}				t_settings;

int				validate_game_board(char **game_board,
					int *apparance_rate_game_elements,
					t_game_elements *game_elements);
#endif // GAME_ELEMENTS_H
