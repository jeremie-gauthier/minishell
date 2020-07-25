/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:39:43 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/25 09:37:40 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	spawn_child_process(t_shell *shell, char *child_process,
								char *new_env[ARR_BUFF])
{
	if ((shell->pathname = get_path(shell->path_bin, child_process)))
	{
		if (new_process(shell, new_env) < 0)
			shell->exps.last_exit_status = CMD_NOT_FOUND;
		else
			shell->exps.last_exit_status = SUCCESS;
	}
	else
		shell->exps.last_exit_status = CMD_NOT_FOUND;
}

static int	filter_env(t_shell *shell, char **new_env, t_envopts *opts)
{
	if (opts->ignore_env)
		return (SUCCESS);
	if (copy_env(shell->env, new_env, (const char**)opts->unset_vars) < 0)
	{
		throw_err_msg("malloc() error");
		return (FAILURE);
	}
	ft_tabdel((void**)opts->unset_vars, opts->len_unset_vars);
	return (SUCCESS);
}

static void	env_builtin_action(t_shell *shell, char **child_process,
								char **new_env)
{
	char	**tmp_argv;

	tmp_argv = shell->argv;
	if (*child_process == NULL)
	{
		if (*new_env)
			ft_printtab(new_env);
		shell->exps.last_exit_status = 0;
	}
	else
	{
		shell->argv = child_process;
		spawn_child_process(shell, *child_process, new_env);
		shell->argv = tmp_argv;
	}
}

int			env_builtin(t_shell *shell)
{
	t_envopts	opts;
	char		*new_env[ARR_BUFF];
	char		**child_process;

	ft_bzero((void*)&opts, sizeof(t_envopts));
	ft_bzero((void*)new_env, sizeof(char*) * ARR_BUFF);
	if (!(child_process = parse_env_opts(shell->argc, shell->argv, &opts)))
		return (FAILURE);
	if (filter_env(shell, new_env, &opts) < 0)
	{
		ft_tabdel((void**)opts.unset_vars, opts.len_unset_vars);
		return (FAILURE);
	}
	env_builtin_action(shell, child_process, new_env);
	clear_new_env(new_env);
	return (SUCCESS);
}
