/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:28:00 by nihamdan          #+#    #+#             */
/*   Updated: 2023/05/18 18:03:53 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	index_is_zero(t_list *stack)
{
	while (stack)
	{
		if (stack->index == 0)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	presort_list(t_list *stack)
{
	int		i;
	t_list	*tmp;
	t_list	*current;

	i = 1;
	tmp = stack;
	current = tmp -> next;
	while (!index_is_zero(stack))
	{
		tmp = stack;
		current = tmp -> next;
		while (current)
		{
			while (tmp->index != 0)
				tmp = tmp->next;
			if ((tmp->content > current->content && current->index == 0))
				tmp = current;
			current = current->next;
		}
		tmp -> index = i++;
	}
	return ;
}

int	is_sorted(t_list *stack)
{
	size_t	i;
	t_list	*tmp;

	i = 1;
	tmp = stack;
	if (!tmp)
		return (1);
	while (tmp)
	{
		if (tmp->index != i++)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	**tab;

	a = NULL;
	b = NULL;
	if (!check_arg(argc, argv, 0))
		return (0);
	tab = extract_to_tab(argc, argv);
	a = tab_to_list(a, tab);
	if (!check_double(&a))
		return (0);
	presort_list(a);
	if (!is_sorted(a))
	{
		if (!a)
			return (0);
		else if (ft_lstsize(a) <= 5)
			sort_small_stack(&a, &b);
		else
			sort_big_stack(&a, &b);
	}
	free_list(&a);
	return (0);
}
