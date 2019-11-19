/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:49:48 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/19 12:54:22 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_fork(__attribute__((unused)) int signum)
{
	ft_printf("\n");
}

void	sigint_core(__attribute__((unused)) int signum)
{
	ft_printf("\n");
	display_prompt();
}
