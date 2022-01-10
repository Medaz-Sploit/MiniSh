/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:20:29 by mazoukni          #+#    #+#             */
/*   Updated: 2022/01/08 13:38:47 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stddef.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../libft/libft.h"
# define TOKEN_CMD 0
# define TOKEN_OPT 1
# define TOKEN_STRING 2
# define TOKEN_PIPE 3
# define TOKEN_LRED 4
# define TOKEN_RRED 5
# define TOKEN_APP_RED 6
# define TOKEN_INPUT_RED 7

typedef struct s_lexeme
{
	char *value;
	int type;
}	t_lexeme;


typedef struct	s_node
{
	void	*content;
	struct s_node *left;
	struct s_node *right;
}				t_node;
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

void init_env(t_parser *parser, char **envp);
void init_struct(t_parser *parser);
void	parsing(t_parser *parser);
t_parser	*initialize_data(t_parser *parser);
int exit_error(int e);
t_token	*tockinizer(t_parser *parser, size_t index);
#endif