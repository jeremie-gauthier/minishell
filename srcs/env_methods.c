/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_methods.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:22:09 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/08 18:47:55 by jergauth         ###   ########.fr       */
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
