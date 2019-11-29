/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:41:57 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/19 19:42:49 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_entry_env(t_shell *shell, const char *var)
{
	size_t	idx;

	idx = get_var_idx(var, shell->env);
	if (idx != 0xDEADBABE)
	{
		ft_strdel(&shell->env[idx]);
		while (shell->env[idx + 1])
		{
			shell->env[idx] = shell->env[idx + 1];
			idx++;
		}
		shell->env[idx] = NULL;
		shell->env_idx--;
		if (ft_strequ(var, "PATH"))
			reload_path(shell->env, shell);
	}
}
