/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 09:59:34 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/29 10:03:33 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		throw_cmd_error(t_shell *shell, const char *str)
{
	shell->exps.last_exit_status = 127;
	ft_dprintf(STDERR_FILENO, "minishell: %s: command not found\n", str);
	return (-1);
}

int		throw_malloc_error(void)
{
	ft_dprintf(STDERR_FILENO, "minishell: malloc() failed\n");
	return (-1);
}
