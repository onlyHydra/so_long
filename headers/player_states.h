/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_states.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:31:05 by schiper           #+#    #+#             */
/*   Updated: 2025/02/11 14:02:26 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(PLAYER_STATES_H)
# define PLAYER_STATES_H

# define PLAYER_STATE_NUMBER 4

typedef enum bla
{
	STATE_IDLE = 0,
	STATE_WALK = 1,
	STATE_JUMP = 2,
	STATE_FALL = 3,
	STATE_DIE = 4
}	t_player_states;

int	get_state(t_player_states state);

#endif // PLAYER_STATES_H
