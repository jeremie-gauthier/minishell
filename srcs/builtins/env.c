/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:39:43 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/15 16:31:07 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**parse_opts(size_t argc, char **argv, t_envopts *opts)
{
	size_t	i;

	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		if (ft_strequ(argv[i], "--"))
			break ;
		if (ft_strequ(argv[i], "-i"))
			opts->ignore_env = true;
		i++;
	}
	return (&argv[i]);
}

static void	spawn_child_process(t_shell *shell, char *child_process)
{
	if ((shell->pathname = get_path(shell->path_bin, child_process)))
	{
		if (new_process(shell, shell->env) < 0)
			shell->exps.last_exit_status = CMD_NOT_FOUND;
		else
			shell->exps.last_exit_status = SUCCESS;
	}
	else
		shell->exps.last_exit_status = CMD_NOT_FOUND;
}

static int filter_env(t_shell *shell, char **new_env, t_envopts opts)
{
	// char	*new_env[ARR_BUFF];
	(void)shell;
	(void)new_env;
	if (opts.ignore_env)
		return (FAILURE);
	if (copy_env(shell->env, new_env) < 0)
	{
		throw_err_msg("malloc() error");
		return (FAILURE);
	}
	// remove all -u
	return (SUCCESS);
}

int			env_builtin(t_shell *shell)
{
	t_envopts	opts;
	char		*new_env[ARR_BUFF];
	char		**child_process;
	char		**tmp_argv;

	tmp_argv = shell->argv;
	ft_bzero((void*)&opts, sizeof(t_envopts));
	child_process = parse_opts(shell->argc, shell->argv, &opts);
	if (filter_env(shell, new_env, opts) < 0)
		return (FAILURE);
	// if (opts.ignore_env)
	// 	new_env = NULL;

	
	if (*child_process == NULL)
	{
		if (*new_env)
			ft_printtab(new_env);
		shell->exps.last_exit_status = 0;
	}
	else
	{
		shell->argv = child_process;
		spawn_child_process(shell, *child_process);
		shell->argv = tmp_argv;
	}
	return (SUCCESS);
}
