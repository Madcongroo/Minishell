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
	char	*prompt;
	(void)envp;
	(void)argc;


	prompt = "Minishell$ ";
	while (1)
	{
		printf("%s", prompt);
		readline(argv[1]);
	}
}
