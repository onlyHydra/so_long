/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:32:47 by schiper           #+#    #+#             */
/*   Updated: 2025/02/11 13:41:06 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

t_state_node	*new_node(char *name, int condition)
{
	t_state_node	*node;

	node = malloc(sizeof(t_state_node));
	if (node == NULL)
		return (NULL);
	node->name = name;
	node->condition = condition;
	return (node);
}
