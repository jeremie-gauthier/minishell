/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:07:07 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/12 23:33:50 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	shell_leave(t_shell *shell)
{
	free_env(shell->env, shell->env_idx);
	free_path(shell->path_bin);
	ft_bzero((void*)shell, sizeof(t_shell));
}

static int	shell_init(t_shell *shell, char **env)
{
	if (read(0, 0, 0) < 0)
	{
		ft_dprintf(STDERR, "stdin not open !\n");
		return (-1);
	}
	ft_bzero((void*)shell, sizeof(t_shell));
	if ((create_env(shell, env)) < 0)
	{
		ft_dprintf(STDERR, "minishell: Error while building env\n");
		return (-1);
	}
	if (create_path(env, shell) < 0)
	{
		shell_leave(shell);
		return (-1);
	}
	shell->status = RUNNING;
	return (0);
}

int			main(int argc, char **argv, char **env) {
	t_shell	shell;

	(void)argc;
	(void)argv;
	if (shell_init(&shell, env) < 0)
		return (-1);
	listen_stdin(&shell);
	shell_leave(&shell);
	return (0);
}
