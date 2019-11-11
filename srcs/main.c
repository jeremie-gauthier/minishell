/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:07:07 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/11 19:00:49 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	shell_leave(t_shell *shell, char **env)
{
	// ft_printtab(env);
	if (shell->env_malloced)
	{
		size_t i = 0;
		while (i < shell->env_idx)
		{
			ft_printf("%i/%i %s\n",i, shell->env_idx, env[i]);
			ft_strdel(&env[i]);
			i++;
		}
		// free(env);
		// ft_tabdel((void**)env, 1);
	}
	ft_tabdel((void**)shell->path_bin, shell->path_bin_size);
	ft_bzero((void*)shell, sizeof(t_shell));
}

static int	shell_init(t_shell *shell, char **env)
{
	ft_bzero((void*)shell, sizeof(t_shell));
	shell->nb_alloc_bin = 1;
	shell->env_idx = ft_arrlen((void**)env);
	shell->nb_alloc_env = shell->env_idx / ARR_BUFF;
	// if (!(create_env(shell, env)))
	// {
	// 	ft_dprintf(STDERR, "minishell: Error while building env\n");
	// 	return (-1);
	// }
	if (!(shell->path_bin = ft_memalloc(ARR_BUFF * sizeof(char*))))
	{
		ft_dprintf(STDERR, "minishell: Error while building path\n");
		return (-1);
	}
	if (create_path_env(env, shell) < 0)
	{
		shell_leave(shell, env);
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
	listen_stdout(&shell, env);
	shell_leave(&shell, env);
	while (1);
	return (0);
}
