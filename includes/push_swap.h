/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:28:17 by nihamdan          #+#    #+#             */
/*   Updated: 2023/05/03 16:33:58 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdio.h>//tmp

int 	check_arg(int argc, char **argv);
int 	check_doubles(int argc, char **argv);
char	*ft_strjoin_modif(char *s1, char *s2 , char sep);
char	**extract_to_tab(int argc, char **argv);
t_list	*tab_to_list(t_list *stack, char **tab);

#endif
