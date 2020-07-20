/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:39:43 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/20 18:56:24 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	alloc_unset_opts(size_t argc, char **argv, t_envopts *opts)
{
	size_t	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strequ(argv[i], UNSET_ENV_VAR))
			opts->len_unset_vars++;
		i++;
	}
	if (nb_unset > 0)
		if (!(opts->unset_vars = (char**)ft_memalloc(
								(opts->len_unset_vars + 1) * sizeof(char*))))
			return (FAILURE);
	return (SUCCESS);
}

static char	**parse_opts(size_t argc, char **argv, t_envopts *opts)
{
	size_t	i;
	size_t	n_unset_var;

	n_unset_var = 0;
	i = 1;
	if (alloc_unset_opts(argc, argv, opts) == FAILURE)
		return (NULL);
	while (i < argc && argv[i][0] == '-')
	{
		if (ft_strequ(argv[i], END_OF_ARGS))
			break ;
		if (ft_strequ(argv[i], IGNORE_ENV))
			opts->ignore_env = true;
		else if (ft_strequ(argv[i], UNSET_ENV_VAR))
		{
			i++;
			if (!(opts->unset_vars[n_unset_var] = ft_strdup(argv[i])))
			{
				ft_tabdel((void**)opts->unset_vars, n_unset_var);
				return (NULL);
			}
		}
		i++;
	}
	return (&argv[i]);
}

static void	spawn_child_process(t_shell *shell, char *child_process, char *new_env[ARR_BUFF])
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

static int filter_env(t_shell *shell, char **new_env, t_envopts opts)
{
	size_t	i;

	if (opts.ignore_env)
		return (SUCCESS);
	if (copy_env(shell->env, new_env) < 0)
	{
		throw_err_msg("malloc() error");
		return (FAILURE);
	}
	if (opts->len_unset_vars > 0)
	{
		i = 0;
		while (i < opts->len_unset_vars)
		{
			// unset i elem from copy_env
			opts->unset_vars[i];
			i++;
		}
	}
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
	ft_bzero((void*)new_env, sizeof(char*) * ARR_BUFF);
	if (!(child_process = parse_opts(shell->argc, shell->argv, &opts)))
		return (FAILURE);
	if (filter_env(shell, new_env, opts) < 0)
	{
		ft_tabdel((void**)opts->unset_vars, opts->len_unset_vars);
		return (FAILURE);
	}
	if (*child_process == NULL)
	{
		if (*new_env)
			ft_printtab(shell->env);
		shell->exps.last_exit_status = 0;
	}
	else
	{
		shell->argv = child_process;
		spawn_child_process(shell, *child_process, new_env);
		shell->argv = tmp_argv;
	}
	ft_tabdel((void**)opts->unset_vars, opts->len_unset_vars);
	return (SUCCESS);
}
