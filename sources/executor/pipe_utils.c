/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:33:13 by nihamdan          #+#    #+#             */
/*   Updated: 2023/10/20 17:25:35 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_pipe(t_tokens *tokens)
{
	int i;
	int pipe_count;

	i = 0;
	pipe_count = 0;
	while(tokens[i].str)
	{
		if (tokens[i].REDIR_type == 5)
			pipe_count++;
		i++;
	}
	return (pipe_count);
}

int	check_pipe(t_tokens *tokens, int *j)
{
	int i;

	i = *j;
	while(tokens[++i].str)
	{
		if (tokens[i].REDIR_type == 5)
			return (1);
	}
	return (0);
}