/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:20:06 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/10 15:23:43 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	update_pwd(t_shell *shell)
{
	char	cwd[256];
	char	*owd;

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (throw_err_msg("getcwd() error"));
	if ((owd = dup_var_content("PWD", shell->env)))
	{
		if (upsert_env(shell, "OLDPWD", owd) < 0)
		{
			ft_strdel(&owd);
			return (FAILURE);
		}
		ft_strdel(&owd);
	}
	else if (upsert_env(shell, "OLDPWD", cwd) < 0)
		return (FAILURE);
	if (upsert_env(shell, "PWD", cwd) < 0)
		return (FAILURE);
	return (SUCCESS);
}

int			cd_builtin(t_shell *shell)
{
	char	*dest;

	shell->exps.last_exit_status = FAILURE;
	if (shell->argc > 2)
		return (throw_error(shell, "cd", "too many arguments", FAILURE));
	if (!(dest = shell->argc == 1 ? shell->vars.home : shell->argv[1]))
		return (throw_error(shell, "cd", "No such file or directory", FAILURE));
	if (chdir(dest) != 0)
	{
		ft_dprintf(2, "minishell: cd: %s: No such file or directory\n",
			shell->argv[1]);
		return (FAILURE);
	}
	if (update_pwd(shell) < 0)
		return (FAILURE);
	shell->exps.last_exit_status = SUCCESS;
	return (SUCCESS);
}
