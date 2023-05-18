/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:28:17 by nihamdan          #+#    #+#             */
/*   Updated: 2023/05/18 18:30:49 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

void	presort_list(t_list *stack);
void	sort_three(t_list **a);
void	sort_four(t_list **a, t_list **b);
void	sort_five(t_list **a, t_list **b);
void	sort_small_stack(t_list **a, t_list **b);
void	sort_big_stack(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	sa(t_list **a);
void	ra(t_list **a);
void	rra(t_list **a);
void	free_list(t_list **stack);
int		check_arg(int argc, char **argv, int j);
int		check_double(t_list **stack);
int		get_max_bit(t_list	*stack);
int		is_sorted(t_list *stack);
char	*ft_strjoin_modif(char *s1, char *s2, char sep);
char	**extract_to_tab(int argc, char **argv);
t_list	*tab_to_list(t_list *stack, char **tab);

#endif
