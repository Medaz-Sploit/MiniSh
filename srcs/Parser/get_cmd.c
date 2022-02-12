/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:28:03 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/12 01:38:13 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*get_absolute_path(char **pa, char *cmd)
{
	int			i;
	char		*str;
	char		*tmp;
	int			fd;

	i = 0;
	fd = open(cmd, O_RDONLY);
	if (fd > 0)
		return (ft_strdup(cmd));
	while (pa[i])
	{
		str = ft_strjoin(pa[i], "/");
		tmp = str;
		str = ft_strjoin(tmp, cmd);
		free(tmp);
		fd = open(str, O_RDONLY);
		if (fd > 0)
			return (str);
		free(str);
		i++;
	}
	return (ft_strdup(cmd));
}

char	*get_cmd_path(char *str, t_list *env)
{
	t_list	*env_tmp;
	char	**path;
	char	*cmd;
	t_env	*env_l;

	env_tmp = env;
	while (env_tmp)
	{
		env_l = env_tmp->content;
		if (!(ft_strncmp(env_l->name, "PATH", 4)))
			cmd = env_l->content; 
		env_tmp = env_tmp->next;
	}
	path = ft_split(cmd, ':');
	str = get_absolute_path(path, str);
	free_table(path);
	return (str);
}

void	get_command(t_token *tmp2, char *str, t_cmd **cmd, t_token **expanded_types)
{
	if (!tmp2)
		return ;
	if (ft_redirection(' ', tmp2->type))
	{
		if (ft_lstsize_type(tmp2) == 2)
			(*cmd)->cmd = ft_strdup("");
		else if (ft_lstsize_type(tmp2) == 3)
		{
			str = get_node(tmp2)->token;
			(*cmd)->cmd = get_cmd_path(str, g_parser->env);
		}
		else
		{
			while (ft_redirection(' ', tmp2->type))
				tmp2 = tmp2->next->next;
			(*cmd)->cmd = get_cmd_path(tmp2->token, g_parser->env);
		}
	}
	else if (tmp2->type == 0)
		(*cmd)->cmd = get_cmd_path((*expanded_types)->token, g_parser->env);
}

void	help_args(t_token **tmp, t_list **args)
{
	char	*str;
	char	*swap;
	int		i;

	i = 0;
	if ((*tmp)->a == 1)
	{
		while ((*tmp)->a == 1)
		{
			if (i == 0)
				str = ft_strjoin((*tmp)->token, (*tmp)->next->token);
			else
			{
				swap = str;
				str = ft_strjoin(swap, (*tmp)->next->token);
				free(swap);
			}
			i++;
			(*tmp) = (*tmp)->next;
		}
		ft_lstadd_back(args, ft_lstnew(str));
	}
	else
		ft_lstadd_back(args, ft_lstnew(ft_strdup((*tmp)->token)));
}

t_list	*get_args(t_list **args, t_token *types, t_cmd **cmd)
{
	t_token	*tmp;
	t_list	*list_files;

	tmp = types;
	list_files = NULL;
	while (tmp)
	{
		if (ft_redirection(' ', tmp->type) && tmp->next
			&& !ft_redirection(' ', tmp->next->type))
			ft_lstadd_back(&list_files, ft_lstnew(tmp->next->token));
		if (!ft_redirection(' ', tmp->type))
		{
			if (tmp->prev != NULL)
			{
				if (!ft_redirection(' ', tmp->prev->type))
					help_args(&tmp, args);
			}
			else
				ft_lstadd_back(args, ft_lstnew(ft_strdup(tmp->token)));
		}
		tmp = tmp->next;
	}
	(*cmd)->s = ll_to_dp(*args);
	return (list_files);
}
