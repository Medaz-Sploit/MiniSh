/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:24:02 by mazoukni          #+#    #+#             */
/*   Updated: 2022/01/23 15:30:53 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	echo(t_parser *parser)
{
	int		i;
	int		j;
	char	**str;

	str = parser->command_table->s;
	i = 0;
	j = 0;
	while ((!ft_strncmp(str[i++], "-n", 3)) && str[i++])
		j = 1;
	while (str[i])
	{
		write(parser->command_table->output, str[i], strlen(str[i]));
		if (str[++i])
			write(parser->command_table->output, " ", 1);
	}
	if (j == 0)
		write(parser->command_table->output, "\n", 1);
	parser->exit_status = 0;
}