/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:21:17 by mazoukni          #+#    #+#             */
/*   Updated: 2022/01/05 11:34:12 by mazoukni         ###   ########.fr       */
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
		parsing(parser);
		
	}
	return (0);
}