/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:49:35 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/04 15:52:38 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	**ll_to_dp(t_list *list)
{
	int		len;
	int		i;
	char	*l;
	char	**str;

	len = ft_lstsize(list);
	str = malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (list)
	{
		str[i] = ft_strdup(list->content);
		l = (char *)list->content;
		i++;
		list = list->next;
	}
	str[i] = 0;
	return (str);
}

t_token	*get_node(t_token *types)
{
	int		a;
	t_token	*tmp;

	a = 2;
	tmp = types;
	while (a-- && tmp)
		tmp = tmp->next;
	return (tmp);
}