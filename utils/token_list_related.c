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

int	find_dollar_n_quotes(char *arg)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (arg[++i])
	{
		if (arg[i] == 34 || arg[i] == 39)
			flag += 10;
		if (arg[i] == '$')
			flag += 1;
	}
	return (flag);
}

int	is_a_redir(char *arg)
{
	int	len;

	len = ft_strlen(arg);
	if (len == 1)
	{

	}
}

int		type_of_token(char *arg)
{
	int	i;

	i = -1;
	if (is_a_redir(arg))
	{

	}
	while (arg[++i])
	{
		if ()
	}
}

int		should_this_execute(char *arg)
{
	int	i;
	int	flag;

	
}

char	*compare_env_variale(char *arg, char **env)
{
	int		i;
	int		j;
	char	*new_line;
	int		len;

	i = -1;
	len = 0;
	while (env[++i])
	{
		j = 0;
		while(env[i][j] == arg[j])
			j++;
		if (env[i][j] == '=')
		{
			j++;
			len = ft_strlen(env[i] + j)
			new_line = ft_strdup(env[i] + j);
			return (new_line)
		}
	}
	return (0);
}

char	*could_expand(char *arg, t_general *gen)
{
	int		i;
	int		exp;
	char	*new_arg;

	i = 0;
	while (arg[i] != '$')
		i++;
	i++;
	 = compare_env_variable(arg + i, gen->env);
	if (exp > 0)
		new_arg = replace
	
}

void	fill_token_args(t_token *new_node, char *arg, t_general *gen)
{
	int	trigger;

	trigger = find_dollar_n_quotes(arg);
	if (trigger == 0)
		new_node->arg = arg;
	else if (trigger < 20 && trigger > 0)
		new_node->arg = could_expand(arg, gen);
	else
		new_node->arg = cleaning_str(arg, gen);
	new_node->enum_exec = type_of_token(arg);
	new_node->to_execute = should_this_execute(arg);
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
