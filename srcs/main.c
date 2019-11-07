/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:07:07 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/07 11:31:22 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	del_path_env(void *content, size_t size)
// {
// 	(void)size;
// 	ft_memdel(&content);
// }

static void	del_paths(t_list *lst) {
	t_list	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		ft_memdel(&tmp->content);
		ft_memdel((void*)&tmp);
		
		// tmp = (*lst)->next;
		// ft_memdel(&(*lst)->content);
		// ft_memdel((void*)&(*lst));
		// *lst = tmp;
	}
	ft_memdel((void**)lst);
}

int			main(int argc, char **argv, char **env) {
	t_shell	shell;

	(void)argc;
	(void)argv;
	if (create_path_env(env, &shell) < 0)
		return (-1);
	// listen_stdin(&shell, env);
	// ft_lstdel(&shell.path_env, &del_path_env);
	del_paths(shell.path_env);
	// while(1);
	return (0);
}
