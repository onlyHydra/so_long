/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_elements.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:33:22 by schiper           #+#    #+#             */
/*   Updated: 2025/03/29 00:12:25 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(GAME_ELEMENTS_H)
# define GAME_ELEMENTS_H

# define START_POINT 'P'
# define END_POINT 'E'
# define COLLECTIBLE 'C'
# define EMPTY_SPACE '0'
# define WALL '1'

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESC 65307

# define IMG_PXL 64

typedef struct s_game_elements
{
	int				start_point_x;
	int				start_point_y;
	int				end_point_x;
	int				end_point_y;
}					t_game_elements;

typedef struct s_entity
{
	int				x;
	int				y;
}					t_entity;

typedef struct s_sprites
{
	void			*sprite;
	int				width;
	int				height;
}					t_sprites;

typedef struct s_assets
{
	t_sprites		*player_up;
	t_sprites		*player_down;
	t_sprites		*player_left;
	t_sprites		*player_right;
	t_sprites		*wall;
	t_sprites		*collectible;
	t_sprites		*empty_space;
	t_sprites		*end_point;
}					t_assets;

typedef struct s_settings
{
	char			*player_up_path;
	char			*player_down_path;
	char			*player_left_path;
	char			*player_right_path;
	char			*wall_path;
	char			*collectible_path;
	char			*empty_space_path;
	char			*end_point_path;
}					t_settings;

typedef struct s_game
{
	void			*mlx;
	void			*wnd;
	t_assets		assets;
	t_settings		settings;
	t_entity		player;
	char			**game_board;
	unsigned int	move;
	unsigned int	collectibles;
	int				x_movement[5];
	int				y_movement[5];
	int				x;
	int				y;
	int				exit;
}					t_game;

int					validate_game_board(char **game_board,
						t_game_elements *game_elements);
void				update_sprites(t_game game, int x, int y, int dir);
void				move(t_game *game, int dir);
void				ft_win(t_game *game);
int					ft_close(t_game *game);
int					game_loop(t_game *game);
void				render_map(t_game *game, int x, int y);
void				print_movements(t_game game);
void				game_printer(t_game *game);
t_assets			load_assets(void *mlx, t_settings *settings);
t_settings			load_settings(void);
t_entity			load_player(char **game_board);
t_game_elements		load_elements(char **game_board);
t_game				initialise_all(char *str);
t_sprites			*image_to_sprite(void *mlx, char *path);
void				free_double_array(char **array);
int					*populate_freg_vector(char **game_board);
char				**copy_game_board(char **game_board);

#endif // GAME_ELEMENTS_H
