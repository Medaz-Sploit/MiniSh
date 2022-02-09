/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:03:22 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/09 01:04:49 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void free_list(void *content)
{
	free(content);
}

void	free_env(void *content)
{
	t_env	*tmp;

	tmp = (t_env *)content;
	free(tmp->content);
	free(tmp->name);
	free(tmp);
}

void	ft_deletlst(char *name, t_list *env)
{
	t_env	*lst;
	t_list	*tmplst;

	tmplst = NULL;
	while ((env))
	{
		lst = (env)->content;
		if (!strncmp(name, lst->name, strlen(lst->name) + 1))
			break ;
		tmplst = (env);
		(env) = (env)->next;
	}
	if (!(env))
		return ;
	if (tmplst)
		tmplst->next = (env)->next;
	else
		g_parser->env = (env)->next;
	free (lst->content);
	free (lst->name);
	free (lst);
	free ((env));
}