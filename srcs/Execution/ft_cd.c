/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:40:31 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/04 18:57:05 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_env	*ft_lstfind(t_list *lst, char *name)
{
	t_env	*env;

	while (lst)
	{
		env = (t_env *)lst->content;
		if (!strncmp(name, env->name, strlen(env->name) + 1))
			return (env);
		else
			lst = lst->next;
	}
	return (NULL);
}

void	change_oldpwd(t_parser *parser)
{
	char	*str;
	t_env	*oldpwd;

	oldpwd = ft_lstfind(parser->env, "OLDPWD");
	str = oldpwd->content;
	free (str);
	oldpwd->content = ft_strdup(ft_lstfind(parser->env, "PWD")->content);
}

void	change_pwd(t_parser *parser)
{
	char	*str;
	t_env	*pwd;

	pwd = ft_lstfind(parser->env, "PWD");
	str = pwd->content;
	free (str);
	str = getcwd(NULL, 0);
	if (!(str))
		return ;
	pwd->content = ft_strdup(str);
	free (str);
}

void	ft_docdret(t_parser *parser)
{
	t_env	*lst;
	char	*src;

	lst = ft_lstfind(parser->env, "OLDPWD");
	if (lst)
	{
		src = ft_strdup(lst->content);
		change_oldpwd(parser);
		chdir(src);
		free(src);
		change_pwd(parser);
		parser->exit_status = 0;
	}
	else
		parser->exit_status = 1;
}

void	ft_docdsing(t_parser *parser)
{
	t_env	*lst;
	char	*src;

	lst = ft_lstfind(parser->env, "HOME");
	if (lst)
	{
		src = ft_strdup(lst->content);
		change_oldpwd(parser);
		chdir(src);
		free(src);
		change_pwd(parser);
		parser->exit_status = 0;
	}
	else
		parser->exit_status = 1;
}

void ft_cd(t_parser *parser, t_cmd *cmd)
{
	char		**str;

	str = cmd->s;
	if (str[1] && !(ft_strncmp("-", str[1], 1)))
		ft_docdret(parser);
	else if (!str[1])
		ft_docdsing(parser);
	else if (str[1])
	{
		if (chdir(str[1]) < 0)
		{
			perror("cd");
			parser->exit_status = 1;
			return ;
		}
		change_oldpwd(parser);
		change_pwd(parser);
		parser->exit_status = 0;
	}
}