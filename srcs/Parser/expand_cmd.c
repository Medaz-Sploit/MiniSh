/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:05:07 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/09 02:58:44 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	to_skip2(char *s, size_t *a, t_list **head, t_ch *tmp)
{
	char	*swap;
	t_list	*list_keys;

	list_keys = NULL;
	swap = NULL;
	(*a)++;
	while (ft_isalnum(s[(*a)]) == 1)
		add_to_lk(s, (*a)++, tmp, &list_keys);
	swap = list_to_string(list_keys);
	ft_lstclear(&list_keys, &free_list);
	add_string(head, return_env_value(swap));
	free(swap);
	(*a)--;
}

static void	to_skip(char *s, size_t *a, t_list **head, size_t i)
{
	t_ch	*tmp;
	t_list	*list_keys;
	char	*key;

	list_keys = NULL;
	tmp = NULL;
	if (s[i + 1] == '\'' || s[i + 1] == '?')
	{
		if (s[i + 1] == '?')
		{
			key = ft_itoa(g_parser->exit_status);
			(*a)++;
		}
		else
		{
			add_to_lk(s, *a, tmp, &list_keys);
			key = list_to_string(list_keys);
			ft_lstclear(&list_keys, &free_list);
		}
		add_string(head, key);
		free(key);
		return ;
	}
	to_skip2(s, a, head, tmp);
}

void	expand_word2(char *str, t_list **head, int a, size_t i)
{
	t_ch	*tmp;
	size_t	f;

	while (1)
	{
		tmp = malloc(sizeof(t_ch));
		tmp->c = str[i];
		if (str[i] == '$')
		{
			g_parser->f_unset = 1;
			f = i;
			to_skip(str, &i, head, f);
			free(tmp);
		}
		else if (str[i] == ' ' && a == 0)
		{
			ft_lstadd_back(head, ft_lstnew(tmp));
			while (str[i] == ' ')
				i++;
			i--;
		}
		else
			ft_lstadd_back(head, ft_lstnew(tmp));
		if (i++ >= ft_strlen(str) - 1)
			break ;
	}
}

void	expand_word(char *str, t_list **head, int a, size_t i)
{
	t_ch	*tmp;

	if (!str[i])
	{
		tmp = malloc(sizeof(t_ch));
		tmp->c = '\0';
		ft_lstadd_back(head, ft_lstnew(tmp));
		return ;
	}
	expand_word2(str, head, a, i);
}

t_token	*expander(t_token *tmp)
{
	t_token	*new;
	t_list	*head;
	char	*to_str;

	new = NULL;
	while (tmp)
	{
		head = NULL;
		if (tmp->type == 2 || tmp->type == 0)
			expand_word(tmp->token, &head, tmp->type, 0);
		else
			add_string(&head, tmp->token);
		if (tmp->type == 0)
		{
			to_str = list_to_string(head);
			add_tab_to_ll(&new, to_str, tmp->type, tmp->a);
			free(to_str);
		}
		else
			ft_lstadd_back_type(&new,
				ft_lstnew_type2(list_to_string(head), tmp->type, tmp->a));
		ft_lstclear(&head, &free_list);
		tmp = tmp->next;
	}
	return (new);
}