/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboudi <nabboudi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:51:20 by nabboudi          #+#    #+#             */
/*   Updated: 2022/02/04 20:06:09 by nabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_splitlen(char **p)
{
	int	i;

	i = 0;
	while (p[i])
		i++;
	return (i);
}

char	**ft_free_split(char **d)
{
	int				i;

	i = 0;
	if (d == NULL)
		return (NULL);
	while (d[i])
	{
		if (d[i])
			free(d[i]);
		i++;
	}
	free(d);
	return (NULL);
}

char	**ft_print_split(char **d)
{
	int				i;

	i = 0;
	if (d == NULL)
		return (NULL);
	while (d[i])
	{
		printf("\n**%s**\n", d[i]);
		i++;
	}
	return (NULL);
}

t_cmd	*ft_findcmd(t_list *data, int id)
{
	t_cmd	*tmp;
	int		i;

	i = -1;
	tmp = data->content;
	while (tmp && ++i < g_parser->number_of_commands)
	{
		tmp = data->content;
		if (i == id)
			return (tmp);
		data = data->next;
	}
	return (NULL);
}
