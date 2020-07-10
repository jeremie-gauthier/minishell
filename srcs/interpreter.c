/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:30:53 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/10 13:53:08 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_accessible(const char *pathname)
{
	return (access(pathname, F_OK | X_OK) >= 0);
}

/*
**	Returns a malloc'ed string corresponding to the file pathname
**	or NULL if the filename is not found.
*/

char	*access_file(const char *path, const char *filename)
{
	char	*pathname;

	if (!(pathname = glue_str(path, filename, '/')))
	{
		throw_malloc_error();
		return (NULL);
	}
	if (!is_accessible(pathname))
	{
		ft_strdel(&pathname);
		return (NULL);
	}
	return (pathname);
}

