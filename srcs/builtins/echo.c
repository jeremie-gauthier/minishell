/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:09:39 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/07 21:11:07 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		echo_builtin(const t_shell *shell, char **const env)
{
	// (void)shell;
	(void)env;
	ft_printf("ECHO %s\n", shell->argv[1]);
	return (0);
}
