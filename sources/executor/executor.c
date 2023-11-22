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

	/*printf("cmd : %s\n", cmd);
	printf("arg 0: %s\n", arg[0]);
	printf("arg 1: %s\n", arg[1]);
	write(g_minishell->stdout, "---\n", 4);
	write(g_minishell->stdout, cmd, ft_strlen(cmd));
	write(g_minishell->stdout, "\n", 1);
	write(g_minishell->stdout, arg, ft_strlen(arg[0]));
	write(g_minishell->stdout, "\n", 1);*/
	/*write(g_minishell->stdout, arg + 1, ft_strlen(arg[1]));
	write(g_minishell->stdout, "\n", 1);
	write(g_minishell->stdout, "---\n", 4);*/
	pid = fork();
	/*if (!strcmp(cmd, "wc"))
		write(g_minishell->stdout, "la\n", 3);*/
	if(pid == -1)
	{
		perror("Erreur fork ");
		return(EXIT_FAILURE);
	}
	else if(pid > 0)
	{
		/*dup2(g_minishell->pipefd[0], g_minishell->pipefd[0]);
		char buf[4060];
		read(g_minishell->pipefd[0], buf, 400);
		write(g_minishell->stdout, &buf, ft_strlen(buf));
		write(g_minishell->stdout, "\n", 1);*/
		waitpid(pid, &status, 0);
		/*write(g_minishell->stdout, "eee\n", 4);*/
	}
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
	builtin(g_minishell, tokens);
	return (EXIT_SUCCESS);
}

int	ft_executor(t_minishell *g_minishell, t_tokens *tokens)
{
	int		i;
	int 	j;
	int		pipe_status;

	g_minishell->re = 0;
	i = 0;
	pipe_status = 1;
	g_minishell->pipe_ct = count_pipe(tokens);
	g_minishell->stdin = dup(0);
	g_minishell->stdout = dup(1);
	if (g_minishell->pipe_ct > 0 && pipe_status)
	{
		pipe(g_minishell->pipefd);
		pipe_status = 0;
	}
	while(tokens[i].str)
	{
		if (tokens[i].REDIR_type == 5)
			dup2(g_minishell->pipefd[0], 0);
		if(tokens[i].type == 2 || tokens[i].type == 3)
		{
			j = i;
			executor_2(g_minishell, tokens, &i, &j);
		}
		else if (tokens[i].type != 2 && tokens[i].type != 3)
			i++;
	}
	close(g_minishell->stdin);
	close(g_minishell->stdout);
	close(g_minishell->pipefd[0]);
	close(g_minishell->pipefd[1]);
	return(EXIT_SUCCESS);
}
