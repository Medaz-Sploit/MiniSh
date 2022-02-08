/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:57:21 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/08 15:10:17 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	check_builtins(t_parser *parser, t_cmd *cmd, char **envp)
{
	g_parser->signal = 1;
	if (parser->number_of_commands == 0 || cmd == NULL)
		return ;
	//else if (!strncmp(cmd->s[0], "help", 5))
	//	do_help();
	else if (!ft_strncmp(cmd->s[0], "echo", 5))
		echo(parser, cmd);
	//else if (!strncmp(cmd->s[0], "exit", 5))
	//	ft_exit(cmd, parser);
	//else if (!strncmp(cmd->s[0], "pwd", 4))
	//	do_pwd(parser, cmd);
	//else if (!strncmp(cmd->s[0], "env", 4))
	//	do_env(parser, cmd);
	//else if (!strncmp(cmd->s[0], "cd", 3))
	//	ft_cd(parser, cmd);
	//else if (!strncmp(cmd->s[0], "export", 7))
	//	do_export(parser, cmd);
	//else if (!strncmp(cmd->s[0], "unset", 6))
	//	do_unset(parser, cmd);
	else
		exec_cmd(cmd->s, parser, cmd, envp);
}