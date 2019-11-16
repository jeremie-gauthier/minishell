/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:07:01 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/16 20:12:25 by jergauth         ###   ########.fr       */
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

typedef struct	s_vars
{
	char	*home;
	char	*path;	//unused
}				t_vars;

typedef struct	s_shell
{
	char		*path_bin[ARR_BUFF];
	char		*env[ARR_BUFF];
	t_vars		vars;
	char		**argv;
	char		*pathname;
	size_t		path_bin_size;
	size_t		argc;
	size_t		env_idx;
	t_status	status;
}				t_shell;

typedef int		(*t_builtin)(t_shell*);

#endif
