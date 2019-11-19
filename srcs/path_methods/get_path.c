/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 22:24:24 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/17 17:05:15 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Iterate through $PATH to get the directory where we can run the command.
*/

char	*get_path(char **path_bin, const char *filename)
{
	char	*pathname;
	size_t	filelen;

	filelen = ft_strlen(filename);
	if (ft_strspn(filename, ".") != filelen
			&& ft_strspn(filename, "/") != filelen)
	{
		while (*path_bin)
		{
			if ((pathname = access_file(*path_bin, filename)))
				return (pathname);
			path_bin++;
		}
	}
	return (NULL);
}
