/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:22:48 by schiper           #+#    #+#             */
/*   Updated: 2025/02/10 18:35:37 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(NODE_H)
# define NODE_H

/** State machien node structure
 *
 */
typedef struct s_node
{
	s_node	*next_states;
	char	*name;
	int		condition;
}			t_state_node;

#endif // NODE_H
