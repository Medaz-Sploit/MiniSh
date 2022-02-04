/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:08:35 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/04 18:59:12 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_pwd(t_parser *parser, t_cmd *cmd)
{
	char	*str;

	str = getcwd(NULL, 0);
	if (cmd->s[1])
		parser->exit_status = 1;
	else
	{
		ft_putstr_fd(str, cmd->output);
		write(cmd->output, "\n", 1);
	}
	free(str);
	parser->exit_status = 0;
}