/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:17:46 by nihamdan          #+#    #+#             */
/*   Updated: 2023/06/23 19:46:19 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_all	so_long;

	if (check_arg(argc, argv))
		return (EXIT_FAILURE);
	init_so_long(&so_long, argv[1]);
	if (check_map(&so_long))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
