/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:09:39 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/11 21:17:39 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_var(const char *str)
{
	char	*var;
	char	*ptr;

	var = NULL;
	ptr = (char*)str;
	while (*ptr && ft_isalnum(*ptr))
		ptr++;
	if (ptr - str)
		if (!(var = ft_strndup(str, ptr - str + 1)))
			return (NULL);
	return (var);
}

static void	arg_parser(t_shell *shell, const char *str)
{
	char	*ptr;
	char	*var;

	var = NULL;
	if ((ptr = ft_strchr(str, '$')))
	{
		write(1, str, str - ptr);
		if ((var = get_var(ptr + 1)))
		{
			ptr = get_var_content(var, shell->env);
			ft_strdel(&var);
			if (ptr)
				ft_printf("%s", ptr);
		}
		else
			ft_printf("$");
	}
	else
		ft_printf("%s", str);
}

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
	while (shell->argv[i])
	{
		if (i > ret)
			ft_printf(" ");
		arg_parser(shell, shell->argv[i]);
		i++;
	}
	if (ret > 1)
		ft_printf("%s%%{reset}", EOL_COLOR);
	ft_printf("\n");
	return (0);
}
