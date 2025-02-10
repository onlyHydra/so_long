/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_states.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:31:05 by schiper           #+#    #+#             */
/*   Updated: 2025/02/10 18:31:08 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(PLAYER_STATES_H)
# define PLAYER_STATES_H

enum
{
	STATE_IDLE,
	STATE_WALK,
	STATE_RUN,
	STATE_JUMP,
	STATE_FALL,
	STATE_ATTACK,
	STATE_DEFEND,
	STATE_DIE
};

#endif // PLAYER_STATES_H
