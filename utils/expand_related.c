//
//
//
//
//
//
//
//

#include "../minishell.h"

int	could_it_be_transformed(char *str, t_general *gen)
{
	int		i;
	int		dol_i;
	int		j;

	i = 0;
	while (str[i] != '$')
		i++;
	i++;
	dol_i = i;
	while (gen->envir)
	{
		j = -1;
		i = dol_i;
		while (str[i] == gen->envir->name[++j])
			i++;
		if ((str[i] == 34 || str[i] == 39 || str[i] == '\0' || str[i] == ' ')
			&& gen->envir->name[j] == '\0')
				return (1);
		gen->envir = gen->envir->next;
	}
	return (0);
}

int	check_if_quoted(char *str)
{
	int		i;
	char	c;
	int		dollar;

	i = -1;
	while (str[++i])
	{
		if (str[i] == 34 || str[i] == 39)
		{
			c = str[i];
			while (str[++i] != c)
			{
				if (str[i] == '$')
					dollar = 1;
			}
		}
		if (dollar == 1 && c == 34)
			return (1);
		else if (dollar == 1 && c == 39)
			return (2);
	}
	return (3);
}

t_expand	*find_concerned_node(char *str, t_expand *exp)
{
	int	i;

	while (exp)
	{
		i = 0;
		while (exp->name[i] == str[i])
			i++;
		if (exp->name[i] == '\0' && (str[i] == ' ' || str[i] == '\0'
			|| str[i] == 34 || str[i] == 39))
				return (exp);
		exp = exp->next;
	}
	return (exp);
}

int	get_good_len(char *str, t_general *gen)
{
	int len1;
	int	len2;
	int	len3;

	len1 = ft_strlen(gen->envir->env);
	len2 = ft_strlen(gen->envir->name);
	len3 = ft_strlen(str);
	return (len1 + (len3 - len2));
}

char	*expand_variable(char *str, t_general *gen)
{
	int		i;
	int		j;
	int		len;
	char	*new;

	gen->envir = find_concerned_node(str, gen->envir);
	len = get_good_len(str, gen);
	new = (char *)malloc(sizeof(char) * len);
	if (!new)
		exit (1);
	i = -1;
	len = -1;
	while (str[++i])
	{
		new[++len] = str[i];
		if (str[i] == '$')
		{
			j = -1;
			while (gen->envir->env[++j])
				new[len++] = gen->envir->env[j];
		}
	}
	new[len] = '\0';
	return (cleaning_str(new, gen, 0));
}

char	*take_dollar_off(char *str, t_general *gen)
{
	char	*new;
	int		i;
	int		j;

	i = ft_strlen(str);
	new = (char *)malloc(sizeof(char) * i);
	if (!new)
		exit (1);
	i = 0;
	j = -1;
	while (str[i])
	{
		if (str[i] == '$')
			i++;
		new[++j] = str[i];
		i++;
	}
	new[j] = '\0';
	return (cleaning_str(new, gen, 0));
}

/*check_if_quoted == 1 if single quoted : 2 if double quoted : 3 if unquoted

check if the dollar is quoted if the dollar is single quoted write the var untransformed
and unquoted
if the dollar is unquoted ignore the dollar create a token by what follows the dollar*/
char	*handle_quoted_dollar(char *str, t_general *gen)
{
	int		i;
	int		transform;
	char	*new_str;

	transform = could_it_be_transformed(str, gen);
	i = check_if_quoted(str);
	if (transform == 1)
	{
		if (i == 2 || i == 3)
			new_str = expand_variable(str, gen);
		else
			new_str = cleaning_str(str, gen, 0);
	}
	else
	{
		if (i == 1 || i == 2)
			new_str = cleaning_str(str, gen, 0);
		else
			new_str = take_dollar_off(str, gen);
	}
	return (new_str);
}
char	*compare_env_variable(char *arg, t_general *gen)
{
	int		i;
	char	*new_line;

	i = 0;
	if (arg[i] == '$' && arg[i + 1] == '\0')
		return (arg);
	while (gen->envir)
	{
		i = 0;
		while(gen->envir->name[i] == arg[i])
			i++;
		if (gen->envir->name[i] == '\0')
		{
			// free(arg);
			new_line = ft_strdup(gen->envir->env);
			return (new_line);
		}
		gen->envir = gen->envir->next;
	}
	new_line = ft_strdup(""); // a voir plus tard si ca fonctionne mais pas sur
	// free(arg);
	return (new_line);
}

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

char	*could_expand(char *arg, t_general *gen, t_token *new_node)
{
	int		i;
	char	*new_arg;

	i = 0;
	while (arg[i] != '$')
		i++;
	i++;
	new_arg = compare_env_variable(arg + i, gen);
	printf("new arg = %s\n", new_arg);
	i = -1;
	while (new_arg[++i])
	{
		if (new_arg[i] == ' ')
			new_node->to_split = 1;
	}
	return (new_arg);
}
