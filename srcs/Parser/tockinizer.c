/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tockinizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:50:45 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/08 13:02:45 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_lstsize_type(t_token *type)
{
	int		i;

	i = 0;
	if (type)
	{
		while (type)
		{
			i++;
			type = type->next;
		}
	}
	return (i);
}

t_token	*tockinizer(size_t index)
{
	t_token *tocken;
	int sq;
	int dq;

	tocken = (void *) 0;
	sq = 0;
	dq = 0;
	while (1)
	{
		if (g_parser->line[index] == '\'' && sq == 0 && dq == 0)
			sq = add_quote(&index, '\'', &tocken);
		else if (g_parser->line[index] == '\'' && sq == 1 && dq == 0)
			sq = 0;
		else if (g_parser->line[index] == '"' && sq == 0 && dq == 0)
			dq = add_quote(&index, '"', &tocken);
		else if (g_parser->line[index] == '"' && sq == 0 && dq == 1)
			dq = 0;
		else if (g_parser->line[index] == '>' && sq == 0 && dq == 0)
			output(&index, '>', &tocken);
		else if (g_parser->line[index] == '<' && sq == 0 && dq == 0)
			input(&index, '<', &tocken);
		else if (g_parser->line[index] == '|' && sq == 0 && dq == 0)
		{
			ft_lstadd_back(&g_parser->token, ft_lstnew(tocken));
			tocken = (void *)0;
		}
		else if (g_parser->line[index] != ' ')
			add_cmd(&index, &tocken);
		if (index++ >= ft_strlen(g_parser->line) - 1)
			break;
	}
	return (tocken);
}

void	add_double_quote(size_t *i, char c, t_token **head, char *str)
{
	if (c != '\'')
	{
		if (g_parser->line[(*i)] == ' ' || !g_parser->line[(*i)] || \
			g_parser->line[(*i)] == '|' || ft_redirection(g_parser->line[(*i)], 0))
			ft_lstadd_back_type(head, ft_lstadd_type(str, 2, 0));
		else
			ft_lstadd_back_type(head, ft_lstadd_type(str, 2, 1));
	}
	free(str);
}