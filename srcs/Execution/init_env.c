#include "../../inc/minishell.h"

void init_env(char **envp)
{
	t_env *env;
	t_list *tmp_list;
	char **env_table;
	int i;
	
	i = 1;
	env = ft_calloc(1, sizeof(t_env));
	if (!env)
		exit_error(2);
	env_table = ft_split(envp[0], '=');
	env->name = ft_strdup(env_table[0]);
	env->content = ft_strdup(env_table[1]);
	tmp_list = ft_lstnew(env_table);
	while (envp[i])
	{
		env_table = ft_split(envp[i], '=');
		env = ft_calloc(1, sizeof(t_env));
		if (!env)
			exit_error(2);
		env->name = ft_strdup(env_table[0]);
		env->content = ft_strdup(env_table[1]);
		ft_lstadd_back(&(tmp_list), ft_lstnew(env));
		free_table(env_table);
		i++;
	}
	g_parser->env = tmp_list;
	g_parser->exit_status = 0;
	signal(SIGQUIT, handle_signal);
}

t_env	*ft_lstfind(t_list *lst, char *name)
{
	t_env	*env;

	while (lst)
	{
		env = (t_env *)lst->content;
		if (!ft_strncmp(name, env->name, ft_strlen(env->name) + 1))
			return (env);
		else
			lst = lst->next;
	}
	return (NULL);
}