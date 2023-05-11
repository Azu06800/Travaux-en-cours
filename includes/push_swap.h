/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:28:17 by nihamdan          #+#    #+#             */
/*   Updated: 2023/05/11 18:34:11 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdio.h>//tmp

void	presort_list(t_list *stack);
void 	pa (t_list **a, t_list **b);
void 	pb (t_list **a, t_list **b);
void 	ra (t_list **a);
int 	check_arg(int argc, char **argv);
int		check_double(t_list *stack);
char	*ft_strjoin_modif(char *s1, char *s2 , char sep);
char	**extract_to_tab(int argc, char **argv);
t_list	*tab_to_list(t_list *stack, char **tab);

#endif
