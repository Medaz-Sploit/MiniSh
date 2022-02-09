/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 01:01:11 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/09 01:02:07 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	unset(t_parser *parser, t_cmd *cmd)
{
	int		i;
	char	**str;

	i = 0;
	str = cmd->s;
	if (!str[1])
		return ;
	while (str[++i])
		ft_deletlst(str[i], parser->env);
	parser->exit_status = 0;
}