/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:34:32 by nihamdan          #+#    #+#             */
/*   Updated: 2023/06/21 12:42:01 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_all *so_long)
{
	int j;
	
	j = -1;
	while (so_long->map[++j])
		free(so_long->map[j]);
	free(so_long->map[j]);
	free(so_long->map);
	return ;
}

void	free_cpy_map(t_all *so_long)
{
	int j;
	
	j = -1;
	while (so_long->cpy_map[++j])
		free(so_long->cpy_map[j]);
	free(so_long->cpy_map[j]);
	free(so_long->cpy_map);
	return ;
}

void	free_all(t_all *so_long)
{
	free_map(so_long);
	free_cpy_map(so_long);
	return ;
}
