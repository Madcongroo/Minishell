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
	else
		printf("token uninitialized\n");
}

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	t_token		*token;
	// (void)argc;
	// (void)envp;
	// (void)argv;

	token = NULL;
	while (1)
	{
		line = readline("Minishell$ ");
		add_history(line);
		if (lexing_words(&token, line))
			return (0);
		read_n_classify(&token);
		// clear_list(&token);
		rl_on_new_line();
	}
	free (line);
	return (0);
}
