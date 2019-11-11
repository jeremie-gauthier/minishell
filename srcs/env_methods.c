/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_methods.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:22:09 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/11 22:29:25 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	On success, returns a pointer to the matching value of var in env else NULL.
*/

char	*get_var_content(const char *var, char *env[ARR_BUFF])
{
	size_t	idx;
	size_t	len;

	idx = get_var_idx(var, env);
	if (idx < 0)
		return (NULL);
	len = ft_strlen(var);
	return (env[idx] + len + 1);
}

/*
**	On success, returns the index of var in env else -1.
*/

size_t	get_var_idx(const char *var, char *env[ARR_BUFF])
{
	size_t	i;
	size_t	len;

	len = ft_strlen(var);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(var, env[i], len) == 0 && env[i][len] == '=')
			return (i);
		i++;
	}
	return (0xDEADBABE);
}

void	free_env(char *env[ARR_BUFF], size_t env_idx)
{
	size_t	i;

	i = 0;
	while (i < env_idx)
	{
		ft_strdel(&env[i]);
		i++;
	}
}

int		recreate_env(t_shell *shell, char **const env)
{
	size_t	i;

	i = 0;
	while (env[i])
	{
		if (!(shell->env[i] = ft_strdup(env[i])))
		{
			shell->env_idx = i;
			free_env(shell->env, shell->env_idx);
			return (-1);
		}
		i++;
	}
	shell->env_idx = i;
	return (0);
}

int		update_entry_env(t_shell *shell, size_t idx, char *key, char *value)
{
	ft_strdel(&shell->env[idx]);
	if (!(shell->env[idx] = glue_str(key, value, '=')))
		return (-1);
	if (ft_strequ(key, "PATH"))
		if (update_path_env(shell->env, shell) < 0)
			return (-1);
	return (0);
}

int		add_entry_env(t_shell *shell, char *key, char *value)
{
	size_t	idx;

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
