/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:06:09 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/06 18:30:41 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		listen_stdin(t_shell *shell, char **env)
{
	char	buf[READ_SIZE];
	size_t	len;
	int		ret;

	ft_printf("{cyan}minishell$>{reset} ");
	while ((ret = read(1, &buf, READ_SIZE)))
	{
		if (ret == READ_SIZE)
			ft_dprintf(2, "argument list too long\n");
		else
		{
			buf[ret] = '\0';
			shell->argv = ft_strsplit(buf, " \t\n");
			len = ft_arrlen((void**)shell->argv);
			if (!(shell->pathname = get_pathname(shell->path_env, shell->argv[0])))
				ft_dprintf(2, "minishell: command not found: %s\n", shell->argv[0]);
			new_process(shell, env);
			ft_strdel(&shell->pathname);
			ft_tabdel((void**)shell->argv, len);
		}
		ft_printf("{cyan}minishell$>{reset} ");
	}
	return (0);
}
