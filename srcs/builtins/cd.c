/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:20:06 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/09 15:38:17 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	update_pwd(t_shell *shell)
{
	char	cwd[256];
	char	*owd;

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		ft_dprintf(STDERR_FILENO, "minishell: getcwd() error\n");
		return (-1);
	}
	if ((owd = dup_var_content("PWD", shell->env)))
	{
		if (upsert_env(shell, "OLDPWD", owd) < 0)
		{
			ft_strdel(&owd);
			return (-1);
		}
		ft_strdel(&owd);
	}
	else if (upsert_env(shell, "OLDPWD", cwd) < 0)
		return (-1);
	if (upsert_env(shell, "PWD", cwd) < 0)
		return (-1);
	return (0);
}

int			cd_builtin(t_shell *shell)
{
	char	*dest;

	shell->exps.last_exit_status = -1;
	if (shell->argc > 2)
	{
		ft_dprintf(2, "minishell: cd: too many arguments\n");
		return (-1);
	}
	if (!(dest = shell->argc == 1 ? shell->vars.home : shell->argv[1]))
    return throw_error(shell, "cd", "No such file or directory", -1);
	if (chdir(dest) != 0)
	{
		ft_dprintf(2, "minishell: cd: %s: No such file or directory\n",
			shell->argv[1]);
		return (-1);
	}
	if (update_pwd(shell) < 0)
		return (-1);
	shell->exps.last_exit_status = 0;
	return (0);
}
