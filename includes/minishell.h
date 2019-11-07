/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:02:55 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/07 21:09:11 by jergauth         ###   ########.fr       */
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

/*
**	PATH ENV
*/

int			create_path_env(char **const env, t_shell *shell);

/*
**	BUILT-INS
*/

t_builtin	get_builtin(const char *cmd);
int			echo_builtin(const t_shell *shell, char **const env);

// DEBUG FUNCTIONS
void		test_content_list_output(t_list *elem);

#endif
