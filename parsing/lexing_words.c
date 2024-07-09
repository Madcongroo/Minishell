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

t_token	*find_last_node(t_token *token)
{
	t_token	*temp;

	temp = token;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	new_node(t_token **token, int status, char *arg)
{
	t_token	*new_node;

	new_node = (t_token *)malloc(sizeof(t_token));
	if (!new_node)
		return ;
	if (!(*token))
		(*token) = new_node;
	else
		find_last_node(token)->next = new_node;
	new_node->next = NULL;
}

void	lexing_words(t_token **tokens, char *line)
{
    
}
