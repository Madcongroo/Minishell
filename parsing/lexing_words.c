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

t_tocken	*find_last_node(t_tocken *tocken)
{
	t_tocken	*temp;

	temp = tocken;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	new_node(t_tocken **tocken, int status, char *arg)
{
	t_tocken	*new_node;

	new_node = (t_tocken *)malloc(sizeof(t_tocken));
	if (!new_node)
		return ;
	if (!(*tocken))
		(*tocken) = new_node;
	else
		find_last_node(tocken)->next = new_node;
	new_node->next = NULL;
}

void	lexing_words(t_tocken **tockens, char *line)
{
    
}
