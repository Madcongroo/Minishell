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

t_tocken	*find_last_node(int i, t_tocken *tocken)
{
	t_tocken	*temp;

	temp = tocken;
	if (i == 1)
	{
		while (temp->next)
			temp = temp->next;
	}
	else
	{
		while
	}
}

void	new_node(t_tocken **tocken, int status, char *arg)
{
	t_tocken	*new_node;

	new_node = (t_tocken *)malloc(sizeof(t_tocken));
	if (!new_node)
		return ;
	new_node->arg = arg;
	new_node->status = status;
	new_node->next = NULL;
	if (!(*tocken))
	{
		(*tocken) = new_node;
		(*tocken)->prev = NULL;
	}
	else
	{
		find_last_node(1, tocken)->next = new_node;

	}
}

t_tocken	*find_last_node(int i, t_tocken *tocken)
{
	t_tocken	*temp;

	temp = tocken;
	if (i == 1)
	{
		while (temp->next)
			temp = temp->next;
	}
	else
	{
		while
	}
}

void	new_node(t_tocken **tocken, int status, char *arg)
{
	t_tocken	*new_node;

	new_node = (t_tocken *)malloc(sizeof(t_tocken));
	if (!new_node)
		return ;
	new_node->arg = arg;
	new_node->status = status;
	new_node->next = NULL;
	if (!(*tocken))
	{
		(*tocken) = new_node;
		(*tocken)->prev = NULL;
	}
	else
	{
		find_last_node(1, tocken)->next = new_node;

	}
}


void	tokening_line(t_tocken **tockens, char *line)
{
    
}
