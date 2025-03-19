/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:16:55 by schiper           #+#    #+#             */
/*   Updated: 2024/11/12 13:14:46 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(GET_NEXT_LINE_H)
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# if !defined(BUFFER_SIZE)
#  define BUFFER_SIZE 42
# endif // BUFFER_SIZE

char	*ft_resize(char *arr, char *new_data, ssize_t size_new_data,
			ssize_t *total_size);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);
char	*ft_copymem(char *source, char *dest, int c, int n);
char	*get_next_line(int fd);
char	*ft_strcpy(char *dest, char *src);

#endif // GET_NEXT_LINE_H
