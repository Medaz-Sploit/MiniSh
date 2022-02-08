/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:20:44 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/08 12:54:51 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	exec_cmd(char **cmd1, t_parser *parser, t_cmd *cmd, char **envp)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		parser->exit_status = WEXITSTATUS(status);
	}
	else
	{
		execve(cmd->cmd, cmd1, envp);
		ft_putstr_fd("Error: command not found\n", 2);
		exit(127);
	}
}