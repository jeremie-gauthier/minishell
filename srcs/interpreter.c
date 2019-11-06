/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:30:53 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/06 11:33:24 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Returns a malloc'ed string corresponding to the file pathname
**	or NULL if the filename is not found.
*/

char	*access_file(const char *filename, const t_list *path_env)
{
	char	*pathname;

	(void)path_env;
	if (!(pathname = ft_strjoin("/bin/", filename)))
	{
		ft_dprintf(2, "minishell: malloc failed\n");
		return (NULL);
	}
	if (access(pathname, F_OK | X_OK) < 0)
	{
		ft_dprintf(2, "minishell: command not found: %s\n", filename);
		ft_strdel(&pathname);
		return (NULL);
	}
	return (pathname);
}
