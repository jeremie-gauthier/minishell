/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:02:55 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/06 16:21:04 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "types.h"
# include "defines.h"
# include <sys/wait.h>

char	*access_file(const char *path, const char *filename);
int		new_process(const t_shell *shell, char **const env);
int		exec(const t_shell *shell, char **const env);
char	*get_pathname(const t_list *path_env, const char *filename);
int		listen_stdin(t_shell *shell, char **env);

/*
**	PATH ENV
*/

int		create_path_env(char **const env, t_shell *shell);


// DEBUG FUNCTIONS
void	test_content_list_output(t_list *elem);

#endif
