/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:05:52 by schiper           #+#    #+#             */
/*   Updated: 2025/03/24 13:10:39 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "imports/get_next_line/get_next_line_bonus.h"
#include "so_long.h"

int	main(int argc, char **argv)
{
	int	freg_vector[256];

	if (argc != 2)
	{
		ft_printf("Error:\n Wrong number of arguments\n");
		return (1);
	}
	create_gameboard(argv[1], &freg_vector);
}
