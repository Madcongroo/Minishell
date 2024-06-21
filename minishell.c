#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*prompt;

	prompt = "Minishell$> ";

	while (1)
	{
		printf("%s", prompt);
		readline();
	}
}
