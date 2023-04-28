/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:12:16 by nihamdan          #+#    #+#             */
/*   Updated: 2023/04/28 19:35:58 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
			if(i != 0 && (argv[j][i] == '+' || argv[j][i] == '-') && argv[j][i - 1] != ' ')
				return (0);
			if ((!(ft_isdigit(argv[j][i]))) && argv[j][i] != '+' &&  argv[j][i] != '-'
				&& argv[j][i] != ' ')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

char **extract_to_tab(int argc, char **argv)
{
	int		j;
	char	*tmp;
	char	**tab;

	j = 1;
	tmp = NULL;
	tmp = ft_calloc(sizeof(char), ft_strlen(argv[j]) + 1);
	ft_strlcpy(tmp, argv[j], ft_strlen(argv[j]) + 1);
	while(j < argc - 1)
	{
		tmp = ft_strjoin_modif(tmp, argv[j + 1], ' ');
		j++;
	}
	tab = ft_split(tmp, ' ');
	free(tmp);
	return(tab);
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
