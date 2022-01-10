/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tockinizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:50:45 by mazoukni          #+#    #+#             */
/*   Updated: 2022/01/08 14:53:44 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_token	*tockinizer(t_parser *parser, size_t index)
{
	t_token *tocken;
	int single_quote;
	int double_quote;

	single_quote = 0;
	double_quote = 0;
	tocken = NULL;
	while (1)
	{
		if (parser->line[index] == '\'')
			single_quote = (single_quote == 0) ? add_single_quote(tocken, '\'', &index) : 0;
		else if (parser->line[index] == '"')
			double_quote = (double_quote == 0) add_double_quote(tocken, '"', &index) : 0;
		else if (parser->line[index] == '>')
			output_token(tocken, '>', &index);
		else if (parser->line[index] == '<')
			input_token(tocken, '<', &index);
		else if (parser->line[index] == '|')
			pipe_token(tocken, '|', &index);
		if (index++ > ft_strlen(parser->line))
			break;
	}
	return (tocken);
}