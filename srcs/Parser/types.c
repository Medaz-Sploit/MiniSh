/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:26:42 by mazoukni          #+#    #+#             */
/*   Updated: 2022/01/11 20:11:08 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	add_single_quote(t_token *tocken, char c, size_t *index)
{
	//tocken = NULL;
	//if (parser->line[*index] == '\'')
	//{
	//	
	//}
}

t_parser	*add_cmd(t_parser *parser, size_t *index)
{
	t_cmd *cmd;
	char **tab;
	cmd = ft_calloc(1, sizeof(t_cmd));
	tab = ft_calloc(1, sizeof(char *));
	if (!cmd || !tab)
		printf("Error\n");
	tab = ft_split(parser->line, ' ');
	cmd->s = tab;
	cmd->cmd = cmd->s[0];
	parser->command_table->s = cmd->s;
	parser->command_table->cmd = cmd->cmd;
	return (parser);
}