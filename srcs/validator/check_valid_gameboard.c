/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_gameboard.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:15:46 by schiper           #+#    #+#             */
/*   Updated: 2025/03/29 14:15:28 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game_elements.h"
#include "so_long.h"

static void	flood_fill(char **board, int x, int y, int *freq_vector)
{
	freq_vector[(int)board[x][y]]--;
	if (board[x][y] == WALL || board[x][y] == 'M')
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
		returned_sum = 1;
	check_sum += freq_vector[COLLECTIBLE];
	if (check_sum == 2)
		returned_sum = 1;
	freq_vector[START_POINT] = 0;
	freq_vector[END_POINT] = 0;
	freq_vector[COLLECTIBLE] = 0;
	freq_vector['\0'] = 0;
	freq_vector[WALL] = 0;
	freq_vector[EMPTY_SPACE] = 0;
	freq_vector['\n'] = 0;
	check_sum = 0;
	while (check_sum < 256)
		if (freq_vector[check_sum++] > 0)
			returned_sum = 1;
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
	while (game_board[index] != NULL)
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
	int		flag;
	int		check_sum;

	check_sum = 0;
	game_board_copy = copy_game_board(game_board);
	flag = validate_boarder(game_board_copy);
	if (flag != 0)
		ft_printf("Error:\nGame board is not surrounded by walls\n");
	check_sum += flag;
	flag = validate_unique_game_elements(game_board_copy);
	if (flag != 0)
		ft_printf("Error:\nMultiples unique elements and not allowed elem\n");
	check_sum += flag;
	flag = validate_path_to_end(game_board_copy, game_elements);
	if (flag != 0)
		ft_printf("Error:\nNot all elements on the board are reachable\n");
	check_sum += flag;
	flag = same_size(game_board_copy);
	if (flag != 0)
		ft_printf("Error:\nGame board is not rectangular\n");
	check_sum += flag;
	free_double_array(game_board_copy);
	return (check_sum);
}
