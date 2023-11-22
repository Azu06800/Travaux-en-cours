/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:27:22 by biaroun           #+#    #+#             */
/*   Updated: 2023/11/22 11:28:41 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    exec_heredoc(t_minishell *g_minishell, t_tokens *tokens)
{
    char    *heredoc;
    int     fd;

    heredoc = ft_heredoc(g_minishell, tokens);
	fd = open(heredoc, O_RDONLY, 0644);
	if (fd == -1)
	{
		perror("Impossible d'ouvrir le fichier");
        exit(EXIT_FAILURE);
	}
	if (dup2(fd, 0) == -1)
	{
	    perror("Erreur lors de la redirection");
        exit(EXIT_FAILURE);
	}
	close(fd);
}
char	*ft_redirect(t_minishell *g_minishell,t_tokens *tokens, int *j)
{
	char	*heredoc;
	int		fd;
	
	heredoc = NULL;
	fd = 0;
	if (tokens[(*j)].type == 1)
	{
		if (tokens[(*j)].REDIR_type == 1) // >>
			redirect_1(tokens, j, &fd);
		else if (tokens[(*j)].REDIR_type == 2) //heredoc
			heredoc = redirect_2(g_minishell,tokens, j, &fd);
		else if (tokens[(*j)].REDIR_type == 3) // <
			redirect_3(tokens, j, &fd);
		else if (tokens[(*j)].REDIR_type == 4) // >
			redirect_4(tokens, j, &fd);
		/*else if (tokens[(*j)].REDIR_type == 5) // |
			redirect_5(g_minishell);*/
	}
	return (heredoc);
}

void	executor_2(t_minishell *g_minishell, t_tokens *tokens, int *i, int *j)
{
	char 	**arg;
	char	*heredoc;
	
	arg = NULL;
	heredoc = NULL;
	arg = get_cmd_arg(tokens, j);
	if (tokens[(*j)].type == 1)
		heredoc = ft_redirect(g_minishell,tokens, j);
	if (g_minishell->pipe_ct > 0)
		dup2(g_minishell->pipefd[1], 1);
	if (tokens[(*i)].type == 3)
		exec_cmd(tokens[(*i)].path_cmd, arg);
	else
		exec_builtin(g_minishell, &tokens[(*i)]);
	*i = *j;
	free(arg);
	if (--g_minishell->pipe_ct <= 0)
		dup2(g_minishell->stdin, 0);
	if (g_minishell->pipe_ct <= 0)
	{
		write(1,"test\n", 5);
		dup2(g_minishell->stdout, 1);
		write(1,"test\n", 5);
	}
	if (heredoc)
		unlink(heredoc);
}
