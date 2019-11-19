/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:42:18 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/19 11:38:06 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			setenv_builtin(t_shell *shell)
{
	shell->exps.last_exit_status = -1;
	if (shell->argc != 2 && shell->argc != 3)
	{
		ft_dprintf(STDERR_FILENO,"minishell: setenv: Wrong number of arguments\n");
		return (-1);
	}
	if (!ft_isalpha(shell->argv[1][0]))
	{
		ft_dprintf(STDERR_FILENO,"minishell: setenv: key must begin with a letter\n");
		return (-1);
	}
	if (!ft_str_is_alnum(shell->argv[1]))
	{
		ft_dprintf(STDERR_FILENO,
			"minishell: setenv: key must contains alphanumeric characters\n");
		return (-1);
	}
	if (upsert_env(shell, shell->argv[1], shell->argv[2]) < 0)
	{
		ft_dprintf(STDERR_FILENO,"minishell: setenv: failed to insert new entry\n");
		return (-1);
	}
	shell->exps.last_exit_status = 0;
	return (0);
}
