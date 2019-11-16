/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:20:06 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/16 20:28:11 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	update_pwd(t_shell *shell)
{
	char	cwd[256];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		ft_dprintf(STDERR_FILENO, "minishell: getcwd() error\n");
		return (-1);
	}
	if (upsert_env(shell, "PWD", cwd) < 0)
	{
		ft_dprintf(STDERR_FILENO, "minishell: malloc() error\n");
		return (-1);
	}
	return (0);
}

int			cd_builtin(t_shell *shell)
{
	char	*dest;

	if (shell->argc > 2)
	{
		ft_dprintf(2, "minishell: cd: too many arguments\n");
		return (-1);
	}
	dest = shell->argc == 1 ? shell->vars.home : shell->argv[1];
	if (chdir(dest) != 0)
	{
		ft_dprintf(2, "minishell: cd: %s: No such file or directory\n",
			shell->argv[1]);
		return (-1);
	}
	if (update_pwd(shell) < 0)
		return (-1);
	return (0);
}
