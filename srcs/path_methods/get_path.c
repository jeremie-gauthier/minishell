/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 22:24:24 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/12 22:24:52 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Iterate through $PATH to get the directory where we can run the command.
*/

char	*get_path(char **path_bin, const char *filename)
{
	char	*pathname;

	while (*path_bin)
	{
		if ((pathname = access_file(*path_bin, filename)))
			return (pathname);
		path_bin++;
	}
	return (NULL);
}
