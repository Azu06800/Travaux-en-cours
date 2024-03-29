/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:41:09 by biaroun           #+#    #+#             */
/*   Updated: 2023/11/11 19:24:25 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//------------------INCLUDES------------------//

# include <stdio.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/signal.h>

# define BUFFER_SIZE 1000
//-------------------STRUCT-------------------//

typedef struct s_tokens
{
	char				*str;

	int					spcecho;

	int					type; // 1 = REDIR, 2 = bultins, 3 = cmd, 4 = arg, 5 = fail
	int					REDIR_type; //1 = >>, 2 = <<, 3 = <, 4 = >, 5 = |
	char				*opt;
	int					dquote;

	char				*path_cmd;

}				t_tokens;

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}				t_env;

typedef struct s_minishell
{
	t_env		*envlst;
	t_tokens	*tokens;
	char		**builtins;
	char		**PATH;
	int			pipe_ct;
	int			pipefd[2];
	int			stdin;
	int			stdout;

	int			re;
}				t_minishell;

//-------------------LEXER-------------------//
	//quote
t_tokens	*remove_quotes(t_tokens *tokens);
t_tokens	*join_quotes(t_tokens *tokens);
void		free_tokens(t_tokens *tokens);
int			dquote_or_squote(char quote);
	//is
int				ft_isspace(int c);
int				ft_issep(int c);
int				ft_isquote(int c);
int				ft_isfle(int c);
int				ft_isspcable(int c);
	//malloc split
size_t			cpt_quote(char *s);
size_t			cpt_word(char *str, int a);
size_t			ft_cptword(char *args);
	//sep
char			*ft_remove_spcqu(char *arg);
char			*ft_add_spcqu(char *arg);
char			*ft_remove_spc(char *arg);
char			*ft_add_spc(char *arg);
char			*ft_remove_quotes(char *str);
char			*ft_add_spcqu(char *arg);
char			*ft_rmspc(char *arg);
	//split
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
void			*ft_memcpy(void *dst, const void *src, size_t n);
t_tokens		*ft_lexer(char *args);
void			ft_lasttoken(char **token);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
int				is_arrow(char *token);
char			*concat_tokens(char *token1, char *token2);
void			compact_array(char **token, int j, int i);
void			concat_arrow(char **token);
char			**tokentostr(t_tokens *token);

//-------------------PARSE-------------------//
void			init_minishell(t_minishell *g_minishell, t_env *envlst);
void			parse_tokens(t_tokens *tokens, t_minishell *mini);
void			get_envlst(char **envp, t_env *envlst);
int				cmd_abs_exists(t_tokens *token);
void    		parse_redir_token(t_tokens *tokens, int i);
int				find_cmd(t_minishell *g_minishell, int cmd);
char			*get_value(char	*envp);
char			*get_name(char	*envp);

//--------------------TOOLS--------------------//
char			*expander(t_tokens tokens, t_env *env, t_minishell *mini);
char   			*no_expand(char *str);
void    		ft_expander(t_tokens *tokens, t_env *env, t_minishell *mini);
char			*ft_heredoc(t_minishell *mini, t_tokens *tokens);

//--------------------CMD--------------------//
void			ft_cd(t_minishell *minishell, t_tokens *tokens);
void			ft_clear(t_minishell *g_minishell);
void			ft_echo(t_minishell *g_minishell, t_tokens *tokens);
void			ft_env(t_env *envlst, t_minishell *g_minishell);
void			ft_exit(t_minishell *g_minishell);
void			ft_export(t_minishell *minishell, t_tokens *tokens);
void			ft_history(t_minishell *g_minishell);
void			ft_pwd(t_minishell *g_minishell);
int				is_identifier(char *str);
void			ft_unset(t_minishell *minishell, t_tokens *tokens);
int				ft_validator(t_tokens *tokens);

//-------------------EXEC-------------------//
void			exec_heredoc(t_minishell *g_minishell, t_tokens *tokens);
int				ft_executor(t_minishell *g_minishell,t_tokens *tokens);
void			executor_2(t_minishell *g_minishell, t_tokens *tokens, int *i, int *j);
char			*ft_redirect(t_minishell *g_minishell,t_tokens *tokens, int *j);
void			redirect_1(t_tokens *tokens, int *j, int *fd);
char 			*redirect_2(t_minishell *g_minishell, t_tokens *tokens, int *j, int *fd);
void			redirect_3(t_tokens *tokens, int *j, int *fd);
void			redirect_4(t_tokens *tokens, int *j, int *fd);
//void			redirect_5(t_tokens *tokens, int *j, int *fd);
int				count_pipe(t_tokens *tokens);
int				builtin(t_minishell *g_minishell, t_tokens *tokens);
char			**get_cmd_arg(t_tokens *tokens, int *j);
int 			exec_cmd(char *cmd, char **arg);
int				exec_builtin(t_minishell *g_minishell, t_tokens *tokens);
int				check_pipe(t_tokens *tokens, int *j);


//-------------------UTILS-------------------//
int				ft_random(void);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_onlyspace(char *str);
int				ft_cinstr(char *str, char c);
size_t			ft_strlen(const char *str);
void			ft_putstr_fd(char *str, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strchr(char *s, int c);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char 			*ft_strstr(const char *haystack, const char *needle);
char			*get_env_value(char *name, t_env *envlst);
int				ft_atoi(const char *str);
char			*ft_strjoin_path(char const *s1, char const *s2);
char			*ft_itoa(int n);
void    		free_tab(char **tab);
	//lst
t_env			*ft_lstlast(t_env	*lst);
void			ft_lstadd_front(t_env *alst, t_env *n);
void			ft_lstadd_back(t_env *alst, t_env *n);
t_env			*ft_lstnew(char *name, char *value);
void			free_lsts(t_env *a, t_env *b);

//-------------------ERROR-------------------//
int				error_quote(char *str);
int				err_unclosed_quote(char *str);

#endif

