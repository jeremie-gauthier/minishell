/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:15:28 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/06 17:20:19 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	create_path_env(char **const env, t_shell *shell)
{
	char	**paths;
	t_list	*node;
	size_t	i;

	i = 0;
	while (ft_strncmp(env[i], PATH, 5))
		i++;
	if (!(paths = ft_strsplit(&env[i][5], ":")))
		return (-1);
	while (*paths)
	{
		if (!(node = ft_lstnew_addr((void*)*paths)))
			return (-1);
		ft_lstadd(&shell->path_env, node);
		paths++;
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

char	*get_pathname(const t_list *path_env, const char *filename)
{
	t_list	*current;
	char	*pathname;

	current = (t_list*)path_env;
	while (current)
	{
		if ((pathname = access_file(current->content, filename)))
			return (pathname);
		current = current->next;
	}
	return (NULL);
}
