/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:18:16 by mazoukni          #+#    #+#             */
/*   Updated: 2022/01/07 13:06:37 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	parsing(t_parser *parser)
{
	t_token *tocken;
	t_list	*tockens;
	t_cmd	*cmd;
	char	*string;

	tocken = tockinizer(parser, 0);
}