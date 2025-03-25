/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:04:50 by schiper           #+#    #+#             */
/*   Updated: 2025/03/25 16:54:29 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(SO_LONG_H)
# define SO_LONG_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>

char	**create_gameboard(char *file_name, int **freg_vector);

void	add_error_message(char *msg);
#endif // SO_LONG_H
