/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 00:05:12 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/19 11:05:26 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exp_parser(t_shell *shell)
{
	size_t	i;

	i = 1;
	while (shell->argv[i])
	{
		if (exp_tilde(shell, &shell->argv[i]) < 0
				|| exp_param(shell, &shell->argv[i]) < 0)
			return (-1);
		i++;
	}
	return (0);
}
