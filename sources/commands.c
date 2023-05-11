/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:24:33 by nihamdan          #+#    #+#             */
/*   Updated: 2023/05/11 18:35:28 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa (t_list **a, t_list **b)
{
	t_list *tmp;
	
	if (!*b)
		return;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	write(1,"pa\n", 3);
	return;
}

void pb (t_list **a, t_list **b)
{
	t_list *tmp;

	if (!*a)
		return;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	write(1,"pb\n", 3);
	return;
}

void ra (t_list **a)
{
	t_list *tmp;
	t_list *last;
	
	if (!*a)
		return;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	last->next = tmp;
	write(1,"ra\n", 3);
	return;
}
