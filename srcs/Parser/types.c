/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:26:42 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/04 15:58:08 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	free_table(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
	table = NULL;
}

int	add_cmd(size_t *i, t_token **head)
{
	t_ch	*tmp;
	t_list	*list;
	char	**tab;
	char	*str;

	list = NULL;
	while ((g_parser->line[(*i)] != '\'' && g_parser->line[(*i)] != '"'
			&& g_parser->line[(*i)] != '|' && g_parser->line[(*i)] != '>'
			&& g_parser->line[(*i)] != '<') && g_parser->line[(*i)])
	{
		tmp = malloc(sizeof(t_ch));
		tmp->c = g_parser->line[(*i)];
		ft_lstadd_back(&list, ft_lstnew(tmp));
		(*i)++;
	}
	str = list_to_string(list);
	tab = ft_split(str, ' ');
	ffunction(head, tab, *i, 0);
	free_table(tab);
	free(str);
	ft_lstclear(&list, &free_list);
	(*i)--;
	return (1);
}

int	add_quote(size_t *i, char c, t_token **head)
{
	t_list	*list;
	char	*str;
	
	(*i)++;
	list = fill_list(i, c);
	str = list_to_string(list);
	ft_lstclear(&list, &free_list);
	(*i)++;
	if (c == '\'')
	{
		if (g_parser->line)
		{
			if(ft_redirection(g_parser->line[(*i)], 0) || !g_parser->line[(*i)] || \
			g_parser->line[(*i)] == '|' || g_parser->line[(*i)] == ' ')
				ft_lstadd_back_type(head, ft_lstadd_type(str, 1, 0));
			else
				ft_lstadd_back_type(head, ft_lstadd_type(str, 1, 1));
		}
		(*i) -= 2;
		free(str);
		return (1);
	}
	add_double_quote(i, c, head, str);
	(*i) -= 2;
	return (1);
}