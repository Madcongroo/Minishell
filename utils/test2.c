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
	else if (line[i + 1] == 34 || line[i + 1] == 39)

}

int	get_quote_length(char *line, int i, char c)
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
	int			j;
	int			w_length;

	j = 0;
	while (line[++idx] == ' ')
	{}
	if (i - idx <= 0)
		return (NULL);
	if (c == 39 || c == 34)
		w_length = find_quote_length(line, i, c);
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

char	**ft_get_words(char *line, t_token **token)
{
	int		i;
	int		trigger;
	char	*array;

	i = -1;
	trigger = is_there_quotes(line);
	while (line[++i])
	{
		if (trigger == 0 && (line[i] == ' ' || line[i] == '\0'))
			array = get_single_word(line, i);
		else if (trigger = 1 && (line[i] == 34 || line[i] == 39
			|| line[i] == ' ' || line[i] == '\0'))
			array = handle_quotes(line, i, line[i]);
		else if (trigger == -1)
			return (NULL);
		if (array)
			new_node(token, 0, array);
	}
	return (array);
}
