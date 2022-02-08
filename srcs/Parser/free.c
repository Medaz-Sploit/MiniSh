/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:56:50 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/08 14:33:36 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	free_cmd(void *content)
{
	t_cmd	*tmp;
	t_list	*args;
	t_list	*help;

	tmp = (t_cmd *)content;
	args = tmp->args;
	while (args)
	{
		if (args->next)
			help = args->next;
		else
			help = NULL;
		free(args->content);
		free(args);
		args = help;
	}
	free(tmp->cmd);
	free_table(tmp->s);
	free(tmp);
}

void	free_nodes_types(t_token	**list)
{
	t_token	*tmp;

	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		if (tmp->token != NULL)
			free(tmp->token);
		free(tmp);
	}
}

void	free_token(void *content)
{
	t_token	*tmp;

	tmp = (t_token *)content;
	free_nodes_types(&tmp);
}

void	clear_list_files(t_list **list_files)
{
	t_list	*help;

	while ((*list_files))
	{
		if ((*list_files)->next)
			help = (*list_files)->next;
		else
			help = NULL;
		free((*list_files));
		(*list_files) = help;
	}
}