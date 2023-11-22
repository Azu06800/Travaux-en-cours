/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:50:11 by nihamdan          #+#    #+#             */
/*   Updated: 2023/11/11 14:52:41 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect_1(t_tokens *tokens, int *j, int *fd)
{
	*fd = open(tokens[(*j)+1].str, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (*fd == -1)
	{
		perror("Impossible d'ouvrir le fichier");
       	exit(EXIT_FAILURE);
	}
	if (dup2(*fd, 1) == -1)
	{
		perror("Erreur lors de la redirection");
       	exit(EXIT_FAILURE);
	}
	close(*fd);
}

char *redirect_2(t_minishell *g_minishell, t_tokens *tokens, int *j, int *fd)
{
	char *heredoc;
	heredoc = ft_heredoc(g_minishell,tokens+((*j)+1));
	*fd = open(heredoc, O_RDONLY, 0644);
	if (*fd == -1)
	{
		perror("Impossible d'ouvrir le fichier");
       	exit(EXIT_FAILURE);
	}
	if (dup2(*fd, 0) == -1)
	{
		perror("Erreur lors de la redirection");
    	exit(EXIT_FAILURE);
	}
	close(*fd);
	return (heredoc);
}

void	redirect_3(t_tokens *tokens, int *j, int *fd)
{
	*fd = open(tokens[(*j)+1].str, O_RDONLY, 0644);
	if (*fd == -1)
	{
		perror("Impossible d'ouvrir le fichier");
    	exit(EXIT_FAILURE);
	}
	if (dup2(*fd, 0) == -1)
	{
		perror("Erreur lors de la redirection");
    	exit(EXIT_FAILURE);
	}
	close(*fd);
}

void	redirect_4(t_tokens *tokens, int *j, int *fd)
{
	*fd = open(tokens[(*j)+1].str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*fd == -1)
	{
		perror("Impossible d'ouvrir le fichier");
    	exit(EXIT_FAILURE);
	}
	if (dup2(*fd, 1) == -1)
	{
		perror("Erreur lors de la redirection");
    	exit(EXIT_FAILURE);
	}
	close(*fd);
}

/*void	redirect_5(t_minishell *g_minishell)
{
	mettre le fd entrant du pipe
	et checkez le pipe_ct pour verifier si retablissement du pipe sortant
} */
