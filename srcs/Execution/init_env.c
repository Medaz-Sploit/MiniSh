#include "../../inc/minishell.h"

void init_env(t_parser *parser, char **envp)
{
	t_env *env;
	t_list *tmp;
	char **env;
	int i;
	
	i = 0;
	
	env = ft_calloc(1, sizeof(t_env));
	if (!env)
		exit_error(2);
	env = ft_split(envp[0], "=");
	tmp = 
	while (envp[i])
	{
		printf ("%s\n", envp[i]);
		i++;
	}
}