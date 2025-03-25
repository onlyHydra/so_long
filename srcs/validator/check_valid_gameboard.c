/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_gameboard.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:15:46 by schiper           #+#    #+#             */
/*   Updated: 2025/03/25 17:46:57 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/game_elements.h"
#include "header/so_long.h"

static void	flood_fill(char **board, int x, int y)
{
	if (board[x][y] != EMPTY_SPACE && board[x][y] != START_POINT)
		return ;
	if (board[x][y] == EMPTY_SPACE)
		board[x][y] = 'M';
	flood_fill(board, x - 1, y);
	flood_fill(board, x + 1, y);
	flood_fill(board, x, y - 1);
	flood_fill(board, x, y + 1);
}

static int	validate_path_to_end(char **game_board,
		t_game_elements *game_elements)
{
	int	x;
	int	y;
	int	true_flag;

	x = 0;
	true_flag = 0;
	flood_fill(game_board, game_elements->start_point_x,
		game_elements->start_point_y);
	while (game_board[x])
	{
		y = 0;
		while (game_board[x][y] != '\n' || game_board[x][y] != '\0')
		{
			if (game_board[x][y] != WALL && game_board[x][y] != 'M')
			{
				true_flag += (game_board[x][y - 1] == 'M');
				true_flag += (game_board[x][y + 1] == 'M');
				true_flag += (game_board[x - 1][y] == 'M');
				true_flag += (game_board[x + 1][y] == 'M');
			}
			y++;
		}
		x++;
	}
	return (true_flag);
}

// validates if the unique game elements conditions is applied to the game board
static int	validate_unique_game_elements(int *freq_vector)
{
	int	check_sum;
	int	returned_sum;

	returned_sum = 0;
	check_sum = freq_vector[START_POINT] + freq_vector[END_POINT];
	if (check_sum != 2)
		returned_sum += 3;
	check_sum += freq_vector[COLLECTIBLE];
	if (check_sum == 2)
		returned_sum += 7;
	return (returned_sum);
}

// validates if the game_board has been boarded by walls
static int	validate_boarder(char **game_board)
{
	int	index;
	int	game_board_size;

	game_board_size = get_game_board_size(game_board);
	index = 0;
	while (game_board[0][index] != '\0')
	{
		if (game_board[0][index] != '1' || game_board[game_board_size
			- 1][index] != '1')
			return (1);
		index++;
	}
	game_board_size = index;
	index = 0;
	while (game_board[index][0] != '\0')
	{
		if (game_board[index][0] != '1' || game_board[index][game_board_size
			- 1] != '1')
			return (1);
		index++;
	}
	return (0);
}

// checks all conditions for a valid game board
int	validate_game_board(char **game_board, int *freq_vector,
		t_game_elements *game_elements)
{
	int	valid;

	valid = validate_boarder(game_board)
		+ validate_unique_game_elements(freq_vector);
	if (validate_path_to_end(game_board, game_elements) != 0)
		add_error_message("Not all elements on the board are reachable");
	return (valid);
}
