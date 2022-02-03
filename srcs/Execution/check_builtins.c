/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:57:21 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/01 21:48:57 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	check_builtins(char **envp)
{
	if (!(ft_strncmp(g_parser->command_table->s[0], "echo", 4)))
		echo();
	else if (!(ft_strncmp(g_parser->command_table->s[0], "cd", 2)))
		ft_cd();
	else if (!(ft_strncmp(g_parser->command_table->s[0], "pwd", 3)))
		ft_pwd();
	// else if (!(ft_strncmp(g_parser->command_table->s[0], "export", 6)))
	// 	printf("Im working");
	// else if (!(ft_strncmp(g_parser->command_table->s[0], "unset", 5)))
	// 	printf("Im working");
	// else if (!(ft_strncmp(g_parser->command_table->s[0], "env", 3)))
	// 	printf("Im working");
	else if (!(ft_strncmp(g_parser->command_table->s[0], "exit ", 4)))
		ft_exit();
	else
		exec_cmd(envp);
}