/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:24:02 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/09 00:17:04 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	echo(t_parser *parser, t_cmd *cmd)
{
	int		i;
	int		j;
	char	**str;

	str = cmd->s;
	i = 0;
	j = 0;
	while (!ft_strncmp(str[i++], "-n", 3) && str[i])
		j = 1;
	while (str[i])
	{
		write(cmd->output, str[i], strlen(str[i]));
		if (str[++i])
			write(cmd->output, " ", 1);
	}
	if (j == 0)
		write(cmd->output, "\n", 1);
	parser->exit_status = 0;
}

void	help(void)
{
	ft_putstr_fd("Builtins Commands:\n", 1);
	ft_putstr_fd("echo\ncd\npwd\nexport\nunset\nenv\nexit\n", 1);
}