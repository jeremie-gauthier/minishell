/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:39:43 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/19 11:37:38 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		env_builtin(t_shell *shell)
{
	ft_printtab(shell->env);
	shell->exps.last_exit_status = 0;
	return (0);
}
