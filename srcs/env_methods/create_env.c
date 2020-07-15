/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:43:11 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/15 12:03:01 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Increment SHLVL if exists or set it to 1 if not
*/

static void	increment_shell_level(t_shell *shell)
{
	char	*shell_lvl_content;
	int		shell_lvl;

	if ((shell_lvl_content = get_var_content("SHLVL", shell->env)))
	{
		shell_lvl = ft_atoi(shell_lvl_content) + 1;
		if ((shell_lvl_content = ft_itoa(shell_lvl)))
		{
			upsert_env(shell, "SHLVL", shell_lvl_content);
			ft_strdel(&shell_lvl_content);
		}
	}
	else
		upsert_env(shell, "SHLVL", "1");
}

static void	default_env(t_shell *shell)
{
	char	cwd[256];

	upsert_env(shell, "SHLVL", "1");
	if (getcwd(cwd, sizeof(cwd)))
		upsert_env(shell, "PWD", cwd);
}

int			create_env(t_shell *shell, char **const env)
{
	size_t	i;

	i = 0;
	while (env[i])
	{
		if (!(shell->env[i] = ft_strdup(env[i])))
		{
			shell->env_idx = i;
			free_env(shell->env, shell->env_idx);
			return (FAILURE);
		}
		i++;
	}
	shell->env_idx = i;
	if (shell->env_idx > 0)
		increment_shell_level(shell);
	else
		default_env(shell);
	return (SUCCESS);
}
