/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:02:55 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/11 13:40:39 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "types.h"
# include "defines.h"
# include <sys/wait.h>

char		*access_file(const char *path, const char *filename);
int			new_process(const t_shell *shell, char **const env);
int			exec(const t_shell *shell, char **const env);
char		*get_pathname(char **path_bin, const char *filename);
int			listen_stdout(t_shell *shell, char **env);
void		throw_error(char *str);

/*
**	ENV METHODS
*/

char		*get_var_content(const char *var, char **const env);

/*
**	PATH ENV
*/

int			create_path_env(char **const env, t_shell *shell);

/*
**	BUILT-INS
*/

t_builtin	get_builtin(const char *cmd);
int			echo_builtin(t_shell *shell, char **const env);
int			exit_builtin(t_shell *shell, char **const env);
int			cd_builtin(t_shell *shell, char **const env);
int			env_builtin(t_shell *shell, char **const env);

// DEBUG FUNCTIONS
void		test_content_list_output(t_list *elem);

#endif
