/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 22:22:24 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/12 22:34:00 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		create_path(char *env[ARR_BUFF], t_shell *shell)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (ft_strncmp(env[i], PATH, 5))
		i++;
	j = 4;
	while (env[i][j++] && shell->path_bin_size < ARR_BUFF)
	{
		if (!(shell->path_bin[shell->path_bin_size++] = ft_strcdup(&env[i][j],
			PATH_DELIMITER)))
		{
			ft_tabdel((void**)shell->path_bin, shell->path_bin_size);
			shell->path_bin_size = 0;
			return (-1);
		}
		while (env[i][j] && env[i][j] != ':')
			j++;
	}
	return (0);
}
