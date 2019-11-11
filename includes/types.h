/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:07:01 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/11 22:24:34 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "defines.h"

typedef enum	e_status
{
	STOPPED	= 0,
	RUNNING
}				t_status;

typedef struct	s_shell
{
	char		*path_bin[ARR_BUFF];
	char		*env[ARR_BUFF];
	char		**argv;
	char		*pathname;
	size_t		path_bin_size;
	// size_t		nb_alloc_bin;
	size_t		argc;
	size_t		env_idx;
	t_status	status;
}				t_shell;

typedef int		(*t_builtin)(t_shell*);

#endif
