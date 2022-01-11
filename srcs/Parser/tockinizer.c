/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tockinizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:50:45 by mazoukni          #+#    #+#             */
/*   Updated: 2022/01/11 20:11:36 by mazoukni         ###   ########.fr       */
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
	tocken = (void *) 0;
	parser->command_table = (t_cmd *)malloc(sizeof(t_cmd));
	parser->command_table->cmd = NULL;
	while (1)
	{
		if (parser->line[index] == '\'')
			printf("Single quote\n");
		else if (parser->line[index] == '"')
			printf("Double quote\n");
		else if (parser->line[index] == '>')
			printf("Output\n");
		else if (parser->line[index] == '<')
			printf("Input\n");
		else if (parser->line[index] == '|')
			printf("Pipe\n");
		if (index++ > ft_strlen(parser->line))
			break;
	}
	parser = add_cmd(parser, &index);
	return (tocken);
}