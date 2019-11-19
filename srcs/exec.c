/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:15:25 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/19 11:38:06 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec(const t_shell *shell, char **const env)
{
	if (execve(shell->pathname, shell->argv, env) < 0)
	{
		throw_error((t_shell*)shell, shell->pathname);
		return (-1);
	}
	return (0);
}

/*
**	Create a new process with fork() where to exec the given args.
*/

int	new_process(t_shell *shell, char **const env)
{
	pid_t	pid;
	int		status;

	status = 0;
	if ((pid = fork()) < 0)
	{
		ft_printf("fork error\n");
		return (-1);
	}
	if (pid == 0)
	{
		if (exec(shell, env) < 0)
			exit(-1);
	}
	else
		wait(&status);
	shell->exps.last_exit_status = status;
	return (0);
}
