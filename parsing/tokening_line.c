//
//
//
//
//
//
//
//
//

#include "../minishell.h"

void	ft_strtok(t_tocken *node, char *line, char del1, char del2)
{
	static int index;
	static int	len;
	while (line[len] != del1 && line[len] != del2 && line[len] != '\0')
		len++;
	node->arg = malloc(sizeof(char) * len);
	len++;
	while (line[index] != del1 && line[index] != del2 && line[index] != '\0')
	{
		node->arg[index] = line[index];
		index++;
	}
	index++;
	return ;
	// allouer memoire token
	//assigner 
}
void	tokening_line(t_tocken **tockens, char *line)
{
	new_node(tockens);

	ft_strtok(*tockens, line, ' ', '"');
}
