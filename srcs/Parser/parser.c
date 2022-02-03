/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:18:16 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/03 16:05:18 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"



int	check_words2(int *i, t_token *tmp2)
{
	while (tmp2)
	{
		if (ft_redirection(tmp2->type, 0))
			if (!(tmp2->next))
				return (0);
		tmp2 = tmp2->next;
	}
	if (g_parser->line[*(i)] == '\0')
		return (1);
	(*i)++;
	ft_spaceskip(g_parser->line, i);
	if (g_parser->line[*i] == '|')
		return (0);
	return (1);
}

void	parsing()
{
	t_token *tocken;
	t_list	*tmp1;
	//t_cmd	*cmd;
	//char	*str;

	tocken = tockinizer(0);
	if (tocken)
		ft_lstadd_back(&g_parser->token, ft_lstnew(tocken)); // add leximes to tokkens list
	tmp1 = g_parser->token;
	syntax_error(tmp1);
	//if (g_parser->syntax_check == 0)
	//	expand_cmdlist(tmp1, str, cmd);
	//ft_lstclear(&g_parser->token, &free_type);
}