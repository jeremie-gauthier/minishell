/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:30:35 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/15 15:02:36 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printtab(char **tab)
{
	while (*tab)
	{
		ft_putstr(*tab);
		ft_putchar('\n');
		tab++;
	}
}
