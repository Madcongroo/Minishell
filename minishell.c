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



int	main(int argc, char **argv, char **envp)
{
	char		*prompt;
	char		*line;
	t_token	*token;

	token = NULL;
	prompt = "Minishell> ";
	while (1)
	{
		printf("%s", prompt);
		line = readline(argv[1]);
		if (lexing_words(&token, line))
			return (0);
	}
	free(line);
	return (0);
}
