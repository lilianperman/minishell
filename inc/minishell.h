/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:29:54 by liperman          #+#    #+#             */
/*   Updated: 2023/07/01 19:29:56 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "ft_printf.h"
# include "defines.h"
# include "types.h"
# include "env.h"
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/ioctl.h>

extern int	g_global;

// srcs/prompt/
void		init_shell(t_shell *data);
void		launch_prog(t_shell *data);
char		*readline_gets(char *line);
int			only_spaces(char *line);
void		fill_shell(t_shell *data);
int			open_pipe_reds(t_shell *data);
void		close_fds(t_shell *data);
void		free_shell(t_shell *data);
void		executor(t_shell *data);
void		print_executor_error(char *str);

// srcs/parser/
int			isquotes(char c);
int			isdelim(char c);
t_tkn		which_delim(char *delim);
int			scan_line(t_token **lst, char *line);
int			lexer(t_token *lst);

// srcs/env/
t_env		*get_env(char *environ[]);
void		expandvars(char **sentences, t_env *env);
t_string	*path_to_lst(char *path);
int			check_varname(char *key);
int			iscrule(int c, int first);
void		expand_hdoc_var(char **sentence, t_env *env);
void		swap_ptr(char **a, char **b);
char		*get_global(char *var, int size);

// srcs/exec/
void		exec_command(char *comm, char **args, t_shell *data);
char		*prefix_slash(char **str);
int			args_size(char **args);
int			call_execve(char **args, char *path, char **envs);
void		print_execve_error(char *str, int error);

// srcs/sentence/
void		create_sentences(t_env *env, t_token **lst_token, \
				t_sentence **lst_sentence);
int			new_index(char *str, int i);
int			no_quote_size(char *str);
int			quote_size(char *str, char quote);
char		*quotes_removed(char *str, int i, char *new_str);
void		remove_quotes(char **sentences);
char		**tkn_to_sentence(t_token **lst_token);
char		*while_no_quotes(char *str, int i, char *new_str);
char		*remove_hdoc_quotes(char *str);
void		clean_reds_sentences(t_sentence *lst_sentence);

// srcs/builtins/
int			check_export(char *key, char *str);
int			check_unset(char *key);
t_env		*compare_key(t_env *env, char *key);
int			export(int size, char *str[], t_env *env);
void		export_error(char *str);
void		env(t_env *env);
void		print_export(t_env *env);
int			unset(int size, char *str[], t_env **env);
int			echo(char **arg, int fd);
void		ft_exit(char **args, t_shell *data, int size);
int			pwd(int fd);
int			cd(int argc, char **argv, t_shell *data);
t_builtin	isbuiltin(char *comm);
int			call_builtin(char **args, t_shell *data, t_builtin builtin);

// srcs/pipes/
int			counting_pipes(t_token **lst_token);
int			*open_pipe(t_sentence *actual, t_sentence *next);
void		clear_pipe(t_shell *data);

// srcs/redirects/
int			counting_redirects(t_token **lst_token);
int			open_reds(int token, t_sentence *cmd, char *file_name, t_env *env);
int			heredoc(t_sentence *cmd, char *file, t_env *env);
void		error_redir(char *filename);

// srcs/signals
void		default_signals(void);
void		int_handler(int signum);
void		setup_signals(void);

#endif
