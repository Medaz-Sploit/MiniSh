/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:30:30 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/04 16:20:34 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	add_tab_to_ll(t_token **head, char *str, int type, int a)
{
	char	**tab;
	int		i;

	i = 0;
	if (!str[0])
	{
		ft_lstadd_back_type(head, ft_lstnew_type2(ft_strdup(""), type, a));
		return ;
	}
	tab = ft_split(str, ' ');
	while (tab[i])
	{
		ft_lstadd_back_type(head, ft_lstnew_type2(tab[i], type, a));
		i++;
	}
	free (tab);
}

void	add_string(t_list **head, char *str)
{
	t_ch	*tmp;
	int		i;

	i = 0;
	if (!str[i])
	{
		tmp = malloc(sizeof(t_ch));
		tmp->c = '\0';
		ft_lstadd_back(head, ft_lstnew(tmp));
	}
	while (str[i])
	{
		tmp = malloc(sizeof(t_ch));
		tmp->c = str[i];
		ft_lstadd_back(head, ft_lstnew(tmp));
		i++;
	}
}

void	add_to_lk(char *s, int a, t_ch *tmp, t_list **list_keys)
{
	tmp = malloc(sizeof(t_ch));
	tmp->c = s[a];
	ft_lstadd_back(list_keys, ft_lstnew(tmp));
}

t_token	*ft_lstnew_type2(char *content, int i, int a)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token) * 1);
	new->token = content;
	new->type = i;
	new->a = a;
	new->next = NULL;
	return (new);
}

char	*return_env_value(char *key)
{
	t_list	*env;
	t_env	*tmp;
	size_t	i;

	env = g_parser->env;
	i = 0;
	while (env)
	{
		tmp = (t_env *)env->content;
		i = ft_strlen(tmp->name);
		if (i == ft_strlen(key))
		{
			if (strcmp(tmp->name, key) == 0)
				return (tmp->content);
		}
		env = env->next;
	}
	return (ft_strdup(""));
}