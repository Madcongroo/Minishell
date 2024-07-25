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

// int	clean_list(t_token **token)
// {
// 	t_token	*temp;

// 	temp = (*token);
// 	while (temp)
// 	{

// 	}
// }

int	new_value_to_malloc(char *str)
{
	int		i;
	char	c;
	int		quote;

	i = -1;
	quote = 0;
	while (str[++i])
	{
		if (str[i] == 34 || str[i] == 39)
		{
			quote++;
			c = str[i];
			i++;
			while (str[i] != c)
				i++;
			quote++;
		}
	}
	return (i - quote);
}

char	*copy_str(char *str, int mall)
{
	char	*clean_str;
	int		i;
	int		j;
	char	c;

	clean_str = malloc(sizeof(char) * (mall + 1));
	if (!clean_str)
		return (NULL);
	j = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == 34 || str[i] == 39)
		{
			c = str[i];
			while (str[++i] != c)
				clean_str[j++] = str[i];
		}
		if (str[i] != 34 && str[i] != 39)
		{
			clean_str[j] = str[i];
			j++;
		}
	}
	return (clean_str);
}

int	could_it_be_trandormed(char *str, t_general *gen)
{
	char	c;
	int		i;
	int		dol_i;
	int		j;

	i = 0;
	while (str[i] != '$')
		i++;
	dol_i = i;
	while (gen->envir)
	{
		j = -1;
		i = dol_i;
		while (str[i] == gen->envir->env[++j])
			i++;
		if (str[i] == '=' && gen->envir->env[j] == '=')
			return (1);
		gen->envir = gen->envir->next;
	}
	return (0);
}
// check_if_quoted == 0 : double quoted, 1 : single quoted
char	*handle_quoted_dollar(char *str, t_general *gen)
{
	char	c;
	int		i;
	int		transform;
	char	*new_str;

	transform = could_it_be_transformed(str);
	if (transform == 1)
	{
		if (check_if_quoted(str, gen) == 0)
			new_str = expand_variable(str, gen);
	}
	// check if the dollar is quoted if the dollar is quoted write the var untransformed and unquoted
	// if the dollar is unquoted ignore the dollar create a token by what follows the dollar
}

char	*cleaning_str(char *str, t_general *gen)
{
	int		i;
	char	*clean_str;
	int		mall;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '$')
			break;
	}
	if (str[i] == '$')
		handle_quoted_dollar(str, gen);
	else
	{
		mall = new_value_to_malloc(str);
		clean_str = copy_str(str, mall);
		if (!clean_str)
			return (NULL);
	}
	free(str);
	return (clean_str);
}

int	is_there_quotes(char *line)
{
	int		i;
	int		trigger;
	char	c;

	i = 0;
	trigger = 0;
	while (line[i])
	{
		if (line[i] == 34 || line[i] == 39)
		{
			c = line[i];
			i++;
			while (line[i] != c && line[i] != '\0')
				i++;
			if (line[i] == '\0')
				return (-1);
			trigger = 1;
		}
		i++;
	}
	return (trigger);
}

int	ft_get_words(char *line, t_general *gen)
{
	int		i;
	int		trigger;
	char	**array;

	i = -1;
	trigger = is_there_quotes(line);
	if (trigger == 0)
		array = ft_split(line, ' ');
	else if (trigger == 1)
		array = ft_split_with_quotes(line, ' ');
	if (trigger == -1)
		return (print_errors(1, UNCLOSED_QUOTES, gen));
	if (array)
	{
		while (array[++i])
			new_node(&gen->tok, array[i], gen);
	}
	else
		return (1);
	return (0);
}

char	*get_clean_line(char *line)
{
	int		i;
	char	*n_line;
	int		j;

	i = 0;
	j = 0;
	while (line[j] == ' ')
		j++;
	while (line[i])
		i++;
	n_line = (char *)malloc(sizeof(char) * (i - j + 1));
	if (!n_line)
		return (NULL);
	i = -1;
	while (line[++i])
	{
		n_line[i] = line[j];
		j++;
	}
	n_line[i] = '\0';
	return (n_line);
}

int	lexing_words(t_general *gen, char *line)
{
	char	*clean_line;

	if (!line)
		return (1);
	clean_line = get_clean_line(line);
	if (!clean_line)
		return (1);
	free(line);
	if (ft_get_words(clean_line, gen))
		return (1);
	return (0);
}
