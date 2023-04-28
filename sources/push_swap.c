/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:28:00 by nihamdan          #+#    #+#             */
/*   Updated: 2023/04/28 19:36:01 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//void	push_swap(t_list *a, t_list *b);

int main(int argc, char **argv)
{
	//t_list *a;
	//t_list *b;
	char	**tab;
	int		j;
	
	if (!check_arg(argc, argv))
	{
		printf("Error\n");
		return (0);
	}
	tab = extract_to_tab(argc, argv);
	j = 0;
	while(tab[j])
	{
		printf("%s\n", tab[j]);
		free(tab[j++]);
	}
	free(tab);
	return (0);
}
