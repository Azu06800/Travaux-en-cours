/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:28:00 by nihamdan          #+#    #+#             */
/*   Updated: 2023/05/11 18:50:48 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	index_is_zero(t_list *stack)
{
	while(stack)
	{
		if(stack->index == 0)
			return (0);
		stack = stack->next;
	}
	return 1;
}

void	presort_list(t_list *stack)
{
	int 	i;
	t_list 	*tmp;
	t_list	*current;

	i = 1;
	tmp = stack;
	current = tmp -> next;
	while (!index_is_zero(stack))
	{
		tmp = stack;
		current = tmp -> next;
		while(current)
		{
			while(tmp->index != 0)
				tmp = tmp->next;
			if((tmp->content > current->content && current->index == 0))
				tmp = current;
			current = current->next;
		}
		tmp -> index = i++;
	}
	return;
}

int main(int argc, char **argv)
{
	t_list *a;
	t_list *b;
	t_list *tmp_a;
	t_list *tmp_b;
	char	**tab;

	a = NULL;
	b = NULL;
	if (!check_arg(argc, argv))
	{
		printf("Error\n");
		return (0);
	}
	tab = extract_to_tab(argc, argv);
	a = tab_to_list(a, tab);
	if(!check_double(a))
	{
		printf("Error double detection\n");
		return (0);
	}
	presort_list(a);
	pb(&a,&b);
	pb(&a,&b);
	pb(&a,&b);
	pa(&a,&b);
	pa(&a,&b);
	ra(&a);
	tmp_a = a;
	tmp_b = b;
	printf("list A\n");
	if (!tmp_a)
			printf("Vide\n");
	while (tmp_a)
	{
		printf("[index :%zu][content :%d]\n",tmp_a->index, tmp_a->content);
		tmp_a = tmp_a->next;
	}
	printf("list B \n");
	if (!tmp_b)
			printf("Vide\n");
	while (tmp_b)
	{
		printf("[index :%zu][content :%d]\n",tmp_b->index, tmp_b->content);
		tmp_b = tmp_b->next;
	}
	return (0);
}
