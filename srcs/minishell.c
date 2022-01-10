/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:21:17 by mazoukni          #+#    #+#             */
/*   Updated: 2022/01/07 13:13:02 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int main(int argc, char **argv, char **envp)
{
	t_parser *parser;
	
	parser = NULL;
	argv = NULL;
	argc = 0;
	parser = initialize_data(parser);
	init_env(parser, envp);
	while (1)
	{
		parser->line = readline("\x1B[33mLAIN_IS_LAIN@Medaz-Sploit$> \x1B[37m");
		parsing(parser);
	}
	return (0);
}