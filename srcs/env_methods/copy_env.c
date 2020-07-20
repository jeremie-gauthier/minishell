/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:10:05 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/20 23:00:56 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool  element_in_array(const char **array, const char *element)
{
  size_t  i;

  if (array == NULL || element == NULL)
    return (false);
  i = 0;
  while (array[i])
  {
    if (ft_strnequ(array[i], element, ft_strlen(array[i])))
      return (true);
    i++;
  }
  return (false);
}

int   			copy_env(char *env[ARR_BUFF], char *copy_env[ARR_BUFF],
                  const char **blacklist)
{
	size_t	i;
  size_t  cpy_idx;

	i = 0;
  cpy_idx = 0;
	while (env[i] && i < ARR_BUFF)
	{
    if (element_in_array(blacklist, env[i]) == false)
    {
      if (!(copy_env[cpy_idx] = ft_strdup(env[i])))
      {
        free_env(copy_env, cpy_idx);
        return (FAILURE);
      }
      cpy_idx++;
    }
		i++;
	}
	return (SUCCESS);
}
