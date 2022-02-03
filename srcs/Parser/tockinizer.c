/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tockinizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:50:45 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/02 15:16:47 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_token	*tockinizer(size_t index)
{
	t_token *tocken;
	int sq;
	int dq;

	tocken = (void *) 0;
	sq = 0;
	dq = 0;
	g_parser->command_table = (t_cmd *)malloc(sizeof(t_cmd));
	g_parser->command_table->cmd = NULL;
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
			;
		else if (g_parser->line[index] == '<' && sq == 0 && dq == 0)
			;
		else if (g_parser->line[index] == '|' && sq == 0 && dq == 0)
			;
		if (index++ > ft_strlen(g_parser->line))
			break;
	}
	add_cmd();
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