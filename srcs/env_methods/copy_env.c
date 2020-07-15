/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:10:05 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/15 15:28:22 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			copy_env(char *env[ARR_BUFF], char *copy_env[ARR_BUFF])
{
	size_t	i;

	i = 0;
	while (env[i] && i < ARR_BUFF)
	{
		if (!(copy_env[i] = ft_strdup(env[i])))
		{
			free_env(copy_env, i);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}
