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

char	*each_envp_line(char *env_line)
{
	int		i;
	char	*new_line;

	i = ft_strlen(env_line);
	new_line = (char *)malloc(sizeof(char) * (i + 1));
	if (!new_line)
		exit (1);
	i = -1;
	while (env_line[++i])
		new_line[i] = env_line[i];
	new_line[i] = '\0';
	// printf("%s\n", new_line);
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
		new_env[i] = each_envp_line(envp[i]);
	return (new_env);
}

void	add_env_variable(t_general *gen, char **envp)
{
	char	*new_env;
	int		i;

	gen->env = get_envp_array(envp);
	i = -1;
	while (envp[++i])
	{
		new_env = each_envp_line(envp[i]);
		new_node_env(&gen->envir, new_env);
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
	while (1)
	{
		line = readline("Minishell$ ");
		add_history(line);
		init_struct(&gen);
		add_env_variable(&gen, envp);
		if (lexing_words(&gen, line))
			return (1);
		// read_n_classify(&token);
		test_read_list(gen.tok);
		syntax_analisis(gen);
		clear_list(&gen.tok);
		rl_on_new_line();
	}
	free (line);
	return (0);
}
