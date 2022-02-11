/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:25:05 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/09 03:35:06 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_dblq(int *i, t_token **tmp1, int *f, char *str)
{
	*f = 1;
	str = get_sq_word((*tmp1), 2, f);
	while ((*tmp1) && *f != 0)
	{
		(*f)--;
		(*tmp1) = (*tmp1)->next;
	}
	*i += ft_strlen(str) + 1;
	if (g_parser->line[*i] != '"')
		return (-1);
	return (0);
}

char	*get_sq_word(t_token *types, int i, int *f)
{
	while (types)
	{
		if (types->type == i)
			return (types->token);
		types = types->next;
		(*f)++;
	}
	return (NULL);
}

int	check_sq(int *i, t_token **tmp2, int *f, char *str)
{
	*f = 1;
	str = get_sq_word((*tmp2), 1, f);
	while ((*tmp2) && *f != 0)
	{
		(*f)--;
		(*tmp2) = (*tmp2)->next;
	}
	*i += ft_strlen(str) + 1;
	if (g_parser->line[*i] != '\'')
		return (-1);
	return (0);
}

int	check_words(t_token *tmp, int *i)
{
	t_token	*tmp2;
	t_token	*tmp1;
	int		f;

	tmp2 = tmp;
	tmp1 = tmp;
	while (g_parser->line[*(i)] && g_parser->line[*(i)] != '|')
	{
		if (g_parser->line[*(i)] == '\'')
		{
			if (check_sq(i, &tmp2, &f, NULL) == -1)
				return (0);
		}
		else if (g_parser->line[*(i)] == '"')
		{
			if (check_dblq(i, &tmp1, &f, NULL) == -1)
				return (0);
		}
		(*i)++;
	}
	return (check_words2(i, tmp));
}

void	syntax_error(t_list *types)
{
	t_token	*tmp;
	char	*str;
	int		i;

	i = 0;
	while (types)
	{
		tmp = types->content;
		if (check_words(tmp, &i) == 0)
		{
			log_error("syntax_error\n");
			return ;
		}
		else
			g_parser->syntax_check = 0;
		types = types->next;
	}
	str = g_parser->line;
	i = ft_strlen(str) - 1;
	if (str[0] == '|' || str[i] == '|' || str[0] == '<' || str[0] == '>')
		log_error("syntax_error\n");
}