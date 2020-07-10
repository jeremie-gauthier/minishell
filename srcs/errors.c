/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 09:59:34 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/10 15:15:40 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		throw_error(t_shell *shell, const char *cmd, const char *err,
					const int exit_status)
{
	shell->exps.last_exit_status = exit_status;
	ft_dprintf(STDERR_FILENO, "minishell: %s: %s\n", cmd, err);
	return (FAILURE);
}

int		throw_err_msg(const char *err)
{
	ft_dprintf(STDERR_FILENO, "minishell: %s\n", err);
	return (FAILURE);
}
