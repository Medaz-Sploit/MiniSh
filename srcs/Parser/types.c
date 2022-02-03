/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:26:42 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/02 15:19:44 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	free_table(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
	table = NULL;
}

char *get_cmd_path(char **path, char *cmd)
{
	int			i;
	char		*str;
	char		*tmp;
	int			fd;

	i = 0;
	fd = open(cmd, O_RDONLY);
	if (fd > 0)
		return (ft_strdup(cmd));
	while (path[i])
	{
		str = ft_strjoin(path[i], "/");
		tmp = str;
		str = ft_strjoin(tmp, cmd);
		free(tmp);
		fd = open(str, O_RDONLY);
		if (fd > 0)
			return (str);
		free(str);
		i++;
	}
	if (fd < 0)
		perror("command not found\n");
	return (ft_strdup(cmd));
}

char	*get_command(char *str)
{
	t_list	*env_tmp;
	char	**path;
	char	*cmd;
	t_env	*env_l;

	env_tmp = g_parser->env;
	while (env_tmp)
	{
		env_l = env_tmp->content;
		if (!(ft_strncmp(env_l->name, "PATH", 4)))
			cmd = env_l->content;
		env_tmp = env_tmp->next;
	}
	path = ft_split(cmd, ':');
	str = get_cmd_path(path, str);
	free_table(path);
	return (str);
}

void	add_cmd()
{
	t_cmd *cmd;
	char **tab;
	cmd = ft_calloc(1, sizeof(t_cmd));
	tab = ft_calloc(1, sizeof(char *));
	if (!cmd || !tab)
		printf("Error\n");
	g_parser->command_table->output = 1;
	g_parser->command_table->input = 0;
	tab = ft_split(g_parser->line, ' ');
	cmd->s = tab;
	cmd->cmd = cmd->s[0];
	cmd->cmd = get_command(cmd->cmd);
	g_parser->command_table->s = cmd->s;
	g_parser->command_table->cmd = cmd->cmd;
}

int	add_quote(size_t *i, char c, t_token **head)
{
	t_list	*list;
	char	*str;
	
	(*i)++;
	list = fill_list(i, c);
	str = list_to_string(list);
	ft_lstclear(&list, &free_list);
	(*i)++;
	if (c == '\'')
	{
		if (g_parser->line)
		{
			if(ft_redirection(g_parser->line[(*i)], 0) || !g_parser->line[(*i)] || \
			g_parser->line[(*i)] == '|' || g_parser->line[(*i)] == ' ')
				ft_lstadd_back_type(head, ft_lstadd_type(str, 1, 0));
			else
				ft_lstadd_back_type(head, ft_lstadd_type(str, 1, 1));
		}
		(*i) -= 2;
		free(str);
		return (1);
	}
	add_double_quote(i, c, head, str);
	(*i) -= 2;
	return (1);
}