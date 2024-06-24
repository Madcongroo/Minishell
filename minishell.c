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
	t_tocken	*tocken;


	prompt = "Minishell> ";
	while (1)
	{
		printf("%s", prompt);
		line = readline(argv[1]);
		if (tokening_line(&tocken, line))
			return (0);
	}
	free(line);
	return (0);
}
