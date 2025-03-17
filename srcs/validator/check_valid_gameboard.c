/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_gameboard.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:15:46 by schiper           #+#    #+#             */
/*   Updated: 2025/03/17 16:27:46 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/game_elements.h"

static int	validate_path_to_end(char **game_board,
		t_game_elements *game_elements, int *apparance_rate_game_elements)
{
	return (0);
}

// validates if the unique game elements conditions is applied to the game board
static int	validate_unique_game_elements(int *apparance_rate_game_elements)
{
	int	check_sum;
	int	returned_sum;

	returned_sum = 0;
	check_sum = apparance_rate_game_elements[START_POINT]
		+ apparance_rate_game_elements[END_POINT];
	if (check_sum != 2)
		returned_sum += 3;
	check_sum += apparance_rate_game_elements[COLLECTIBLE];
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
int	validate_game_board(char **game_board, int *apparance_rate_game_elements,
		t_game_elements *game_elements)
{
	int	valid;

	valid = validate_boarder(game_board)
		+ validate_unique_game_elements(apparance_rate_game_elements)
		+ validate_path_to_end(game_board, game_elements,
			apparance_rate_game_elements);
	return (valid);
}
