/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:02:55 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/19 11:30:49 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "types.h"
# include <sys/wait.h>
# include <signal.h>

char		*access_file(const char *path, const char *filename);
int			new_process(t_shell *shell, char **const env);
int			exec(const t_shell *shell, char **const env);
int			listen_stdin(t_shell *shell);
void		throw_error(t_shell *shell, char *str);
char		*glue_str(char const *s1, char const *s2, char glue);

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
void		free_env(char *env[ARR_BUFF], size_t env_idx);
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

// DEBUG FUNCTIONS
void		test_content_list_output(t_list *elem);

#endif
