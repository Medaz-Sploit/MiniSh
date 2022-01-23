/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:26:42 by mazoukni          #+#    #+#             */
/*   Updated: 2022/01/23 15:28:57 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_token	add_single_quote(t_parser *parser, char c, size_t *index)
{
	//tocken = NULL;
	//if ( == '\'')
	//{
	//	//
	//}
}

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
		printf("command not found\n");
	return (ft_strdup(cmd));
}

char	*get_command(t_parser *parser, char *str)
{
	t_list	*env_tmp;
	char	**path;
	char	*cmd;
	t_env	*env_l;

	env_tmp = parser->env;
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

t_parser	*add_cmd(t_parser *parser, size_t *index)
{
	t_cmd *cmd;
	char **tab;
	cmd = ft_calloc(1, sizeof(t_cmd));
	tab = ft_calloc(1, sizeof(char *));
	if (!cmd || !tab)
		printf("Error\n");
	parser->command_table->output = 1;
	parser->command_table->input = 0;
	tab = ft_split(parser->line, ' ');
	cmd->s = tab;
	cmd->cmd = cmd->s[0];
	cmd->cmd = get_command(parser, cmd->cmd);
	parser->command_table->s = cmd->s;
	parser->command_table->cmd = cmd->cmd;
	return (parser);
}