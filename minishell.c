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
	char	*line;
	(void)envp;
	(void)argc;


	prompt = "Minishell$ ";
	while (1)
	{
		printf("%s", prompt);
		line = readline(argv[1]);
		if (parse_line(line))
			return (0);
	}
}
