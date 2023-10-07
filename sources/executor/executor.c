/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:40:08 by nihamdan          #+#    #+#             */
/*   Updated: 2023/09/26 10:58:4 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin(t_minishell *g_minishell, t_tokens *tokens)
{
	/*int ret;

	ret = 0;*/
	if(ft_strcmp(tokens->str,"echo") == 0)
		ft_echo(g_minishell, tokens);
	else if(ft_strcmp(tokens->str,"cd") == 0)
		ft_cd(g_minishell, tokens);
	else if(ft_strcmp(tokens->str,"pwd") == 0)
		ft_pwd(g_minishell);
	else if(ft_strcmp(tokens->str,"export") == 0)
		ft_export(g_minishell, tokens);
	else if(ft_strcmp(tokens->str,"unset") == 0)
		ft_unset(g_minishell, tokens);
	else if(ft_strcmp(tokens->str,"env") == 0)
		ft_env(g_minishell->envlst, g_minishell);
	else if(ft_strcmp(tokens->str,"exit") == 0)
		ft_exit(g_minishell);
	/*if (ret == 0)
		return(EXIT_SUCCESS);*/
	return(EXIT_SUCCESS);
}

char	**get_cmd_arg(t_tokens *tokens, int *j)
{
	char **arg;
	int counter;
	int tmp;

	counter = 1;
	tmp = *j;
	(*j)++;
	while(tokens[(*j)++].type == 4)
		counter++;
	*j = tmp;
	tmp = 0;
	arg = malloc(sizeof(char*) * (counter + 1));
	if (!arg)
		return (NULL);
	while(counter-- && tokens[(*j)].str)
		arg[tmp++] = tokens[(*j)++].str;
	arg[tmp] = NULL;
	return (arg);
}

int exec_cmd(char *cmd, char **arg)
{
	pid_t 	pid;
	int		status;

	pid = fork();
	if(pid == -1)
	{
		perror("Erreur fork ");
		return(EXIT_FAILURE);
	}
	else if(pid > 0)
		wait(&status);
	else
	{
		if(execve(cmd, arg, NULL) == -1)
			perror("Erreur cmd ");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	exec_builtin(t_minishell *g_minishell, t_tokens *tokens)
{
	pid_t 	pid;
	int		status;

	pid = fork();
	if(pid == -1)
	{
		perror("Erreur fork ");
		return(EXIT_FAILURE);
	}
	else if(pid > 0)
		wait(&status);
	else
	{
		if(builtin(g_minishell, tokens) == 1)
			perror("Erreur cmd ");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_executor(t_minishell *g_minishell, t_tokens *tokens)
{
	int		i;
	int 	j;
	char 	**arg;
	int		stdin;
	int		stdout;
	int 	fd;

	g_minishell->re = 0;
	i = 0;
	arg = NULL;
	while(tokens[i].str)
	{
		if(tokens[i].type == 2 || tokens[i].type == 3)
		{
			stdin = dup(0);
			stdout = dup(1);
			j = i;
			arg = get_cmd_arg(tokens, &j);
			if (tokens[j].type == 1) // a factoriser
			{
				if (tokens[j].REDIR_type == 1) // >>
				{
					fd = open(tokens[j+1].str, O_WRONLY | O_CREAT | O_APPEND, 0644);
					if (fd == -1)
					{
						perror("Impossible d'ouvrir le fichier");
        				exit(EXIT_FAILURE);
					}
					if (dup2(fd, 1) == -1)
					{
						perror("Erreur lors de la redirection");
        				exit(EXIT_FAILURE);
					}
					close(fd);
				}
				else if (tokens[j].REDIR_type == 2) //heredoc
				else if (tokens[j].REDIR_type == 3) // <
				{
					
				}
				else if (tokens[j].REDIR_type == 4) // >
				{
					fd = open(tokens[j+1].str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
					if (fd == -1)
					{
						perror("Impossible d'ouvrir le fichier");
        				exit(EXIT_FAILURE);
					}
					if (dup2(fd, 1) == -1)
					{
						perror("Erreur lors de la redirection");
        				exit(EXIT_FAILURE);
					}
					close(fd);
				}
				else if (tokens[j].REDIR_type == 5) // |
				{

				}
			}
			if (tokens[i].type == 3)
				exec_cmd(tokens[i].path_cmd, arg);
			else
				exec_builtin(g_minishell, &tokens[i]);
			i = j;
			free(arg);
			dup2(stdin, 0);
			dup2(stdout, 1);
			close(stdin);
			close(stdout);
		}
		if (tokens[i].type == 1)//a modifier
			i++;
	}
	return(EXIT_SUCCESS);
}
