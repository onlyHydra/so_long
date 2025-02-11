/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:22:48 by schiper           #+#    #+#             */
/*   Updated: 2025/02/11 13:36:01 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(NODE_H)
# define NODE_H

# include "common_headers.h"
/** State machien node structure
 *
 */
typedef struct s_node
{
	t_state_node	*next_states;
	char			*name;
	int				condition;
}					t_state_node;

/** Create a new node
 *
 * @param name
 * @param condition
 * @return t_state_node*
 */
t_state_node		*new_node(char *name, int condition);

/** Add a new node to the list
 *
 * @param node
 * @param name
 * @param condition
 */
void				add_node(t_state_node *node, char *name, int condition);

#endif // NODE_H
