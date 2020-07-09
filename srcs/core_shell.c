/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:06:09 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/29 10:12:52 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		free_cmds(t_shell **shell)
{
	size_t	len;

	ft_strdel(&(*shell)->pathname);
	len = ft_arrlen((void**)(*shell)->argv);
	ft_tabdel((void**)(*shell)->argv, len);
}

void		display_prompt(void)
{
	char	cwd[256];
	char	*dir;

	if (getcwd(cwd, sizeof(cwd)))
	{
		if ((dir = ft_strrchr(cwd, '/')) && dir != cwd)
			dir++;
		ft_printf("%s%s{reset} ", PROMPT_COLOR, dir);
	}
	else
		ft_printf("%sminishell{reset} ", PROMPT_COLOR);
}

static void	run_cmd(t_shell *shell)
{
	t_builtin	fptr;

	if (exp_parser(shell) == 0)
	{
		if ((fptr = get_builtin(shell->argv[0])))
			fptr(shell);
		else if ((shell->pathname = get_path(shell->path_bin, shell->argv[0])))
			new_process(shell, shell->env);
		else
			throw_error(shell, shell->argv[0], "command not found", CMD_NOT_FOUND);
	}
}

static int	iter_cmds(t_shell *shell, const char *input)
{
	char	**cmds;
	size_t	len_cmds;
	size_t	i;

	if (!(cmds = ft_strsplit(input, ";", &len_cmds)))
		return (-1);
	i = 0;
	while (i < len_cmds)
	{
		if ((shell->argv = ft_strsplit(cmds[i], " \t\n", &shell->argc)))
			run_cmd(shell);
		free_cmds(&shell);
		i++;
	}
	ft_tabdel((void**)cmds, len_cmds);
	return (0);
}

/*
**	The main loop of minishell, where we can send commands.
*/

int			listen_stdin(t_shell *shell)
{
	char	*input;

	display_prompt();
	signal(SIGINT, &sigint_core);
	while (shell->status == RUNNING && get_next_line(STDIN_FILENO, &input) > 0)
	{
		iter_cmds(shell, input);
		ft_strdel(&input);
		if (shell->status == RUNNING)
			display_prompt();
	}
	ft_strdel(&input);
	return (0);
}
