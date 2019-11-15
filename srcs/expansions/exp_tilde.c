/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tilde.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 00:03:58 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/13 21:56:34 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	home_replacing(t_shell *shell, char *str, char *tilde)
{
	(void)shell;
	(void)str;
	(void)tilde;
	return (0);
}

static int	pwd_replacing(t_shell *shell, char *str, char *tilde)
{
	(void)shell;
	(void)str;
	(void)tilde;
	return (0);
}

//traiter le cas de l'expansion `~` (remplacer par $HOME =>
//	https://www.gnu.org/software/bash/manual/html_node/Tilde-Expansion.html#Tilde-Expansion)
int		exp_tilde(t_shell *shell, char *str)
{
	char	*tilde;
	size_t	i;

	i = 0;
	if ((tilde = ft_strchr(str, '~')))
	{
		if (tilde[1] == '/')
			return (home_replacing(shell, str, tilde));
		if (tilde[1] == '+')
			return (pwd_replacing(shell, str, tilde));
		//
	}
	return (0);
}
