/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:15:28 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/07 20:16:07 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	create_path_env(char **const env, t_shell *shell)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (ft_strncmp(env[i], PATH, 5))
		i++;
	j = 4;
	while (env[i][j++])
	{
		if (!(shell->path_bin[shell->path_bin_size++] = ft_strcdup(&env[i][j],
			PATH_DELIMITER)))
		{
			ft_tabdel((void**)shell->path_bin, shell->path_bin_size);
			shell->path_bin_size = 0;
			free(shell->path_bin);
			shell->path_bin = NULL;
			return (-1);
		}
		while (env[i][j] && env[i][j] != ':')
			j++;
	}
	return (0);
}

int	update_path_env(const char *pathname, t_shell *shell)
{
	(void)pathname;
	(void)shell;
	return (0);
}

/*
**	Iterate through $PATH to get the directory where we can run the command.
*/

char	*get_pathname(char **path_bin, const char *filename)
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
