/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:13:36 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/10 14:04:46 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exit_builtin(t_shell *shell)
{
	shell->status = STOPPED;
	if (shell->argv[1])
		shell->exps.last_exit_status = ft_atoi(shell->argv[1]);
	else
		shell->exps.last_exit_status = 0;
	return (SUCCESS);
}
