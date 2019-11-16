/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:30:53 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/16 15:47:07 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Returns a malloc'ed string corresponding to the file pathname
**	or NULL if the filename is not found.
*/

char	*access_file(const char *path, const char *filename)
{
	char	*pathname;

	if (!(pathname = glue_str(path, filename, '/')))
	{
		ft_dprintf(STDERR_FILENO,"minishell: malloc failed\n");
		return (NULL);
	}
	if (access(pathname, F_OK | X_OK) < 0)
	{
		ft_strdel(&pathname);
		return (NULL);
	}
	return (pathname);
}
