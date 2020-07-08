/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:49:48 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/08 17:58:23 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_fork(int signum)
{
	(void)signum;
	ft_printf("\n");
}

void	sigint_core(int signum)
{
	(void)signum;
	ft_printf("\n");
	display_prompt();
}
