/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:15:32 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/01 22:27:41 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	initialize_data()
{
	g_parser = ft_calloc(1, sizeof(t_parser));
	if (!g_parser)
		return (0);
	g_parser->env = NULL;
	g_parser->exit_status = 0;
	g_parser->line = NULL;
	g_parser->number_of_commands = 0;
	g_parser->signal = 0;
	g_parser->syntax_check = 0;
	g_parser->token = NULL;
	return (1);
}