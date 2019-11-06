/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:35:52 by jergauth          #+#    #+#             */
/*   Updated: 2019/08/27 18:24:36 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	register size_t			len;
	register unsigned int	uptr;

	len = 0;
	while (1)
	{
		uptr = *(unsigned int*)str;
		if ((uptr & 0XFF) == 0)
			return (len);
		if ((uptr & 0XFF00) == 0)
			return (len + 1);
		if ((uptr & 0XFF0000) == 0)
			return (len + 2);
		if ((uptr & 0XFF000000) == 0)
			return (len + 3);
		str += 4;
		len += 4;
	}
}
