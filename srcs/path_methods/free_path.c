/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 22:21:34 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/12 22:21:57 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_path(char *path_bin[ARR_BUFF])
{
	size_t	i;

	i = 0;
	while (path_bin[i])
	{
		ft_strdel(&path_bin[i]);
		i++;
	}
}
