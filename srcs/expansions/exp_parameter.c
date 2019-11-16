/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_parameter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:51:37 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/16 20:32:03 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Returns the length of the env var typed in the shell.
**	Example:
**		"$PATH string string" => 5 {$, P, A, T, H}
*/

static size_t	len_env_var(const char *var)
{
	size_t	len;

	len = var[0] == '$' ? 1 : 0;
	while (var[len] && (ft_isalnum(var[len])
			|| ft_strchr(ENV_ALLOWED_CHARS, var[len])))
		len++;
	return (len);
}

static char	*get_var_name(const char *str)
{
	char	*var;
	size_t	len_var;

	var = NULL;
	len_var = len_env_var(str);
	if (!(var = ft_strndup(str, len_var)))
		return (NULL);
	return (var);
}

static int	var_replacing(t_shell *shell, char **str, char *param)
{
	char	*tmp;
	char	*var;
	char	*content;

	tmp = *str;
	if (!(var = get_var_name(param)))
		return (-1);
	// ft_printf("{RED}%s{RESET}\n", var);
	if (!(content = get_var_content(var + 1, shell->env)))
	{
		ft_dprintf(STDERR_FILENO,"minishell: %s: Undefined variable.\n", var + 1);
		ft_strdel(&var);
		return (-1);
	}
	if (!(*str = replace_substr(*str, var, content)))
	{
		ft_strdel(&var);
		ft_strdel(&content);
		*str = tmp;
		return (-1);
	}
	ft_strdel(&var);
	ft_strdel(&tmp);
	return (0);
}

int			exp_parameter(t_shell *shell, char **str)
{
	char	*param;

	while ((param = ft_strchr(*str, '$')))
	{
		if (ft_isalpha(param[1]))
			if (var_replacing(shell, str, param) < 0)
				return (-1);
	}
	return (0);
}
