/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:28:00 by nihamdan          #+#    #+#             */
/*   Updated: 2023/05/03 17:33:57 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//void	push_swap(t_list *a, t_list *b);

int main(int argc, char **argv)
{
	t_list *a;
	//t_list *b;
	char	**tab;

	a = NULL;
	if (!check_arg(argc, argv))
	{
		printf("Error\n");
		return (0);
	}
	tab = extract_to_tab(argc, argv);
	a = tab_to_list(a, tab);
	while (a)
	{
		printf("[%ld]\n",*(long *)a->content);
		a = a->next;
	}
	return (0);
}
