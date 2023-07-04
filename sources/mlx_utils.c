/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:13:59 by nihamdan          #+#    #+#             */
/*   Updated: 2023/07/04 19:05:49 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_mlx(t_all *so_long)
{
	so_long->mlx_ptr = mlx_init();
	so_long->wdw_ptr = mlx_new_window(so_long->mlx_ptr,
		 so_long->map_length * 64, so_long->map_size * 64, "so_long");
	so_long->collect_game = count_collectibles(so_long);
	set_img(so_long);
}

void	set_img(t_all *so_long)
{
	so_long->charptr = get_img(so_long->mlx_ptr, so_long->charpath, so_long);
	so_long->wallptr = get_img(so_long->mlx_ptr, so_long->wallpath, so_long);
	so_long->groundptr = get_img(so_long->mlx_ptr, so_long->groundpath, so_long);
	so_long->collectptr = get_img(so_long->mlx_ptr, so_long->collectpath, so_long);
	so_long->exitonptr = get_img(so_long->mlx_ptr, so_long->exitonpath, so_long);
	so_long->exitoffptr = get_img(so_long->mlx_ptr, so_long->exitoffpath, so_long);
}

void	*get_img(void *mlx, char *path, t_all *so_long)
{
	void	*ptr;
	int		i;
	
	ptr = mlx_xpm_file_to_image(mlx, path, &i, &i);
	if (!ptr)
		ft_error("Cannot open xpm \n", so_long);
	return (ptr);
}
int	game_loop(t_all *so_long)
{
	int y;
	int x;
	
	y = -1;
	while (so_long->map[++y])
	{
		x = -1;
		while (++x < so_long->map_length)
		{
			mlx_put_image_to_window(so_long->mlx_ptr, so_long->wdw_ptr, so_long->groundptr, x * 64, y * 64);
			if (so_long->map[y][x] == '1')
				mlx_put_image_to_window(so_long->mlx_ptr, so_long->wdw_ptr, so_long->wallptr, x * 64, y * 64);
			else if (so_long->map[y][x] == 'P')
				mlx_put_image_to_window(so_long->mlx_ptr, so_long->wdw_ptr, so_long->charptr, x * 64, y * 64);
			else if (so_long->map[y][x] == 'C')
				mlx_put_image_to_window(so_long->mlx_ptr, so_long->wdw_ptr, so_long->collectptr, x * 64, y * 64);
			else if (so_long->map[y][x] == 'E' && so_long->collect_game)
				mlx_put_image_to_window(so_long->mlx_ptr, so_long->wdw_ptr, so_long->exitoffptr, x * 64, y * 64);
			else if (so_long->map[y][x] == 'E' && so_long->collect_game == 0)
				mlx_put_image_to_window(so_long->mlx_ptr, so_long->wdw_ptr, so_long->exitonptr, x * 64, y * 64);
		}
	}
	return (0);
}
