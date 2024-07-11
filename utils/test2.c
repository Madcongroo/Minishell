//
//
//
//
//
//
//

#include "../minishell.h"

char	*get_simple_word(char *line, int i, int *j)
{
	int		for_mallloc;
	char	*n_line;

	for_mallloc = 0;
	while (for_mallloc == ' ')
		for_mallloc++;
	n_line = (char *)malloc(sizeof(char) * (i - for_mallloc));
	if (!n_line)
		return (NULL);

}

char	*get_single_word(char *line, int i)
{
	char		*word;
	static int	idx = -1;
	int			j;

	j = 0;
	while (line[++idx] == ' ')
	{}
	if (i - idx <= 0)
		return (NULL);
	word = (char *)malloc(sizeof(char) * (i - idx));
	if (!word)
		return (NULL);
	while (line[idx])
	{
		word[j] = line[idx];
		j++;
	}
	word[j] = '\0';
	return (word);
}

// int	claculate_word_length(char *line, int i, char c)
// {
// 	int			j;
// 	static int	idx = -1;

// 	j = -1;
// 	if (line[i - 1]  == ' ')
// 	{
// 		while (line[++idx] != c)
// 		idx++;
// 	}
// }

int	check_after_quotes(char *line, int i, char c)
{
	int	count;

	count = 0;
	if (line[i] == 34 || line[i] == 39)
	{	
		c = line[i];
		count += 1;
		while (line[++i] != c)
		{
			
		}
	}
}

int	space_before_quote(char *line, int i, char c)
{
	int	j;

	j = 0;
	while (line[i] != c)
	{
		i++;
		j++;
	}
	if (line[i + 1] == ' ')
		return (j);
	else
	{
		i++;
		j += check_after_quotes(line, i, c);
	}
}

int	find_quote_length(char *line, int i, char c)
{
	if (i != 0)
	{
		if (line[i - 1] == ' ')
			return (space_before_quote(line, i, c));
		else if (line[i - 1] != ' ')
			return (no_space_before_quote(line, i, c));
	}
	else
		return (space_before_quote(line, i, c));
}

char	*handle_quotes(char *line, int i, char c)
{
	char		*word;
	static int	idx = -1;

	if (i != 0)
	{
		if (line[i - 1] != ' ')

	}
}

char	*cleaning_str(char *str)
{
	int		i;
	char	*clean_str;
	int		quote;

	i = 0;
	quote = 0;
	while (str[i] && (str[i] != 34 && str[i] != 39))
		i++;
	if (str[i] == '\0')
		return (str);
	i = -1;
	while (str[++i])
	{
		if (str[i] == 34 || str[i] == 39)
			
	}
}

void	ft_get_words(char *line, t_token **token)
{
	int		i;
	int		trigger;
	char	**array;
	char	**clean_array;

	i = -1;
	trigger = is_there_quotes(line);
	if (trigger == 0)
		array = ft_split(line, ' ');
	else if (trigger = 1 && (line[i] == 34 || line[i] == 39
		|| line[i] == ' ' || line[i] == '\0'))
			array = handle_quotes(line, i, line[i]);
	else if (trigger == -1)
		return (NULL);
	clean_array = cleanig_array(array);
	free(array);
	if (clean_array)
	{
		while (clean_array[++i])	
			new_node(token, 0, clean_array[i]);
	}
}
