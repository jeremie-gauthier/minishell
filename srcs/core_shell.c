/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:06:09 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/07 21:33:45 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_inputs(t_shell **shell, char **input)
{
	size_t	len;

	ft_strdel(&(*shell)->pathname);
	len = ft_arrlen((void**)(*shell)->argv);
	ft_tabdel((void**)(*shell)->argv, len);
	ft_strdel(input);
}

/*
**	The main loop of minishell, where we can send commands.
*/

int		listen_stdout(t_shell *shell, char **env)
{
	char		*input;
	t_builtin	fptr;

	ft_printf("{cyan}minishell$>{reset} ");
	while (get_next_line(STDOUT, &input) > 0)
	{
		if ((shell->argv = ft_strsplit(input, " \t\n")))
		{
			if ((fptr = get_builtin(shell->argv[0])))
				fptr(shell, env);
			else if ((shell->pathname = get_pathname(shell->path_bin,
				shell->argv[0])))
			{
				new_process(shell, env);
				free_inputs(&shell, &input);
			}
			else
				ft_dprintf(STDERR, "minishell: command not found: %s\n",
					shell->argv[0]);
		}
		//Need input free in an else case
		ft_printf("{cyan}minishell$>{reset} ");
	}
	return (0);
}
