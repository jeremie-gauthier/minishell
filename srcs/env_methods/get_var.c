/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:39:05 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/12 11:39:42 by jergauth         ###   ########.fr       */
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
