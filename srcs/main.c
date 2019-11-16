/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:07:07 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/16 20:27:35 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	shell_leave(t_shell *shell)
{
	ft_strdel(&shell->vars.home);
	// ft_strdel(&shell->vars.path); //unused
	free_env(shell->env, shell->env_idx);
	free_path(shell->path_bin);
	ft_bzero((void*)shell, sizeof(t_shell));
}

static int	init_locale_vars(t_vars *vars, char **const env)
{
	char	*tmp;

	if ((tmp = get_var_content("HOME", env)))
		if (!(vars->home = ft_strdup(tmp)))
		{
			ft_dprintf(STDERR_FILENO,
				"minishell: Error while setting locale vars\n");
			return (-1);
		}
	return (0);
}

static int	shell_init(t_shell *shell, char **env)
{
	if (read(STDIN_FILENO, 0, 0) < 0)
	{
		ft_dprintf(STDERR_FILENO, "stdin not open !\n");
		return (-1);
	}
	ft_bzero((void*)shell, sizeof(t_shell));
	if ((create_env(shell, env)) < 0)
	{
		ft_dprintf(STDERR_FILENO, "minishell: Error while building env\n");
		return (-1);
	}
	if (create_path(env, shell) < 0)
	{
		shell_leave(shell);
		return (-1);
	}
	shell->status = RUNNING;
	if (init_locale_vars(&shell->vars, shell->env) < 0)
		return (-1);
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
