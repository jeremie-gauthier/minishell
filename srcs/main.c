/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:07:07 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/10 15:18:35 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	shell_leave(t_shell *shell)
{
	ft_strdel(&shell->vars.home);
	free_env(shell->env, shell->env_idx);
	free_path(shell->path_bin);
	ft_bzero((void*)shell, sizeof(t_shell));
}

static void	init_locale_vars(t_vars *vars, char **const env)
{
	vars->home = dup_var_content("HOME", env);
}

static void	init_expansions(t_exp *exp)
{
	exp->pid = getpid();
	exp->last_exit_status = SUCCESS;
}

static int	shell_init(t_shell *shell, char **env)
{
	if (read(STDIN_FILENO, 0, 0) < 0)
		return (throw_err_msg("Cannot read stdin"));
	ft_bzero((void*)shell, sizeof(t_shell));
	if ((create_env(shell, env)) < 0)
		return (throw_err_msg("Error while building env"));
	if (create_path(env, shell) < 0)
	{
		shell_leave(shell);
		return (FAILURE);
	}
	shell->status = RUNNING;
	init_expansions(&shell->exps);
	init_locale_vars(&shell->vars, shell->env);
	return (SUCCESS);
}

int			main(int argc, char **argv, char **env)
{
	t_shell	shell;
	int		last_exit_status;

	(void)argc;
	(void)argv;
	if (argc != 1)
		return (throw_err_msg("Wrong number of arguments"));
	if (shell_init(&shell, env) < 0)
		return (FAILURE);
	listen_stdin(&shell);
	last_exit_status = shell.exps.last_exit_status;
	shell_leave(&shell);
	return (last_exit_status);
}
