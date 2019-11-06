/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:07:01 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/06 11:19:45 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct	s_shell
{
	t_list	*path_env;
	char	**argv;
	char	*pathname;
}				t_shell;

#endif
