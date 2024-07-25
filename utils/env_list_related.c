//
//
//
//
//
//
//
//

#include "../minishell.h"

t_expand	*find_last_node_env(t_expand *exp)
{
	t_expand	*temp;

	temp = exp;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	new_node_env(t_expand **exp, char *arg, char *name)
{
	t_expand	*new_node;

	new_node = (t_expand *)malloc(sizeof(t_expand));
	if (!new_node)
		return ;
	new_node->name = name;
	new_node->env = arg;
	if (!(*exp))
		(*exp) = new_node;
	else
		find_last_node_env(*exp)->next = new_node;
	new_node->next = NULL;
}

void	clear_list_expand(t_expand **env)
{
	t_expand *temp;

	if ((*env))
	{
		while ((*env))
		{
			temp = (*env)->next;
			free ((*env));
			(*env) = temp;
		}
	}
	else
		return ;
}
