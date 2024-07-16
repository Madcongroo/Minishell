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
		puts("token uninitialized");
}

int	main(int argc, char **argv, char **envp)
{
	char		*prompt;
	char		*line;
	t_token		*token;
	(void)argc;
	(void)envp;

	token = NULL;
	prompt = "Minishell> ";
	while (1)
	{
		printf("%s", prompt);
		line = readline(argv[1]);
		if (lexing_words(&token, line))
			return (0);
		test_read_list(token);
	}
	free(line);
	return (0);
}
