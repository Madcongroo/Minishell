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

char	*cleaning_str(char *str, t_general *gen, int doll)
{
	char	*clean_str;
	int		mall;

	if (doll == 1)
		clean_str = handle_quoted_dollar(str, gen);
	else
	{
		mall = new_value_to_malloc(str);
		clean_str = copy_str(str, mall);
		if (!clean_str)
			return (NULL);
	}
	// free(str);
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

int	mall_with_new_value(char *line, int mall)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (line[j] == ' ')
		j++;
	while (line[i])
		i++;
	return ((i - j) + mall);
}

int	handle_sep(char *line)
{
	int	i;
	int	mall;

	i = -1;
	mall = 0;
	while (line[++i])
	{
		if (i > 0)
		{
			if (line[i] == '|' && line[i - 1] != ' ')
				mall += 1;
			else if (line[i] == '<' && line[i - 1] != ' ')
				mall += 1;
			else if (line[i] == '>' && line[i - 1] != ' ')
				mall += 1;
		}
		if (line[i] == '|' && line[i + 1] != ' ')
				mall += 1;
		else if (line[i] == '<' && line[i + 1] != ' ')
				mall += 1;
		else if (line[i] == '>' && line[i + 1] != ' ')
				mall += 1;
	}
	return (mall_with_new_value(line, mall));
}

int	handle_special_char(char *line)
{
	int		i;
	char	trigger;

	i = -1;
	while (line[++i])
	{
		if ((line[i] < 47 || line[i] > 58) && (line[i] < 65 || line[i] > 90)
			&& (line[i] < 97 || line[i] > 122) && line[i] != ' ' && line[i] != '<'
				&& line[i] != '>' && line[i] != '|' && line[i] != '$' && line[i] != 34
					&& line[i] != 39);
					return (-1);
		if (line[i] == '|' && line[i + 1] == '|')
			return (-1);
		if (line[i] == 34 || line[i] == 39)
		{
			trigger = line[i];
			i++;
			while (line[i] != trigger)
				i++;
		}
	}
	return (0);
}

char	*get_clean_line(char *line, int mall)
{
	int		i;
	char	*n_line;
	int		j;
	int		quotes;

	n_line = (char *)malloc(sizeof(char) * (mall + 2));
	if (!n_line)
		return (NULL);
	i = -1;
	j = 0;
	while (line[++i])
	{
		if (line[i] == 34 || line[i] == 39)
			
	}
	n_line[j] = '\0';
	return (n_line);
}

int	lexing_words(t_general *gen, char *line)
{
	char	*clean_line;
	int		mall;

	if (!line)
		return (1);
	if (handle_special_char(line) == -1)
		return (-1);
	mall = handle_sep(line);
	clean_line = get_clean_line(line, mall);
	if (!clean_line)
		return (1);
	free(line);
	if (ft_get_words(clean_line, gen))
		return (1);
	return (0);
}
