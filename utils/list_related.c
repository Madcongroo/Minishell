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
	new_node->arg = arg;
	new_node->enum_exec = status;
	new_node->to_execute = 0;
	if (!(*token))
		(*token) = new_node;
	else
		find_last_node(*token)->next = new_node;
	new_node->next = NULL;
}
void    clear_list(t_token **token)
{
    t_token *temp;

    if ((*token))
    {
        while ((*token))
        {
            temp = (*token)->next;
            free ((*token));
            (*token) = temp;
        }
    }
    else
        return ;
}
