/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_parameter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:51:37 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/19 11:37:04 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	free_vars(char **key, char **value)
{
	ft_strdel(key);
	ft_strdel(value);
	return (-1);
}

int	get_param_key_value(t_shell *shell, const char *param, char **key, char **value)
{
	char	*content;

	if (ft_isalpha(param[1]))
	{
		*key = get_var_name(param);
		if (!(content = get_var_content((*key) + 1, shell->env)))
		{
			ft_dprintf(STDERR_FILENO, "minishell: %s: Undefined variable.\n");
			return (0);
		}
		*value = ft_strdup(content);
	}
	else if (param[1] == '$')
	{
		*key = ft_strdup("$$");
		*value = ft_itoa(shell->exps.pid);
	}
	else if (param[1] == '?')
	{
		*key = ft_strdup("$?");
		*value = ft_itoa(shell->exps.last_exit_status);
	}
	else
	{
		*key = ft_strdup("$");
		*value = ft_strdup("$");
	}
	return (*key != NULL && *value != NULL);
}

static int	exp_replacing(t_shell *shell, char **str, const char *param)
{
	char	*key;
	char	*value;

	key = NULL;
	value = NULL;
	if (!get_param_key_value(shell, param, &key, &value))
		return (free_vars(&key, &value));
	if (!(*str = replace_substr(*str, key, value)))
		return (free_vars(&key, &value));
	free_vars(&key, &value);
	return (0);
}

int		exp_param(t_shell *shell, char **str)
{
	char	*tmp;
	char	*param;
	size_t	i;

	i = 0;
	while ((*str)[i] && (param = ft_strchr(&(*str)[i], '$')))
	{
		tmp = *str;
		if (exp_replacing(shell, str, param) < 0)
		{
			*str = tmp;
			return (-1);
		}
		i = param - tmp + 1;
		ft_strdel(&tmp);
	}
	return (0);
}
