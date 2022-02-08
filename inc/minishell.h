/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:20:29 by mazoukni          #+#    #+#             */
/*   Updated: 2022/02/08 14:33:16 by mazoukni         ###   ########.fr       */
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
	t_list	*args;
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

t_parser *g_parser;

void		init_env(char **envp);
int			add_quote(size_t *i, char c, t_token **head);
void		init_struct();
void		parsing();
int			initialize_data();
void		exit_error(int e);
t_token		*tockinizer(size_t index);
void		ft_lstadd_back_type(t_token **alst, t_token *new);
t_token		*ft_lstadd_type(char *content, int i, int b);
int			add_cmd(size_t *i, t_token **head);
void		exec_cmd(char **cmd1, t_parser *parser, t_cmd *cmd, char **envp);
void		echo();
void		check_builtins(t_parser *parser, t_cmd *cmd, char **envp);
void		ft_exit();
void		ft_cd(t_parser *parser, t_cmd *cmd);
void		ft_pwd(t_parser *parser, t_cmd *cmd);
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
void		output(size_t *i, char c, t_token **head);
void		output(size_t *i, char c, t_token **head);
void		input(size_t *i, char c, t_token **head);
void		ffunction(t_token **head, char **tab, size_t i, int f);
void		ffunction2(t_token **head, char **tab, size_t i, int f);
void		free_token(void *content);
void		free_nodes_types(t_token	**list);
void		expand_cmdlist(t_list *tmp, char *str, t_cmd *cmd);
void		add_string(t_list **head, char *str);
void		add_to_lk(char *s, int a, t_ch *tmp, t_list **list_keys);
t_token		*ft_lstnew_type2(char *content, int i, int a);
void		add_tab_to_ll(t_token **head, char *str, int type, int a);
void		init_cmd(t_cmd *cmd);
int			ft_lstsize_type(t_token *type);
void		clear_list_files(t_list **list_files);
void		get_out(int *i, t_list *list_files, t_token *expanded_types);
void		get_in(int *i, t_list *list_files, t_token *expanded_types);
t_token		*get_node(t_token *types);
char		**ll_to_dp(t_list *list);
void		get_command(t_token *tmp2, char *str, t_cmd **cmd, t_token **expanded_types);
void		free_table(char **table);
char		*return_env_value(char *key);
t_token		*expander(t_token *tmp);
int			ft_heredoc(char *str);
t_list		*get_args(t_list **args, t_token *types, t_cmd **cmd);
void		clear(void);
void		free_cmd(void *content);
#endif