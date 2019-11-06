/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:15:28 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/06 11:35:37 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_path_env(char **const env, t_shell *shell)
{
	size_t	i;
	char	**paths;

	(void)shell;
	i = 0;
	while (ft_strncmp(env[i], PATH, 5))
		i++;
	if (!(paths = ft_strsplit(&env[i][5], ':')))
		return (-1);
	ft_printtab(paths);
	// while (*paths)
	// {
	// 	ft_printf("%s\n", *paths);
	// 	paths++;
	// }
	return (0);
}
