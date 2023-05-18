/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:32:52 by nihamdan          #+#    #+#             */
/*   Updated: 2023/05/18 17:59:33 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_big_stack(t_list **a, t_list **b)
{
	int	i;
	int	j;
	int	max_bit;
	int	list_size;

	i = -1;
	max_bit = get_max_bit(*a);
	list_size = ft_lstsize(*a);
	while (++i < max_bit && !is_sorted(*a))
	{
		j = -1;
		while (++j < list_size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (*b)
			pa(a, b);
	}
	return ;
}

void	sort_small_stack(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 1 || is_sorted(*a))
		return ;
	else if (ft_lstsize(*a) == 2)
		ra(a);
	else if (ft_lstsize(*a) == 3)
		sort_three(a);
	else if (ft_lstsize(*a) == 4)
		sort_four(a, b);
	else if (ft_lstsize(*a) == 5)
		sort_five(a, b);
	return ;
}

void	sort_three(t_list **a)
{
	size_t	first;
	size_t	second;
	size_t	third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_four(t_list **a, t_list **b)
{
	while ((*a)->index != 1)
		ra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_list **a, t_list **b)
{
	while ((*a)->index != 1)
		ra(a);
	pb(a, b);
	while ((*a)->index != 2)
		ra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
