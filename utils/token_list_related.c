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

// int	is_a_redir(char *arg)
// {
// 	int	len;

// 	len = ft_strlen(arg);
// 	if (len == 1)
// 	{

// 	}
// }

// int		type_of_token(char *arg)
// {
// 	int	i;

// 	i = -1;
// 	if (is_a_redir(arg))
// 	{

// 	}
// 	while (arg[++i])
// 	{
// 		if ()
// 	}
// }

void	fill_token_args(t_token *new_node, char *arg, t_general *gen)
{
	int	trigger;

	trigger = find_dollar_n_quotes(arg);
	new_node->to_split = 0;
	// printf("%s\n", arg);
	if (trigger == 0)
		new_node->arg = arg;
	else if (trigger < 20 && trigger > 0)
		new_node->arg = could_expand(arg, gen, new_node);
	else
		new_node->arg = cleaning_str(arg, gen, 1);
	// new_node->enum_exec = type_of_token(arg);
}


t_token	*find_last_node(t_token *token)
{
	t_token	*temp;

	temp = token;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	new_node(t_token **token, char *arg, t_general *gen)
{
	t_token	*new_node;

	new_node = (t_token *)malloc(sizeof(t_token));
	if (!new_node)
		return ;
	fill_token_args(new_node, arg, gen);
	if (!(*token))
	{
		// new_node->prev = NULL;
		(*token) = new_node;
	}
	else
		find_last_node(*token)->next = new_node;
	new_node->next = NULL;
}

void	clear_list(t_token **token)
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
