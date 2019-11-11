/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:20:06 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/11 21:14:26 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		cd_builtin(t_shell *shell)
{
	if (shell->argc > 2)
	{
		ft_dprintf(2, "minishell: cd: too many arguments\n");
		return (-1);
	}
	if (chdir(shell->argv[1]) < 0)
	{
		ft_dprintf(2, "minishell: cd: %s: No such file or directory\n",
			shell->argv[1]);
		return (-1);
	}
	return (0);
}
