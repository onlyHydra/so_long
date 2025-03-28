/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_gameboard.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:15:46 by schiper           #+#    #+#             */
/*   Updated: 2025/03/28 19:34:30 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game_elements.h"
#include "so_long.h"

static void	flood_fill(char **board, int x, int y, int *freq_vector)
{
	freq_vector[(int)board[x][y]]--;
	if (board[x][y] != EMPTY_SPACE && board[x][y] != START_POINT)
		return ;
	if (board[x][y] != WALL && board[x][y] != 'M')
		board[x][y] = 'M';
	flood_fill(board, x - 1, y, freq_vector);
	flood_fill(board, x + 1, y, freq_vector);
	flood_fill(board, x, y - 1, freq_vector);
	flood_fill(board, x, y + 1, freq_vector);
}

static int	validate_path_to_end(char **game_board,
		t_game_elements *game_elements)
{
	int	true_flag;
	int	*freq_vector;

	freq_vector = populate_freg_vector(game_board);
	true_flag = 0;
	flood_fill(game_board, game_elements->start_point_x,
		game_elements->start_point_y, freq_vector);
	if (freq_vector[COLLECTIBLE] > 0)
		true_flag = 1;
	if (freq_vector[END_POINT] > 0)
		true_flag = 1;
	if (freq_vector[START_POINT] > 0)
		true_flag = 1;
	free(freq_vector);
	return (true_flag);
}

// validates if the unique game elements conditions is applied to the game board
static int	validate_unique_game_elements(char **game_board)
{
	int	check_sum;
	int	returned_sum;
	int	*freq_vector;

	freq_vector = populate_freg_vector(game_board);
	returned_sum = 0;
	check_sum = freq_vector[START_POINT] + freq_vector[END_POINT];
	if (check_sum != 2)
		returned_sum += 4;
	check_sum += freq_vector[COLLECTIBLE];
	if (check_sum == 2)
		returned_sum += 8;
	free(freq_vector);
	return (returned_sum);
}

// validates if the game_board has been boarded by walls
static int	validate_boarder(char **game_board)
{
	int	index;
	int	game_board_size;

	game_board_size = get_game_board_size(game_board);
	index = 0;
	while (game_board[0][index] != '\0' && game_board[0][index] != '\n')
	{
		if (game_board[0][index] != '1' || game_board[game_board_size
			- 1][index] != '1')
			return (1);
		index++;
	}
	game_board_size = index;
	index = 0;
	while (game_board[index][game_board_size] != '\0'
		&& game_board[0][game_board_size] != '\n')
	{
		if (game_board[index][0] != '1' || game_board[index][game_board_size
			- 1] != '1')
			return (1);
		index++;
	}
	return (0);
}

// checks all conditions for a valid game board
int	validate_game_board(char **game_board, t_game_elements *game_elements)
{
	char	**game_board_copy;

	game_board_copy = copy_game_board(game_board);
	if (validate_boarder(game_board_copy) != 0)
	{
		ft_printf("Game board is not surrounded by walls");
		return (1);
	}
	if (validate_unique_game_elements(game_board_copy) != 0)
	{
		ft_printf("Game board has more than one start point or end point");
		return (1);
	}
	if (validate_path_to_end(game_board_copy, game_elements) != 0)
		ft_printf("Not all elements on the board are reachable");
	free_double_array(game_board_copy);
	return (0);
}
