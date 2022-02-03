/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:08:35 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/01 21:39:07 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_pwd()
{
	char	*str;

	str = getcwd(NULL, 0);
	if (g_parser->command_table->s[1])
		g_parser->exit_status = 1;
	else
	{
		ft_putstr_fd(str, g_parser->command_table->output);
		write(g_parser->command_table->output, "\n", 1);
	}
	free(str);
	g_parser->exit_status = 0;
}