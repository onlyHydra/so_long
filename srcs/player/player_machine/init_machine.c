/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_machine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:41:30 by schiper           #+#    #+#             */
/*   Updated: 2025/02/11 14:46:10 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "player_states.h"

t_state_node	**init_machine(void)
{
	t_state_node	**graph;

	graph = malloc(sizeof(t_state_node) * PLAYER_STATE_NUMBER);
	if (graph == NULL)
		return (NULL);
	graph[0] = new_node("IDLE", 0);
	graph[1] = new_node("WALK", 0);
	graph[2] = new_node("JUMP", 0);
	graph[3] = new_node("FALL", 0);
	graph[4] = new_node("DIE", 0);
	return (graph);
}

void	start_machine(void)
{
	t_state_node	**graph;

	graph = init_machine();
}
