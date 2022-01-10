/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:26:42 by mazoukni          #+#    #+#             */
/*   Updated: 2022/01/10 19:55:56 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	add_single_quote(t_parser *parser, char c, int *index)
{
	char	*single_quote_string;
	t_list	*single_quote_list;

	//single_quote_list = save_list(c, &index);
	//single_quote_string = list_to_string(single_quote_list);
	//ft_lstclear(&single_quote_list, &free_list);
	(*index++);
	if (c == '\'')
	{
		/*if (parser->line)
		{
			if (is_redir(c) || c == '|' || c == ' ' || !parser->line[index])
				//ft_lstadd_back_type();
			else
				//ft_lstadd_back_type();
		}*/
	}
}

void	add_double_quote(t_parser *parser, char c, int *index)
{
	
}