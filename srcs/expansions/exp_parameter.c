/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_parameter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:51:37 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/08 17:55:44 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	free_vars(char **key, char **value)
{
	ft_strdel(key);
	ft_strdel(value);
	return (-1);
}

static void	set_key_value(char **ptrkey, char **ptrvalue,
						char *key, char *value)
{
	*ptrkey = key;
	*ptrvalue = value;
}

int			get_param_key_value(t_shell *shell, const char *param,
								char **key, char **value)
{
	char	*content;

	if (ft_isalpha(param[1]))
	{
		*key = get_var_name(param);
		if (!(content = get_var_content(*key + 1, shell->env)))
		{
			ft_dprintf(STDERR_FILENO,
				"minishell: %s: Undefined variable.\n", *key + 1);
			return (0);
		}
		*value = ft_strdup(content);
	}
	else if (param[1] == '$')
		set_key_value(key, value, ft_strdup("$$"), ft_itoa(shell->exps.pid));
	else if (param[1] == '?')
		set_key_value(key, value, ft_strdup("$?"),
			ft_itoa(shell->exps.last_exit_status));
	else
		set_key_value(key, value, ft_strdup("$"), ft_strdup("$"));
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

int			exp_param(t_shell *shell, char **str)
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
