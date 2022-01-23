/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:20:44 by mazoukni          #+#    #+#             */
/*   Updated: 2022/01/11 21:34:21 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	exec_cmd(t_parser *parser, char **envp)
{
	pid_t pid;
	int status;
	
	pid = fork();
	if (pid == -1)
		printf("Error Fork\n");
	else if (pid > 0)
		waitpid(pid, &status, 0);
	else
	{
		dup2(parser->command_table->input, 0);
		dup2(parser->command_table->output, 1);
		execve(parser->command_table->cmd, parser->command_table->s, envp);
	}
}