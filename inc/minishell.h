/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:20:29 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/03 15:58:12 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stddef.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
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

typedef struct s_ch
{
	char c;
}				t_ch;

typedef struct	s_node
{
	void	*content;
	struct s_node *left;
	struct s_node *right;
}				t_node;

typedef struct s_token
{
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
	t_cmd	*command_table;
	t_list	*env;
	t_list	*token;
	char	*line;
	int		exit_status;
	int		number_of_commands;
	int		syntax_check;
	int		signal;
}				t_parser;

t_parser *g_parser;

void		init_env(char **envp);
int			add_quote(size_t *i, char c, t_token **head);
void		init_struct();
void		parsing();
int			initialize_data();
void		exit_error(int e);
t_token		*tockinizer(size_t index);
void		ft_lstadd_back_type(t_token **alst, t_token *new);
t_token		*ft_lstnew_type(char *content, int i, int b);
void		add_cmd();
void		exec_cmd(char **envp);
void		echo();
void		check_builtins(char **envp);
void		ft_exit();
void		ft_cd();
void		ft_pwd();
t_token		*ft_lstadd_type(char *content, int i, int b);
int			ft_redirection(char c, int i);
t_list		*fill_list(size_t *i, char c);
char		*list_to_string(t_list *head);
void		free_list(void *content);
void		add_double_quote(size_t *i, char c, t_token **head, char *str);
int			ft_spaceskip(char *line, int *i);
void		syntax_error(t_list *types);
char		*get_sq_word(t_token *types, int i, int *f);
int			check_words2(int *i, t_token *tmp2);
void		log_error(char *s);
#endif