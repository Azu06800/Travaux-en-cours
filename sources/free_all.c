/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:34:32 by nihamdan          #+#    #+#             */
/*   Updated: 2023/07/04 19:01:13 by nihamdan         ###   ########.fr       */
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
void	ft_error(char *error, t_all *so_long)
{
	ft_printf("%s", error);
	free_all(so_long);
	exit(1);
}

int	ft_exit(t_all *so_long)
{
	free_all(so_long);
	mlx_destroy_window(so_long->mlx_ptr, so_long->wdw_ptr);
	exit(0);
	return (0);
}
