/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_elements.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:33:22 by schiper           #+#    #+#             */
/*   Updated: 2025/03/17 12:42:58 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(GAME_ELEMENTS_H)
# define GAME_ELEMENTS_H

# define START_POINT 'P'
# define END_POINT 'E'
# define COLLECTIBLE 'C'
# define EMPTY_SPACE '0'
# define WALL '1'

typedef struct s_game_elements
{
	int	start_point_x;
	int	start_point_y;
	int	end_point_x;
	int	end_point_y;
}		t_game_elements;

#endif // GAME_ELEMENTS_H
