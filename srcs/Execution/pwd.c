/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:08:35 by mazoukni          #+#    #+#             */
/*   Updated: 2022/01/23 16:11:07 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_pwd(t_parser *parser)
{
	char	*str;

	str = getcwd(NULL, 0);
	if (parser->command_table->s[1])
		parser->exit_status = 1;
	else
	{
		ft_putstr_fd(str, parser->command_table->output);
		write(parser->command_table->output, "\n", 1);
	}
	free(str);
	parser->exit_status = 0;
}