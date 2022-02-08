/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:18:16 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/08 13:45:43 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	expand_cmdlist(t_list *tmp, char *str, t_cmd *cmd)
{
	t_token	*tmp2;
	t_token	*expanded_types;
	t_list	*list_files;

	while (tmp)
	{
		tmp2 = tmp->content;
		expanded_types = expander(tmp->content);
		cmd = malloc(sizeof(t_cmd));
		init_cmd(cmd);
		get_command(tmp2, str, &cmd, &expanded_types);
		list_files = get_args(&(cmd->args), expanded_types, &cmd);
		get_out(&(cmd->output), list_files, expanded_types);
		get_in(&(cmd->input), list_files, expanded_types);
		ft_lstadd_back(&g_parser->command_table, ft_lstnew(cmd));
		free_nodes_types(&expanded_types);
		if (list_files)
			clear_list_files(&list_files);
		tmp = tmp->next;
	}
	g_parser->number_of_commands = ft_lstsize(g_parser->command_table);
}

int	check_words2(int *i, t_token *tmp2)
{
	while (tmp2)
	{
		if (ft_redirection(tmp2->type, 0))
			if (!(tmp2->next))
				return (0);
		tmp2 = tmp2->next;
	}
	if (g_parser->line[*(i)] == '\0')
		return (1);
	(*i)++;
	ft_spaceskip(g_parser->line, i);
	if (g_parser->line[*i] == '|')
		return (0);
	return (1);
}

void	parsing()
{
	t_token *tocken;
	t_list	*tmp1;
	t_cmd	*cmd;
	char	*str;

	str = NULL;
	cmd = NULL;
	tocken = tockinizer(0);
	if (tocken)
		ft_lstadd_back(&g_parser->token, ft_lstnew(tocken));
	tmp1 = g_parser->token;
	syntax_error(tmp1);
	if (g_parser->syntax_check == 0)
		expand_cmdlist(tmp1, str, cmd);
	ft_lstclear(&g_parser->token, &free_token);
}