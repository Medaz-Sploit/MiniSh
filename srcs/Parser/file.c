/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:15:44 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/04 15:38:03 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	output(size_t *i, char c, t_token **head)
{
	t_ch	*tmp;
	t_list	*list;
	char	*str;
	size_t	k;

	list = NULL;
	while (g_parser->line[(*i)] == c && g_parser->line[(*i)])
	{
		tmp = malloc(sizeof(t_ch));
		tmp->c = g_parser->line[(*i)];
		ft_lstadd_back(&list, ft_lstnew(tmp));
		(*i)++;
	}
	(*i)--;
	str = list_to_string(list);
	ft_lstclear(&list, &free_list);
	k = ft_strlen(str);
	if (k == 1)
		ft_lstadd_back_type(head, ft_lstadd_type(str, 4, 0));
	else if (k == 2)
		ft_lstadd_back_type(head, ft_lstadd_type(str, 3, 0));
	else
		log_error("syntax_error\n");
	free(str);
}

void	init_cmd(t_cmd *cmd)
{
	cmd->cmd = NULL;
	cmd->s = NULL;
	cmd->args = NULL;
	cmd->input = 0;
	cmd->output = 1;
}

void	input(size_t *i, char c, t_token **head)
{
	t_ch	*tmp;
	t_list	*list;
	char	*str;
	size_t	k;

	list = NULL;
	while (g_parser->line[(*i)] == c && g_parser->line[(*i)])
	{
		tmp = malloc(sizeof(t_ch));
		tmp->c = g_parser->line[(*i)];
		ft_lstadd_back(&list, ft_lstnew(tmp));
		(*i)++;
	}
	(*i)--;
	str = list_to_string(list);
	ft_lstclear(&list, &free_list);
	k = ft_strlen(str);
	if (k == 1)
		ft_lstadd_back_type(head, ft_lstadd_type(str, 6, 0));
	else if (k == 2)
		ft_lstadd_back_type(head, ft_lstadd_type(str, 5, 0));
	else
		log_error("syntax_error\n");
	free(str);
}

void	get_in(int *i, t_list *list_files, t_token *expanded_types)
{
	char	*s;

	*i = 0;
	s = NULL;
	if (list_files)
	{
		expanded_types = expanded_types->next;
		while (expanded_types)
		{
			if (expanded_types->prev->type == 5
				&& (ft_redirection(' ', expanded_types->type) == 0))
			{
				s = expanded_types->token;
				*i = ft_heredoc(expanded_types->token);
			}
			else if (expanded_types->prev->type == 6
				&& (ft_redirection(' ', expanded_types->type) == 0))
			{
				s = expanded_types->token;
				*i = open(expanded_types->token, O_RDONLY);
			}
			expanded_types = expanded_types->next;
		}
	}
}

void	get_out(int *i, t_list *list_files, t_token *expanded_types)
{
	char	*s;

	*i = 1;
	if (list_files)
	{
		expanded_types = expanded_types->next;
		while (expanded_types)
		{
			s = expanded_types->token;
			if (expanded_types->prev->type == 4
				&& (ft_redirection(' ', expanded_types->type) == 0))
				*i = open(s, O_WRONLY | O_CREAT | O_TRUNC, 0777);
			else if (expanded_types->prev->type == 3
				&& (ft_redirection(' ', expanded_types->type) == 0))
				*i = open(s, O_WRONLY | O_CREAT | O_APPEND, 0777);
			expanded_types = expanded_types->next;
		}
	}
}