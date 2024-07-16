//
//
//
//
//

// #include "../minishell.h"

// char	*get_simple_word(char *line, int i, int *j)
// {
// 	int		for_mallloc;
// 	char	*n_line;

// 	for_mallloc = 0;
// 	while (for_mallloc == ' ')
// 		for_mallloc++;
// 	n_line = (char *)malloc(sizeof(char) * (i - for_mallloc));
// 	if (!n_line)
// 		return (NULL);

// }

// char	*get_single_word(char *line, int i)
// {
// 	char	*word;
// 	int		j;
// 	int		n;

// 	j = 0;
// 	n = 0;
// 	while (line[j] == ' ')
// 		j++;
// 	if (i - j <= 0)
// 		return (NULL);
// 	word = (char *)malloc(sizeof(char) * (i - j));
// 	if (!word)
// 		return (NULL);
// 	while (line[j])
// 	{
// 		word[n] = line[j];
// 		n++;
// 		j++;
// 	}
// 	word[n] = '\0';
// 	return (word);
// }

// int	claculate_word_length(char *line, int i, char c)
// {
// 	if (line[i]  == ' ')
// 	{
		
// 	}
// 	else
// 	{

// 	}
// }

// char	*handle_quotes(char *line, int i, char c)
// {
// 	char		*word;
// 	int			len;
// 	int			n;
// 	static int	idx = 0;

// 	len = 0;
// 	n = 0;
// 	if (c == ' ')
		
// 	if (c != ' ')
// 		len = calculate_word_length(line, i, c);
// 	word = (char *)malloc(sizeof(char) * (i - len));
// 	if (!word)
// 		return (NULL);
// 	word[n] = '\0';
// 	return (word);
// }

// char	**ft_get_words(char *line, t_token **token)
// {
// 	int		i;
// 	int		trigger;
// 	char	*array;
// 	int		j;

// 	i = -1;
// 	trigger = is_there_quotes(line);
// 	while (line[++i])
// 	{
// 		j = 0;
// 		if (trigger == 0 && (line[i] == ' ' || line[i] == '\0'))
// 			array = get_single_word(line + j, i - j);
// 		else if (trigger = 1 && (line[i] == 34 || line[i] == 39
// 			|| line[i] == ' ' || line[i] == '\0'))
// 			array = handle_quotes(line, i, line[i]);
// 		else if (trigger == -1)
// 			return (NULL);
// 		if (array)
// 		{
// 			new_node(token, 0, array);
// 			i += j;
// 		}
// 	}
// 	return (array);
// }
