/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:04:31 by schiper           #+#    #+#             */
/*   Updated: 2024/11/12 15:19:19 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// Step 1 : OPEN FILE
/// Step 2 : Read chars 1 by 1 until newline
/// Step 3 : Return the read data
/// Step 4 : Re-do 2 and 3s

#include "get_next_line.h"

char	*find_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*resize_buffer(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	line = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!line)
		return (free(buffer), NULL);
	i++;
	ft_strcpy(line, &buffer[i]);
	return (free(buffer), line);
}

char	*read_file(int fd, char *buffer)
{
	ssize_t	bytes_read;
	char	*chuck_read;
	ssize_t	total_bytes;

	chuck_read = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (chuck_read == NULL)
		return (free(buffer), free(chuck_read), NULL);
	bytes_read = 1;
	if (buffer == NULL)
		total_bytes = 0;
	else
		total_bytes = ft_strlen(buffer);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, chuck_read, BUFFER_SIZE);
		buffer = ft_resize(buffer, chuck_read, bytes_read, &total_bytes);
		if ((bytes_read <= 0 && total_bytes == 0) || buffer == NULL)
		{
			free(buffer);
			free(chuck_read);
			return (NULL);
		}
	}
	buffer[total_bytes] = '\0';
	return (free(chuck_read), buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = find_line(buffer);
	buffer = resize_buffer(buffer);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("42_with_nl", O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }
