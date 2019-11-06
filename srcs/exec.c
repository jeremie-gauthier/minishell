/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:15:25 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/06 14:13:22 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec(const t_shell *shell, char **const env)
{
	if (execve(shell->pathname, shell->argv, env) < 0)
		ft_printf("execve error\n");
	return (1);
}

/*
**	Create a new process with fork() where to exec the given args.
*/

int	new_process(const t_shell *shell, char **const env)
{
	pid_t	pid;

	if ((pid = fork()) < 0)
	{
		ft_printf("fork error\n");
		return (-1);
	}
	if (pid == 0)
		exec(shell, env);
	else
		wait(NULL);
	return (0);
}
