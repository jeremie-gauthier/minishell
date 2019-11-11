/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:02:55 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/11 18:59:26 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "types.h"
# include "defines.h"
# include <sys/wait.h>
# include <signal.h>

char		*access_file(const char *path, const char *filename);
int			new_process(const t_shell *shell, char **const env);
int			exec(const t_shell *shell, char **const env);
int			listen_stdout(t_shell *shell, char **env);
void		throw_error(char *str);
char		*glue_str(char const *s1, char const *s2, char glue);

/*
**	ENV METHODS
*/

char		*get_var_content(const char *var, char **const env);
int			add_entry_env(t_shell *shell, char **env, char *key, char *value);
int			realloc_env(t_shell *shell, char ***env);

/*
**	PATH METHODS
*/

int			create_path_env(char **const env, t_shell *shell);
char		*get_pathname(char **path_bin, const char *filename);

/*
**	BUILT-INS
*/

t_builtin	get_builtin(const char *cmd);
int			echo_builtin(t_shell *shell, char **const env);
int			exit_builtin(t_shell *shell, char **const env);
int			cd_builtin(t_shell *shell, char **const env);
int			env_builtin(t_shell *shell, char **const env);
int			setenv_builtin(t_shell *shell, char **const env);

// DEBUG FUNCTIONS
void		test_content_list_output(t_list *elem);

#endif
