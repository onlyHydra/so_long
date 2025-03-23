/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:17:37 by schiper           #+#    #+#             */
/*   Updated: 2025/03/19 12:56:19 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/game_elements.h"
#include "imports/get_next_line/get_next_line.h"

static char	**realocate_gameboard(char **game_board, int *size)
{
	char	**new_game_board;
	int		new_size;
	int		index;

	index = 0;
	new_size = *size * 2;
	new_game_board = malloc(sizeof(char *) * new_size);
	while (index < size)
	{
		new_game_board[index] = game_board[index];
		free(game_board[index]);
		index++;
	}
	free(game_board);
	return (new_game_board);
}

static char	**populate_gameboard(int fd)
{
	char	**game_board;
	int		i;
	char	*line;
	int		size;

	size = 1;
	i = 0;
	game_board = realocate_game_board(NULL, &size);
	line = get_next_line(fd);
	while (line)
	{
		game_board[i] = ft_strdup(line);
		i++;
		if (i == size)
			game_board = realocate_gameboard(game_board, &size);
		line = get_next_line(fd);
	}
	game_board[i] = NULL;
	return (game_board);
}

char	**create_gameboard(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\n", 2);
		return (NULL);
	}
	return (populate_gameboard(fd));
}
