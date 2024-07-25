//
//
//
//
//
//
//
//
//
//
//
//
//
//

#include "minishell.h"

// void	read_n_cassify(t_token **token)
// {
// 	t_token	*temp;

// 	temp = (*token);
// 	while (temp)
// 	{
// 		what_type_is_node()
// 	}
// }

/*change la liste chainee de la variable d environnement : mettre deux string une pour le "nom"
ex : USER= , et une pour la valeur qui est ce qui suit le nom*/

char	*each_envp_line(char *env_line, int name)
{
	int		i;
	char	*new_line;

	i = 0;
	if (name == 1)
		new_line = ft_strdup(env_line);
	else
	{
		while (env_line[i] != '=')
			i++;
		i++;
		new_line = ft_strdup(env_line + i);
	}
	return (new_line);
}

char	**get_envp_array(char **envp)
{
	char	**new_env;
	int		i;
	int		j;

	j = 0;
	while (envp[j])
		j++;
	new_env = (char **)malloc(sizeof(char *) * j);
	if (!new_env)
		exit (1);
	i = -1;
	while (++i < j)
		new_env[i] = each_envp_line(envp[i], 1);
	return (new_env);
}

char	*get_name(char *envp, t_general *gen)
{
	int		i;
	char	*name;

	i = 0;
	while (envp[i] != '=')
		i++;
	name = (char *)malloc(sizeof(char) * i);
	if (!name)
		exit (1);
	i = -1;
	while (envp[++i] != '=')
		name[i] = envp[i];
	name[i] = '\0';
	return (name);
}

void	add_env_variable(t_general *gen, char **envp)
{
	char	*new_env;
	char	*name;
	int		i;

	gen->env = get_envp_array(envp);
	i = -1;
	while (envp[++i])
	{
		name = get_name(envp[i], gen);
		new_env = each_envp_line(envp[i], 0);
		new_node_env(&gen->envir, new_env, name);
	}
}

void	test_read_list(t_token *token)
{
	if (token)
	{
		while (token)
		{
			printf("%s\n", token->arg);
			token = token->next;
		}
	}
}

void	init_struct(t_general *gen)
{
	gen->env = NULL;
	gen->envir = NULL;
	gen->tok = NULL;
	gen->word = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	t_general	gen;

	if (argc != 1 && !argv[0])
		return (print_errors(1, "Wrong number of arguments\n", &gen));
	init_struct(&gen);
	add_env_variable(&gen, envp);
	while (1)
	{
		line = readline("minishell$ ");
		add_history(line);
		if (lexing_words(&gen, line))
			return (1);
		// read_n_classify(&token);
		test_read_list(gen.tok);
		clear_list(&gen.tok);
		rl_on_new_line();
	}
	free (line);
	return (0);
}
