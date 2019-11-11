/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:30:53 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/11 18:45:46 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Concatenation of two strings with slahs ('/') between them.
*/

char	*glue_str(char const *s1, char const *s2, char glue)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(str = malloc((len_s1 + len_s2 + 2) * sizeof(char))))
		return (NULL);
	ft_memcpy((void*)str, (void*)s1, len_s1);
	str[len_s1] = glue;
	ft_memcpy((void*)&str[len_s1 + 1], (void*)s2, len_s2 + 1);
	return (str);
}

/*
**	Returns a malloc'ed string corresponding to the file pathname
**	or NULL if the filename is not found.
*/

char	*access_file(const char *path, const char *filename)
{
	char	*pathname;

	if (!(pathname = glue_str(path, filename, '/')))
	{
		ft_dprintf(STDERR, "minishell: malloc failed\n");
		return (NULL);
	}
	if (access(pathname, F_OK | X_OK) < 0)
	{
		ft_strdel(&pathname);
		return (NULL);
	}
	return (pathname);
}
