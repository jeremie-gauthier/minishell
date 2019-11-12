/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:41:29 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/12 11:41:44 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		update_entry_env(t_shell *shell, size_t idx, char *key, char *value)
{
	ft_strdel(&shell->env[idx]);
	if (!(shell->env[idx] = glue_str(key, value, '=')))
		return (-1);
	if (ft_strequ(key, "PATH"))
		if (update_path_env(shell->env, shell) < 0)
			return (-1);
	return (0);
}
