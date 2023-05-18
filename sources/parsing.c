/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:12:16 by nihamdan          #+#    #+#             */
/*   Updated: 2023/05/18 18:04:07 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_arg(int argc, char **argv, int j)
{
	int	i;

	j = 0;
	if (argc < 2)
		return (0);
	while (argv[++j] && j <= argc - 1)
	{
		i = -1;
		while (argv[j][++i])
		{
			if (i != 0 && (argv[j][i] == '+' || argv[j][i] == '-')
				&& argv[j][i - 1] != ' ')
			{
				write(2, "Error\n", 6);
				return (0);
			}
			if ((!(ft_isdigit(argv[j][i]))) && argv[j][i] != '+'
				&& argv[j][i] != '-' && argv[j][i] != ' ')
			{
				write(2, "Error\n", 6);
				return (0);
			}
		}
	}
	return (1);
}

char	**extract_to_tab(int argc, char **argv)
{
	int		j;
	char	*tmp;
	char	**tab;

	j = 1;
	tmp = NULL;
	tmp = ft_calloc(sizeof(char), ft_strlen(argv[j]) + 1);
	ft_strlcpy(tmp, argv[j], ft_strlen(argv[j]) + 1);
	while (j < argc - 1)
	{
		tmp = ft_strjoin_modif(tmp, argv[j + 1], ' ');
		j++;
	}
	tab = ft_split(tmp, ' ');
	free(tmp);
	return (tab);
}

t_list	*tab_to_list(t_list *stack, char **tab)
{
	long	j;
	long	num;

	j = 0;
	if (!tab)
		return (stack);
	while (tab[j])
	{
		num = ft_atoi(tab[j]);
		ft_lstadd_back(&stack, ft_lstnew(num));
		free(tab[j++]);
	}
	free(tab);
	return (stack);
}

int	check_double(t_list **stack)
{
	t_list	*tmp;
	t_list	*index;

	tmp = *stack;
	index = tmp;
	while (index)
	{
		tmp = index->next;
		while (tmp)
		{
			if ((index->content == tmp->content)
				|| index->content < -2147483648 || index->content > 2147483647)
			{
				write(2, "Error\n", 6);
				free_list(stack);
				return (0);
			}
			tmp = tmp->next;
		}
		index = index->next;
	}
	return (1);
}
