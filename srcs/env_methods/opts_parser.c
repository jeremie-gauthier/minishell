/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 23:18:48 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/20 23:23:06 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	alloc_unset_opts(size_t argc, char **argv, t_envopts *opts)
{
	size_t	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strequ(argv[i], UNSET_ENV_VAR) && argv[i + 1] != NULL)
			opts->len_unset_vars++;
		i++;
	}
	if (opts->len_unset_vars > 0)
		if (!(opts->unset_vars = (char**)ft_memalloc(
								(opts->len_unset_vars + 1) * sizeof(char*))))
			return (FAILURE);
	return (SUCCESS);
}

static void *tabdel_wrapper(void **tab, size_t size)
{
  ft_tabdel(tab, size);
  return (NULL);
}

char	**parse_env_opts(size_t argc, char **argv, t_envopts *opts)
{
	size_t	i;
	size_t	n_unset_var;

	n_unset_var = 0;
	i = 1;
	if (alloc_unset_opts(argc, argv, opts) == FAILURE)
		return (NULL);
	while (i < argc && argv[i][0] == '-')
	{
		if (ft_strequ(argv[i], END_OF_ARGS))
			break ;
		if (ft_strequ(argv[i], IGNORE_ENV))
			opts->ignore_env = true;
		else if (ft_strequ(argv[i], UNSET_ENV_VAR) && argv[i + 1] != NULL)
		{
			i++;
			if (!(opts->unset_vars[n_unset_var] = ft_strdup(argv[i])))
        return (tabdel_wrapper((void**)opts->unset_vars, n_unset_var));
      n_unset_var++;
		}
		i++;
	}
	return (&argv[i]);
}
