/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:04:53 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/02 15:50:31 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_lstadd_back_type(t_token **alst, t_token *new)
{
	t_token	*last;

	new->next = NULL;
	last = *alst;
	if (!(*alst))
	{
		new->prev = NULL;
		*alst = new;
	}
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
}

t_token	*ft_lstadd_type(char *content, int i, int b)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token) * 1);
	new->token = strdup(content);
	new->type = i;
	new->a = b;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int		ft_redirection(char c, int i)
{
	if (c == '>' || c == '<')
		return (1);
	else if (i == 4 || i == 5 || i == 6 || i == 3)
		return (1);
	return (0);
}

t_list	*fill_list(size_t *i, char c)
{
	t_ch	*tmp;
	t_list		*list;

	list = NULL;
	while (g_parser->line[(*i)] != c && g_parser->line[(*i)])
	{
		tmp = malloc(sizeof(t_ch));
		tmp->c = g_parser->line[(*i)];
		ft_lstadd_back(&list, ft_lstnew(tmp));
		(*i)++;
	}
	return (list);
}

char	*list_to_string(t_list *head)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = ft_lstsize(head);
	str = malloc(len + 1);
	while (head)
	{
		str[i] = ((t_ch *)head->content)->c;
		i++;
		head = head->next;
	}
	str[len] = '\0';
	return (str);
}