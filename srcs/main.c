/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:07:07 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/06 18:34:11 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	del_path_env(void *content, size_t size)
{
	(void)size;
	ft_memdel(&content);
}

int			main(int argc, char **argv, char **env) {
	t_shell	shell;

	(void)argc;
	(void)argv;
	if (create_path_env(env, &shell) < 0)
		return (-1);
	listen_stdin(&shell, env);
	ft_lstdel(&shell.path_env, &del_path_env);
	// while(1);
	return (0);
}
