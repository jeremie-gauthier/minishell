/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:42:18 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/08 15:57:12 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	setenv_error(const char *err)
{
	ft_dprintf(STDERR_FILENO, "minishell: setenv: %s\n", err);
	return (-1);
}

int			setenv_builtin(t_shell *shell)
{
	shell->exps.last_exit_status = -1;
	if (shell->argc != 2 && shell->argc != 3)
		return (setenv_error("Wrong number of arguments"));
	if (!ft_isalpha(shell->argv[1][0]))
		return (setenv_error("key must begin with a letter"));
	if (!ft_str_is_alnum(shell->argv[1]))
		return (setenv_error("key must contains alphanumeric characters"));
	if (upsert_env(shell, shell->argv[1], shell->argv[2]) < 0)
		return (setenv_error("failed to insert new entry"));
	shell->exps.last_exit_status = 0;
	return (0);
}
