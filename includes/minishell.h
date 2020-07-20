/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:02:55 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/20 23:19:35 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "types.h"
# include <sys/wait.h>
# include <signal.h>

int			is_accessible(const char *pathname);
char		*access_file(const char *path, const char *filename);
int			new_process(t_shell *shell, char **const env);
int			exec(const t_shell *shell, char **const env);
void		display_prompt(t_shell *shell);
void		listen_stdin(t_shell *shell);
void		free_cmds(t_shell **shell);

/*
**	ERRORS
*/

int			throw_error(t_shell *shell, const char *cmd, const char *err,
						const int exit_status);
int			throw_err_msg(const char *err);

/*
**	SIGNALS
*/

void		sigint_fork(int signum);
void		sigint_core(int signum);

/*
**	EXPANSIONS
*/

int			exp_param(t_shell *shell, char **str);
int			exp_parser(t_shell *shell);
int			exp_tilde(t_shell *shell, char **str);

/*
**	ENV METHODS
*/

char		*get_var_content(const char *var, char **const env);
char		*dup_var_content(const char *var, char *env[ARR_BUFF]);
size_t		get_var_idx(const char *var, char *env[ARR_BUFF]);
char		*get_var_name(const char *str);
size_t		len_env_var(const char *var);
int			upsert_env(t_shell *shell, char *key, char *value);
int			create_env(t_shell *shell, char **const env);
int			copy_env(char *env[ARR_BUFF], char *copy_env[ARR_BUFF],
                  const char **blacklist);
void		free_env(char *env[ARR_BUFF], size_t env_idx);
void    clear_new_env(char *new_env[ARR_BUFF]);
char    **parse_env_opts(size_t argc, char **argv, t_envopts *opts);
void		del_entry_env(t_shell *shell, const char *var);

/*
**	PATH METHODS
*/

void		free_path(char *path_bin[ARR_BUFF]);
int			create_path(char *env[ARR_BUFF], t_shell *shell);
int			reload_path(char *env[ARR_BUFF], t_shell *shell);
char		*get_path(char **path_bin, const char *filename);

/*
**	BUILT-INS
*/

t_builtin	get_builtin(const char *cmd);
int			echo_builtin(t_shell *shell);
int			exit_builtin(t_shell *shell);
int			cd_builtin(t_shell *shell);
int			env_builtin(t_shell *shell);
int			setenv_builtin(t_shell *shell);
int			unsetenv_builtin(t_shell *shell);

#endif
