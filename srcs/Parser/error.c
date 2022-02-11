/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:01:44 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/10 14:28:44 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void exit_error(int e)
{
	if (e == 0)
		printf("Error:\n\t Exit Successfuly\n");
	else if (e > 2 && e < 10)
		printf("Error:\n\t Malloc FAILED\n");
	else
		printf("Error\n");
}

void	log_error(char *s)
{
	ft_putstr_fd(s, 1);
	g_parser->exit_status = 258;
	g_parser->syntax_check = 1;
}

void	free_nodes_env(t_list	**tmp)
{
	t_env	*tmp2;

	while (*tmp)
	{
		tmp2 = (*tmp)->content;
		*tmp = (*tmp)->next;
		if (tmp2->name != NULL)
			free(tmp2->name);
		if (tmp2->content != NULL)
			free(tmp2->content);
		free(tmp2);
	}
}