#include "minishell.h"

int	print_errors(int status, char *str, t_general *gen)
{
	(void)gen;

	printf("%s", str);
	return (status);
}
