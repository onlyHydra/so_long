/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_states.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:28:41 by schiper           #+#    #+#             */
/*   Updated: 2025/02/11 14:11:14 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(GAME_STATES_H)
# define GAME_STATES_H

# define GAME_STATE_NUMBER 4

typedef enum bla
{
	STATE_INIT,
	STATE_MENU,
	STATE_GAME,
	STATE_EXIT
}	t_game_states;

#endif // GAME_STATES_H
