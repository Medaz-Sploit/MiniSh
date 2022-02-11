/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:26:42 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/09 04:03:15 by mazoukni         ###   ########.fr       */
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

int	add_cmd(size_t *i, t_token **head)
{
	t_ch	*tmp;
	t_list	*list;
	char	**tab;
	char	*str;

	list = NULL;
	while ((g_parser->line[(*i)] != '\'' && g_parser->line[(*i)] != '"'
			&& g_parser->line[(*i)] != '|' && g_parser->line[(*i)] != '>'
			&& g_parser->line[(*i)] != '<') && g_parser->line[(*i)])
	{
		tmp = malloc(sizeof(t_ch));
		tmp->c = g_parser->line[(*i)];
		ft_lstadd_back(&list, ft_lstnew(tmp));
		(*i)++;
	}
	str = list_to_string(list);
	tab = ft_split(str, ' ');
	ffunction(head, tab, *i, 0);
	free_table(tab);
	free(str);
	ft_lstclear(&list, &free_list);
	(*i)--;
	return (1);
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

void	execdup(t_parser *parser, int *fds, int x, int fd)
{
	if (x != 0)
	{
		dup2(fd, 0);
		close(fd);
	}
	if (parser->number_of_commands - 1 != x)
		dup2(fds[1], 1);
	close(fds[1]);
	close(fds[0]);
}

void	ft_exitstatu(int *fd, int *fds, pid_t pid)
{
	if (pid == -1)
		ft_putstr_fd("error : fork failed\n", 2);
	else
	{
		if (*fd)
			close(*fd);
		close(fds[1]);
		*fd = fds[0];
	}
}

void	mlpipe(t_parser *parser)
{
	int		fds[2];
	pid_t	*pid;
	int		i;
	int		fd;

	i = -1;
	pid = malloc(sizeof(pid_t *) * (g_parser->number_of_commands + 1));
	while (++i < parser->number_of_commands)
	{
		pipe(fds);
		pid[i] = fork();
		if (pid[i] == 0)
		{
			execdup(parser, fds, i, fd);
			check_builtins(parser, ft_findcmd(parser->command_table, i), NULL);
			exit(parser->exit_status);
		}
		ft_exitstatu(&fd, fds, pid[i]);
	}
	close (fd);
	i = -1;
	while (++i < parser->number_of_commands)
		waitpid(pid[i], &parser->exit_status, 0);
	parser->exit_status = WEXITSTATUS(parser->exit_status);
	free (pid);
}