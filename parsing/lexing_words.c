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

char	*cleaning_str(char *str)
{
	int		i;
	char	*clean_str;
	int		mall;

	i = 0;
	while (str[i] != 34 && str[i] != 39 && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (str);
	mall = new_value_to_malloc(str);
	clean_str = copy_str(str, mall);
	if (!clean_str)
		return (NULL);
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

int	ft_get_words(char *line, t_token **token)
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
		return (print_errors(1, UNCLOSED_QUOTES, token));
	if (array)
	{
		while (array[++i])
		{
			if (trigger == 0)
				new_node(token, 0, array[i], 1);
			else
				new_node(token, 0, array[i], 0);
		}
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

char	*keep_if_dollar(char *line)
{
	char	*new_line;
	int		n;

	n = ft_strlen(line);
	ft_strnstr(line, ""$USER"", n);
}

int	lexing_words(t_token **tokens, char *line)
{
	char	*clean_line;
	char	*dollared_line;

	if (!line)
		return (1);
	clean_line = get_clean_line(line);
	if (!clean_line)
		return (1);
	free(line);
	if (ft_get_words(clean_line, tokens))
		return (1);
	dollared_line = keep_if_dollar(clean_line);
	// if (clean_list(tokens))
	// 	return (1);
	return (0);
}
