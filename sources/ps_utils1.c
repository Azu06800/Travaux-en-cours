/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:19:42 by nihamdan          #+#    #+#             */
/*   Updated: 2023/05/18 17:55:33 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_strjoin_modif(char *s1, char *s2, char sep)
{
	size_t	ls1;
	size_t	ls2;
	size_t	ltot;
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	ltot = ls1 + ls2 + 2;
	dst = malloc(sizeof(char) * ltot);
	if (!dst)
		return (NULL);
	ft_memmove(dst, s1, ls1);
	dst[ls1] = sep;
	ft_memmove((dst + ls1) + 1, s2, ls2);
	dst[ltot - 1] = '\0';
	free(s1);
	return (dst);
}

int	get_max_bit(t_list	*stack)
{
	int	max_bit;
	int	list_size;

	max_bit = 0;
	list_size = ft_lstsize(stack);
	while (list_size != 0)
	{
		list_size = list_size >> 1;
		max_bit++;
	}
	return (max_bit);
}

void	free_list(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	if (!(*stack))
		return ;
	while (tmp)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	return ;
}
