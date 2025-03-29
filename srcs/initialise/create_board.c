/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:17:37 by schiper           #+#    #+#             */
/*   Updated: 2025/03/29 12:46:40 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "game_elements.h"
#include "get_next_line.h"

static char	**realocate_gameboard(char **game_board, int *size)
{
	char	**new_game_board;
	int		new_size;
	int		index;

	index = 0;
	new_size = *size * 2;
	new_game_board = malloc(sizeof(char *) * new_size);
	while (game_board != NULL && index < *size)
	{
		new_game_board[index] = game_board[index];
		index++;
	}
	*size = new_size;
	free(game_board);
	return (new_game_board);
}

int	*populate_freg_vector(char **game_board)
{
	int	i;
	int	index;
	int	*freq_vector;

	freq_vector = malloc(sizeof(int) * 256);
	i = 0;
	while (i < 256)
		freq_vector[i++] = 0;
	index = 0;
	while (game_board[index] != NULL)
	{
		i = 0;
		while (game_board[index][i] != '\0' && game_board[index][i] != '\n')
		{
			freq_vector[(int)game_board[index][i]]++;
			i++;
		}
		index++;
	}
	return (freq_vector);
}

static char	**populate_gameboard(int fd)
{
	char	**game_board;
	int		i;
	char	*line;
	int		size;

	size = 1;
	i = 0;
	game_board = realocate_gameboard(NULL, &size);
	line = get_next_line(fd);
	while (line)
	{
		game_board[i] = line;
		i++;
		if (i == size)
			game_board = realocate_gameboard(game_board, &size);
		line = get_next_line(fd);
	}
	game_board[i] = NULL;
	return (game_board);
}

char	**create_gameboard(int fd)
{
	return (populate_gameboard(fd));
}
