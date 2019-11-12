/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:40:59 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/12 11:41:15 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		add_entry_env(t_shell *shell, char *key, char *value)
{
	size_t	idx;

	if (value == NULL)
		value = "";
	if ((idx = get_var_idx(key, shell->env)) != 0xDEADBABE)
		return (update_entry_env(shell, idx, key, value));
	if (shell->env_idx >= ARR_BUFF - 1)
	{
		ft_dprintf(STDERR, "minishell: setenv: no space left on env\n");
		return (-1);
	}
	if (!(shell->env[shell->env_idx++] = glue_str(key, value, '=')))
		return (-1);
	shell->env[shell->env_idx] = NULL;
	return (0);
}
