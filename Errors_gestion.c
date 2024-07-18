#include "minishell.h"

int	print_errors(int status, char *str, t_token **token)
{
	(void)token;

	printf("%s", str);
	return (status);
}
