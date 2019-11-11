/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:02:55 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/11 22:29:13 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "types.h"
# include <sys/wait.h>
# include <signal.h>

char		*access_file(const char *path, const char *filename);
int			new_process(const t_shell *shell, char **const env);
int			exec(const t_shell *shell, char **const env);
int			listen_stdout(t_shell *shell);
void		throw_error(char *str);
char		*glue_str(char const *s1, char const *s2, char glue);

/*
**	ENV METHODS
*/

char		*get_var_content(const char *var, char **const env);
size_t		get_var_idx(const char *var, char *env[ARR_BUFF]);
int			add_entry_env(t_shell *shell, char *key, char *value);
int			update_entry_env(t_shell *shell, size_t idx,
				char *key, char *value);
int			recreate_env(t_shell *shell, char **const env);
void		free_env(char *env[ARR_BUFF], size_t env_idx);

/*
**	PATH METHODS
*/

void		free_path(char *path_bin[ARR_BUFF]);
int			create_path_env(char *env[ARR_BUFF], t_shell *shell);
int			update_path_env(char *env[ARR_BUFF], t_shell *shell);
char		*get_pathname(char **path_bin, const char *filename);

/*
**	BUILT-INS
*/

t_builtin	get_builtin(const char *cmd);
int			echo_builtin(t_shell *shell);
int			exit_builtin(t_shell *shell);
int			cd_builtin(t_shell *shell);
int			env_builtin(t_shell *shell);
int			setenv_builtin(t_shell *shell);

// DEBUG FUNCTIONS
void		test_content_list_output(t_list *elem);

#endif
