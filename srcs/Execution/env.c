/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:12:13 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/09 00:13:45 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	env(t_parser *parser, t_cmd *cmd)
{
	t_list	*l;
	t_env	*env;

	l = parser->env;
	if (cmd->s[1])
	{
		parser->exit_status = 127;
		return ;
	}
	while (l != NULL)
	{
		env = l->content;
		ft_putstr_fd(env->name, cmd->output);
		write(cmd->output, "=", 1);
		ft_putstr_fd(env->content, cmd->output);
		write(cmd->output, "\n", 1);
		l = l->next;
	}
	parser->exit_status = 0;
}