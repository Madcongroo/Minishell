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

void	add_env_variable(t_general *gen, char **envp)
{
	
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

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	t_general	*gen;

	gen = NULL;
	if (argc != 1 && !argv[0])
		return (print_errors(1, "Wrong number of arguments\n", gen));
	while (1)
	{
		line = readline("Minishell$ ");
		add_history(line);
		add_env_varible(gen, envp);
		if (lexing_words(gen, line))
			return (1);	
			// read_n_classify(&token);
		test_read_list(gen->tok);
		clear_list(&gen->tok);
		rl_on_new_line();
	}
	free (line);
	return (0);
}
