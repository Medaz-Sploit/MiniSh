/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:21:17 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/08 18:22:39 by mazoukni         ###   ########.fr       */
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
		if (!g_parser->line)
			return (0);
		if (g_parser->line[0])
		{
			parsing();
			if (g_parser->number_of_commands == 1 && g_parser->command_table)
				check_builtins(g_parser, g_parser->command_table->content, envp);
		}
		clear();
	}
	ft_lstclear(&g_parser->env, &free_env);
	free(g_parser);
	return (0);
}