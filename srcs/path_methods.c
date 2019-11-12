/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:15:28 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/12 11:45:29 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_path(char *path_bin[ARR_BUFF])
{
	size_t	i;

	i = 0;
	while (path_bin[i])
	{
		ft_strdel(&path_bin[i]);
		i++;
	}
}

int	create_path_env(char *env[ARR_BUFF], t_shell *shell)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (ft_strncmp(env[i], PATH, 5))
		i++;
	j = 4;
	while (env[i][j++] && shell->path_bin_size < ARR_BUFF)
	{
		if (!(shell->path_bin[shell->path_bin_size++] = ft_strcdup(&env[i][j],
			PATH_DELIMITER)))
		{
			ft_tabdel((void**)shell->path_bin, shell->path_bin_size);
			shell->path_bin_size = 0;
			return (-1);
		}
		while (env[i][j] && env[i][j] != ':')
			j++;
	}
	return (0);
}

int	update_path_env(char *env[ARR_BUFF], t_shell *shell)
{
	free_path(shell->path_bin);
	shell->path_bin_size = 0;
	if ((create_path_env(env, shell)) < 0)
	{
		ft_dprintf(STDERR, "minishell: fail to update env\n");
		return (-1);
	}
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
