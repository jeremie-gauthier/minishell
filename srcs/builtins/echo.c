/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:09:39 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/13 22:39:03 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	echo_options(char **const argv)
{
	size_t	ret;

	ret = 1;
	while (argv[ret] && ft_strequ(argv[ret], "-n"))
		ret++;
	return (ret);
}

int			echo_builtin(t_shell *shell)
{
	size_t	i;
	size_t	ret;

	ret = echo_options(shell->argv);
	i = ret;
	if (exp_parser(shell) < 0)
		return (-1);
	while (shell->argv[i])
	{
		if (i > ret)
			ft_printf(" ");
		ft_printf("%s", shell->argv[i]);
		i++;
	}
	if (ret > 1 && i > ret)
		ft_printf("%s%%{reset}\n", EOL_COLOR);
	else if (ret == 1)
		ft_printf("\n");
	return (0);
}
