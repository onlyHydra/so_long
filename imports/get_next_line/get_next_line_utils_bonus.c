/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:13:10 by schiper           #+#    #+#             */
/*   Updated: 2024/11/12 12:29:51 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_copymem(char *source, char *dest, int c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[c + i] = source[i];
		i++;
	}
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	while (s != NULL && *s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((void *)0);
}

char	*ft_resize(char *arr, char *new_data, ssize_t size_new_data,
		ssize_t *total_size)
{
	char	*new_array;

	if (size_new_data == 0 && *total_size >= 0)
		return (arr);
	if (size_new_data <= 0)
	{
		if (arr != NULL)
			free(arr);
		return (NULL);
	}
	new_array = malloc(sizeof(char) * (*total_size + size_new_data + 1));
	if (new_array == NULL)
	{
		free(arr);
		return (NULL);
	}
	new_array = ft_copymem(arr, new_array, 0, (int)*total_size);
	new_array = ft_copymem(new_data, new_array, *total_size,
			(int)size_new_data);
	new_array[*total_size + size_new_data] = '\0';
	*total_size += size_new_data;
	free(arr);
	return (new_array);
}
