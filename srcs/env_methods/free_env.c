/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:42:31 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/12 11:42:43 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
