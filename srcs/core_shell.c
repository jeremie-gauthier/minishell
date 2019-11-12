/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:06:09 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/13 00:07:13 by jergauth         ###   ########.fr       */
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

static void	run_cmd(t_shell *shell)
{
	t_builtin	fptr;

	//faire appel a exp_parser.c

	if ((fptr = get_builtin(shell->argv[0])))
		fptr(shell);
	else if ((shell->pathname = get_path(shell->path_bin,
		shell->argv[0])))
		new_process(shell, shell->env);
	else
		throw_error(shell->argv[0]);
	free_cmds(&shell);
}

/*
**	The main loop of minishell, where we can send commands.
*/

int		listen_stdin(t_shell *shell)
{
	char		*input;

	ft_printf("{cyan}minishell$>{reset} ");
	while (shell->status == RUNNING && get_next_line(STDIN, &input) > 0)
	{
		if ((shell->argv = ft_strsplit(input, " \t\n", &shell->argc)))
			run_cmd(shell);
		ft_strdel(&input);
		if (shell->status == RUNNING)
			ft_printf("{cyan}minishell$>{reset} ");
	}
	ft_strdel(&input);
	return (0);
}
