#include "../../inc/minishell.h"

void init_env(t_parser *parser, char **envp)
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
	printf("env_table name: %s\tcontent: %s\n", env->name, env->content);
	free(env_table);
	while (envp[i])
	{
		env_table = ft_split(envp[i], '=');
		env = ft_calloc(1, sizeof(t_env));
		if (!env)
			exit_error(2);
		env->name = ft_strdup(env_table[0]);
		env->content = ft_strdup(env_table[1]);
		ft_lstadd_back(&(tmp_list), ft_lstnew(env));
		printf("%s=%s\n", env->name, env->content);
		free(env_table);
		i++;
	}
	parser->env = tmp_list;
}