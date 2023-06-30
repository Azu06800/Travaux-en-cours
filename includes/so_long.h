/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:03:26 by nihamdan          #+#    #+#             */
/*   Updated: 2023/06/30 04:02:23 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include "../libft/libft.h"

typedef struct s_all
{
	int		map_size;
	int		collectibles;
	int 	exit_count;
	int 	position_count;
	int 	collectible_count;
	int		flag_map;
	char	**map;
	char	**cpy_map;

} t_all;

int		check_arg(int argc, char **argv);
int		is_rectangle(t_all *so_long);
int		is_closed(t_all *so_long);
int		check_path(t_all *so_long);
int		check_map(t_all *so_long);
int		check_map_specials(t_all *so_long);
int		map_format(t_all *so_long);
int		count_collectibles(t_all *so_long);

size_t	ft_strlen_modif(char *s);

void	map_size(t_all *so_long, char *argv);
void	init_map(t_all *so_long, char *argv);
void	cpy_map(t_all *so_long, char *argv);
void	map_fill(t_all *so_long, int j, int i , int *exit);
void	map_fill2(t_all *so_long, int j, int i , int *exit);
void	free_all(t_all *so_long);
void	init_so_long(t_all *so_long, char *argv);

#endif
