/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:31:43 by nabboudi          #+#    #+#             */
/*   Updated: 2022/02/09 00:05:19 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ff(char *p)
{
	int	i;

	i = -1;
	if (!ft_isalpha(p[0]))
		return (0);
	while (p[++i])
	{
		if (!ft_isalnum(p[i]) && p[i] != '_')
			return (0);
	}
	return (1);
}

void	addnewenv(t_parser *parser, char	**p)
{
	t_env	*env;
	t_env	*tmp;

	env = ft_lstfind(parser->env, p[0]);
	if (env)
	{
		free (env->content);
		if (p[1])
			env->content = strdup(p[1]);
		else
			env->content = strdup("");
	}
	else
	{
		if (p[1])
			env = ft_lstnewenv(p[0], p[1]);
		else
			env = ft_lstnewenv(p[0], "");
		tmp = ft_lstlast(parser->env)->content;
		ft_lstadd_back(&parser->env, ft_lstnew((void *)env));
	}
}

char	**mycatstr(char *str, int i)
{
	char	**p;
	char	*tmp;

	p = malloc(sizeof(char **) * 3);
	if (i)
	{
		tmp = malloc(i + 2);
		if (str[i - 1] == '+')
			ft_strlcpy(tmp, str, i);
		else
			ft_strlcpy(tmp, str, i + 1);
		p[0] = tmp;
		tmp = malloc(strlen(&str[i] + 2) + 2);
		ft_strlcpy(tmp, &str[i + 1], strlen(&str[i]));
		p[1] = tmp;
		p[2] = NULL;
	}
	else
	{
		p[0] = ft_strdup(str);
		p[1] = NULL;
	}
	return (p);
}

void	export_join(t_parser *parser, char **p)
{
	char	*str;
	char	*tmp;
	t_env	*env;

	env = ft_lstfind(parser->env, p[0]);
	if (env)
	{
		if (p[1])
			str = strdup(p[1]);
		else
			str = strdup("");
		tmp = ft_strjoin(env->content, str);
		free (env->content);
		free (str);
		env->content = tmp;
	}
	else
		addnewenv(parser, p);
}

void	ft_lstupdate(t_parser *parser, char **str, int j)
{
	int		i;
	char	**p;

	i = 0;
	parser->exit_status = 0;
	while (str[++i])
	{
		j = ft_findc(str[i], '=');
		p = mycatstr(str[i], j);
		if (!ff(p[0]))
			return ;
		else if (j)
		{
			if (ft_strchr(p[0], '+'))
				return ;
			if (str[i][j - 1] == '+')
				export_join(parser, p);
			else
				addnewenv(parser, p);
		}
		else
			addnewenv(parser, p);
		ft_free_split(p);
	}
	parser->exit_status = 0;
}

void	export(t_parser *parser, t_cmd *cmd)
{
	int		i;
	char	**str;

	str = cmd->s;
	i = 0;
	if (!str[1])
		ft_printsortlst(parser, cmd);
	else
		ft_lstupdate(parser, str, 0);
}