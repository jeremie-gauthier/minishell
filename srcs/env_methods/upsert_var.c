/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upsert_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:40:59 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/25 09:39:35 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	insert_env(t_shell *shell, char *key, char *value)
{
	if (shell->env_idx >= ARR_BUFF - 1)
	{
		ft_dprintf(STDERR_FILENO, "minishell: setenv: no space left on env\n");
		return (FAILURE);
	}
	if (!(shell->env[shell->env_idx++] = glue_str(key, value, '=')))
		return (throw_err_msg("malloc() failed"));
	shell->env[shell->env_idx] = NULL;
	return (SUCCESS);
}

static int	update_env(t_shell *shell, size_t idx, char *key, char *value)
{
	ft_strdel(&shell->env[idx]);
	if (!(shell->env[idx] = glue_str(key, value, '=')))
		return (throw_err_msg("malloc() failed"));
	return (SUCCESS);
}

int			upsert_env(t_shell *shell, char *key, char *value)
{
	size_t	idx;
	int		ret;

	if (value == NULL)
		value = "";
	if ((idx = get_var_idx(key, shell->env)) != 0xDEADBABE)
		ret = update_env(shell, idx, key, value);
	else
		ret = insert_env(shell, key, value);
	if (ret == 0 && ft_strequ(key, "PATH"))
		ret = reload_path(shell->env, shell);
	return (ret);
}
