/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:20:29 by mazoukni          #+#    #+#             */
/*   Updated: 2022/01/04 12:56:13 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_list
{
	char	*data;
	struct	s_list *next;
}				t_list;

typedef struct s_token
{
	char	c;
	char	*token;
	int		type;
	int		a;
	struct s_token *prev;
	struct s_token *next;
}				t_token;

typedef struct s_cmd
{
	char	*cmd;
	char	**s;
	t_list	args;
	int		input;
	int		output;
}				t_cmd;

typedef struct s_env
{
	char	*name;
	char	*content;
}				t_env;

typedef struct s_parser
{
	t_list	*command_table;
	t_list	*env;
	t_list	*token;
	char	*line;
	int		exit_status;
	int		number_of_commands;
	int		syntax_check;
	int		signal;
}				t_parser;


#endif