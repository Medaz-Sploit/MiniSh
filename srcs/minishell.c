/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:21:17 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/08 12:56:06 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int main(int argc, char **argv, char **envp)
{
	argv = NULL;
	argc = 0;
	initialize_data();
	init_env(envp);
	while (1)
	{
		g_parser->line = readline("\x1B[33mLAIN_IS_LAIN@Medaz-Sploit$> \x1B[37m");
		parsing();
		if (g_parser->number_of_commands == 1 && g_parser->command_table)
			check_builtins(g_parser, g_parser->command_table->content, envp);
	}
	return (0);
}