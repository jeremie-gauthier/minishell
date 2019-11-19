/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:13:36 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/19 11:38:06 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exit_builtin(t_shell *shell)
{
	shell->status = STOPPED;
	shell->exps.last_exit_status = 0;
	return (0);
}
