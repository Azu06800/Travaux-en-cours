/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:12:16 by nihamdan          #+#    #+#             */
/*   Updated: 2023/04/27 19:51:16 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	j = 1;
	if (argc < 2)
		return (0);
	while (argv[j] && j <= argc - 1)
	{
		i = 0;
		while (argv[j][i])
		{
			if ((!(ft_isdigit(argv[j][i]))) && argv[j][i] != '+' &&  argv[j][i] != '-'
				&& argv[j][i] != ' ')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
int check_doubles(int argc, char **argv)
{
	int i;
	int j;

	while (argv[j] && j <= argc - 1)
	{
		i = 0;
		while (argv[j][i])
		{
			if (!argv[j][i] != ' ')
				i++;
		}
		j++;
	}

}

int check_doubles_split(int argc, char **argv, char **split)
{
	int j;

}
