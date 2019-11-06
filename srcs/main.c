/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:07:07 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/06 11:33:06 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **env) {
	t_shell	shell;

	argc=2; //
	if (get_path_env(env, &shell) < 0)
		return (-1);
	if (!(shell.pathname = access_file(argv[0], shell.path_env)))
		return (127);
	new_process(&shell, env);
	ft_strdel(&shell.pathname);
	int len = sizeof(shell.path_env) / sizeof(shell.path_env[0]);
	ft_tabdel((void**)shell.path_env, len);
	return (0);
}
