/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:39:05 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/10 15:21:26 by jergauth         ###   ########.fr       */
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
	if (idx == 0xDEADBABE)
		return (NULL);
	len = ft_strlen(var);
	return (env[idx] + len + 1);
}

char	*dup_var_content(const char *var, char *env[ARR_BUFF])
{
	char	*tmp;

	if (!(tmp = get_var_content(var, env)))
		return (NULL);
	return (ft_strdup(tmp));
}

/*
**	On success, returns the index of var in env else magic code.
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

char	*get_var_name(const char *str)
{
	char	*var;
	size_t	len_var;

	var = NULL;
	len_var = len_env_var(str);
	if (!(var = ft_strndup(str, len_var)))
		return (NULL);
	return (var);
}

/*
**	Returns the length of the env var typed in the shell.
**	Example:
**		"$PATH string string" => 5 {$, P, A, T, H}
*/

size_t	len_env_var(const char *var)
{
	size_t	len;

	len = var[0] == '$' ? 1 : 0;
	while (var[len] && (ft_isalnum(var[len]) ||
			ft_strchr(ENV_ALLOWED_CHARS, var[len])))
		len++;
	return (len);
}
