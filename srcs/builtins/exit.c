/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:13:36 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/11 13:20:33 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int		exit_builtin(t_shell *shell, char **const env)
{
	(void)env;
	shell->status = STOPPED;
	return (0);
}
