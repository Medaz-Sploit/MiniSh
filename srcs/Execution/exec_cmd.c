/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:20:44 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/01 21:49:08 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	exec_cmd(char **envp)
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
		dup2(g_parser->command_table->input, 0);
		dup2(g_parser->command_table->output, 1);
		execve(g_parser->command_table->cmd, g_parser->command_table->s, envp);
	}
}