/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:15:25 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/15 14:21:33 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec(const t_shell *shell, char **const env)
{
	if (execve(shell->pathname, shell->argv, env) < 0)
	{
		throw_error((t_shell*)shell, shell->pathname,
					"command not found", CMD_NOT_FOUND);
		return (FAILURE);
	}
	return (SUCCESS);
}

/*
**	Create a new process with fork() where to exec the given args.
*/

int	new_process(t_shell *shell, char **const env)
{
	pid_t	pid;
	int		status;

	status = 0;
	signal(SIGINT, &sigint_fork);
	if ((pid = fork()) < 0)
		return (throw_err_msg("fork() failed"));
	if (pid == 0)
	{
		if (exec(shell, env) < 0)
			exit(FAILURE);
	}
	else
		wait(&status);
	signal(SIGINT, &sigint_core);
	shell->exps.last_exit_status = status;
	return (SUCCESS);
}
