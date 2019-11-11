/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:07:07 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/11 13:11:11 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	shell_init(t_shell *shell)
{
	ft_bzero((void*)shell, sizeof(t_shell));
	shell->nb_alloc = 1;
	if (!(shell->path_bin = ft_memalloc(ARR_BUFF * sizeof(char*))))
	{
		ft_dprintf(STDERR, "minishell: Error while building path\n");
		return (-1);
	}
	shell->status = RUNNING;
	return (0);
}

static void	shell_leave(t_shell *shell)
{
	ft_tabdel((void**)shell->path_bin, shell->path_bin_size);
	ft_bzero((void*)shell, sizeof(t_shell));
}

int			main(int argc, char **argv, char **env) {
	t_shell	shell;

	(void)argc;
	(void)argv;
	if (shell_init(&shell) < 0)
		return (-1);
	if (create_path_env(env, &shell) < 0)
	{
		shell_leave(&shell);
		return (-1);
	}
	listen_stdout(&shell, env);
	shell_leave(&shell);
	return (0);
}
