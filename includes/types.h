/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:07:01 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/11 18:10:09 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef enum	e_status
{
	STOPPED	= 0,
	RUNNING
}				t_status;

typedef struct	s_shell
{
	char		**path_bin;
	char		**argv;
	char		*pathname;
	size_t		path_bin_size;
	size_t		nb_alloc_bin;
	size_t		argc;
	size_t		nb_alloc_env;
	size_t		env_idx;
	t_status	status;
	int			env_malloced : 1;
}				t_shell;

typedef int		(*t_builtin)(t_shell*, char **const);

#endif
