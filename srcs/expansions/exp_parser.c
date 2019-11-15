/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 00:05:12 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/14 22:04:34 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exp_parser(t_shell *shell)
{
	size_t	i;

	i = 1;
	while (shell->argv[i])
	{
		if (exp_tilde(shell, shell->argv[i]) < 0
				|| exp_parameter(shell, &shell->argv[i]) < 0)
			return (-1);
		// ft_printf("{red}exp_parser: %s{reset}\n", shell->argv[i]);
		// ft_printtab(shell->argv);
		// ft_printf("\n");
		i++;
	}
	// ft_printf("{yellow}END OF PARSER{reset}\n");
	return (0);
}
