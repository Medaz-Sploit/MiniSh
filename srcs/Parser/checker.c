/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 23:15:19 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/04 16:15:34 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_heredoc(char *str)
{
	int		fd[2];
	char	*line;
	int		x;

	x = 1;
	pipe(fd);
	while (x)
	{
		line = readline("");
		x = strcmp(line, str);
		if (!x)
			break ;
		else
			write(fd[1], line, strlen(line));
		free(line);
		write(fd[1], "\n", 1);
	}
	if (line)
		free(line);
	close(fd[1]);
	return (fd[0]);
}

int	ft_spaceskip(char *line, int *i)
{
	if (line == NULL)
		return (0);
	while (line && ((line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n')
			|| (line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f')))
		(*i)++;
	return (1);
}

void	ffunction2(t_token **head, char **tab, size_t i, int f)
{
	int		l;

	l = 0;
	while (tab[l])
		l++;
	if (l != 1)
	{
		while (tab[f] && f < (l - 1))
			ft_lstadd_back_type(head, ft_lstadd_type(tab[f++], 0, 0));
		if ((g_parser->line[i] == '\'' || g_parser->line[i] == '"')
			&& g_parser->line[i - 1] != ' ')
			ft_lstadd_back_type(head, ft_lstadd_type(tab[f], 0, 1));
		else
		{
			if (tab[f] == NULL)
				ft_lstadd_back_type(head, ft_lstadd_type(ft_strdup(""), 0, 0));
			else
				ft_lstadd_back_type(head, ft_lstadd_type(tab[f], 0, 0));
		}
	}
}

void	ffunction(t_token **head, char **tab, size_t i, int f)
{
	int		l;

	l = 0;
	while (tab[l])
		l++;
	if (l == 1)
	{
		if ((g_parser->line[i] == '\'' || \
			g_parser->line[i] == '"') && g_parser->line[i - 1] != ' ')
			ft_lstadd_back_type(head, ft_lstadd_type(tab[0], 0, 1));
		else
			ft_lstadd_back_type(head, ft_lstadd_type(tab[0], 0, 0));
		return ;
	}
	ffunction2(head, tab, i, f);
}