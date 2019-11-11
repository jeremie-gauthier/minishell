/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:06:09 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/11 17:34:13 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmds(t_shell **shell)
{
	size_t	len;

	ft_strdel(&(*shell)->pathname);
	len = ft_arrlen((void**)(*shell)->argv);
	ft_tabdel((void**)(*shell)->argv, len);
}

void	throw_error(char *str)
{
	ft_dprintf(STDERR, "minishell: %s: command not found\n", str);
}

/*
**	The main loop of minishell, where we can send commands.
*/

int		listen_stdout(t_shell *shell, char **env)
{
	char		*input;
	t_builtin	fptr;

	ft_printf("{cyan}minishell$>{reset} ");
	while (shell->status == RUNNING && get_next_line(STDOUT, &input) > 0)
	{
		if ((shell->argv = ft_strsplit(input, " \t\n", &shell->argc)))
		{
			if ((fptr = get_builtin(shell->argv[0])))
				fptr(shell, env);
			else if ((shell->pathname = get_pathname(shell->path_bin,
				shell->argv[0])))
				new_process(shell, env);
			else
				throw_error(shell->argv[0]);
			free_cmds(&shell);
		}
		ft_strdel(&input);
		if (shell->status == RUNNING)
			ft_printf("{cyan}minishell$>{reset} ");
	}
	ft_strdel(&input);
	return (0);
}
