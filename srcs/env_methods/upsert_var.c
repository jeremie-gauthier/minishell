/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upsert_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:40:59 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/29 10:03:56 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	insert_env(t_shell *shell, char *key, char *value)
{
	if (shell->env_idx >= ARR_BUFF - 1)
	{
		ft_dprintf(STDERR_FILENO, "minishell: setenv: no space left on env\n");
		return (-1);
	}
	if (!(shell->env[shell->env_idx++] = glue_str(key, value, '=')))
		return (throw_malloc_error());
	shell->env[shell->env_idx] = NULL;
	return (0);
}

static int	update_env(t_shell *shell, size_t idx, char *key, char *value)
{
	ft_strdel(&shell->env[idx]);
	if (!(shell->env[idx] = glue_str(key, value, '=')))
		return (throw_malloc_error());
	if (ft_strequ(key, "PATH"))
		if (reload_path(shell->env, shell) < 0)
			return (-1);
	return (0);
}

int			upsert_env(t_shell *shell, char *key, char *value)
{
	size_t	idx;

	if (value == NULL)
		value = "";
	if ((idx = get_var_idx(key, shell->env)) != 0xDEADBABE)
		return (update_env(shell, idx, key, value));
	return (insert_env(shell, key, value));
}
