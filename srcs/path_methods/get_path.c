/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 22:24:24 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/10 14:01:02 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Iterate through $PATH to get the directory where we can run the command.
*/

static char	*search_env_path(char **path_bin, const char *filename)
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

static char	*search_relative_path(const char *filename)
{
	char	cwd[256];
	char	*pathname;

	if (ft_strlen(filename) > 1)
		if (getcwd(cwd, sizeof(cwd)))
			if ((pathname = access_file(cwd, &filename[2])))
				return (pathname);
	return (NULL);
}

static char	*search_absolute_path(const char *filename)
{
	if (ft_strlen(filename) > 1)
		if (is_accessible(filename))
			return (ft_strdup(filename));
	return (NULL);
}

/*
**  Will look for a matching file in the relative, absolute and env paths
*/

char		*get_path(char **path_bin, const char *filename)
{
	char	*pathname;

	pathname = NULL;
	if (filename[0] == '.')
		pathname = search_relative_path(filename);
	else if (filename[0] == '/')
		pathname = search_absolute_path(filename);
	else
		pathname = search_env_path(path_bin, filename);
	return (pathname);
}
