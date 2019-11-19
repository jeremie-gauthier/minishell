/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 22:23:24 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/19 19:43:21 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	reload_path(char *env[ARR_BUFF], t_shell *shell)
{
	free_path(shell->path_bin);
	shell->path_bin_size = 0;
	if ((create_path(env, shell)) < 0)
	{
		ft_dprintf(STDERR_FILENO,"minishell: fail to update env\n");
		return (-1);
	}
	return (0);
}
