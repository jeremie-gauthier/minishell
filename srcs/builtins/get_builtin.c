/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:38:25 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/07 21:05:49 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_builtin	get_builtin(const char *cmd)
{
	if (ft_strcasecmp(cmd, ECHO) == 0)
		return (&echo_builtin);
	return (NULL);
}
