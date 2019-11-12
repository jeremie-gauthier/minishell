/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:43:11 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/12 11:43:35 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		create_env(t_shell *shell, char **const env)
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
