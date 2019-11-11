/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_methods.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:22:09 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/11 19:00:42 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var_content(const char *var, char **const env)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(var);
	i = 0;
	while (env[i] && ft_strncasecmp(var, env[i], len))
		i++;
	if (env[i])
		return (env[i] + len + 1);
	return (NULL);
}

int		realloc_env(t_shell *shell, char ***env)
{
	char	**new_env;
	size_t	i;

	shell->nb_alloc_env++;
	if (!(new_env = malloc(shell->nb_alloc_env * ARR_BUFF * sizeof(char*))))
		return (-1);
	i = 0;
	while (*env[i])
	{
		if (!(new_env[i] = ft_strdup(*env[i])))
		{
			ft_tabdel((void**)new_env, i);
			return (-1);
		}
		i++;
	}
	new_env[i] = NULL;
	*env = new_env;
	shell->env_malloced = 1;
	return (0);
}

int		add_entry_env(t_shell *shell, char **env, char *key, char *value)
{
	if (shell->env_idx >= (shell->nb_alloc_env * ARR_BUFF)
			|| shell->env_malloced == 0)
		if (realloc_env(shell, &env) < 0)
			return (-1);
	if (!(env[shell->env_idx++] = glue_str(key, value, '=')))
		return (-1);
	env[shell->env_idx] = NULL;
	return (0);
}
