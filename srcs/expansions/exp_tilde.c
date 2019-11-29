/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tilde.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 00:03:58 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/19 21:25:38 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	tilde_replacing(t_shell *shell, char **str,
				char *tilde, const char *var)
{
	char	*tmp;
	char	*content;

	tmp = *str;
	if (!(content = get_var_content(var, shell->env)))
		return (-1);
	if (!(*str = replace_substr(*str, tilde, content)))
		return (-1);
	ft_strdel(&tmp);
	return (0);
}

int		exp_tilde(t_shell *shell, char **str)
{
	char	*tilde;
	size_t	i;

	i = 0;
	while ((tilde = ft_strchr(*str, '~')))
	{
		if (tilde[1] == '/' || tilde[1] == '\0')
			return (tilde_replacing(shell, str, "~", "HOME"));
		if (tilde[1] == '+')
			return (tilde_replacing(shell, str, "~+", "PWD"));
		if (tilde[1] == '-')
			return (tilde_replacing(shell, str, "~-", "OLDPWD"));
	}
	return (0);
}
