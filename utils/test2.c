//
//
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
// 	char		*word;
// 	static int	idx = -1;
// 	int			j;

// 	j = 0;
// 	while (line[++idx] == ' ')
// 	{}
// 	if (i - idx <= 0)
// 		return (NULL);
// 	word = (char *)malloc(sizeof(char) * (i - idx));
// 	if (!word)
// 		return (NULL);
// 	while (line[idx])
// 	{
// 		word[j] = line[idx];
// 		j++;
// 	}
// 	word[j] = '\0';
// 	return (word);
// }

// // int	claculate_word_length(char *line, int i, char c)
// // {
// // 	int			j;
// // 	static int	idx = -1;

// // 	j = -1;
// // 	if (line[i - 1]  == ' ')
// // 	{
// // 		while (line[++idx] != c)
// // 		idx++;
// // 	}
// // }

// int	check_after_quotes(char *line, int i, char c)
// {
// 	int	count;

// 	count = 0;
// 	if (line[i] == 34 || line[i] == 39)
// 	{	
// 		c = line[i];
// 		count += 1;
// 		while (line[++i] != c)
// 		{
			
// 		}
// 	}
// }

// int	space_before_quote(char *line, int i, char c)
// {
// 	int	j;

// 	j = 0;
// 	while (line[i] != c)
// 	{
// 		i++;
// 		j++;
// 	}
// 	if (line[i + 1] == ' ')
// 		return (j);
// 	else
// 	{
// 		i++;
// 		j += check_after_quotes(line, i, c);
// 	}
// }

// int	find_quote_length(char *line, int i, char c)
// {
// 	if (i != 0)
// 	{
// 		if (line[i - 1] == ' ')
// 			return (space_before_quote(line, i, c));
// 		else if (line[i - 1] != ' ')
// 			return (no_space_before_quote(line, i, c));
// 	}
// 	else
// 		return (space_before_quote(line, i, c));
// }

// int	new_value_to_malloc(char *str)
// {
// 	int		i;
// 	char	c;
// 	int		quote;

// 	i = -1;
// 	quote = 0;
// 	while (str[++i])
// 	{
// 		if (str[i] == 34 || str[i] == 39)
// 		{
// 			quote++;
// 			c = str[i];
// 			i++;
// 			while (str[i] != c)
// 				i++;
// 			quote++;
// 		}
// 	}
// 	return (i - quote);
// }

// char	*copy_str(char *str, int mall)
// {
// 	char	*clean_str;
// 	int		i;
// 	int		j;
// 	char	c;

// 	clean_str = malloc(sizeof(char) * (mall + 1));
// 	if (!clean_str)
// 		return (NULL);
// 	j = -1;
// 	i = -1;
// 	c = 'v';
// 	while (str[++i])
// 	{
// 		if (str[i] == 34 || str[i] == 39)
// 		{
// 			c = str[i];
// 			while (str[++i] != c)
// 				clean_str[j++] = str[i];
// 			i++;
// 		}
// 		clean_str[j] = str[i];
// 		j++;
// 	}
// 	return (clean_str);
// }

// char	*cleaning_str(char *str)
// {
// 	int		i;
// 	char	*clean_str;
// 	int		mall;

// 	i = 0;
// 	while (str[i] && (str[i] != 34 && str[i] != 39))
// 		i++;
// 	if (str[i] == '\0')
// 		return (str);
// 	mall = new_value_to_malloc(str);
// 	clean_str = copy_str(str, mall);
// 	if (!clean_str)
// 		return (NULL);
// 	free(str);
// 	return (clean_str);
// }

// void	ft_get_words(char *line, t_token **token)
// {
// 	int		i;
// 	int		trigger;
// 	char	**array;
// 	char	*clean_str;

// 	i = -1;
// 	trigger = is_there_quotes(line);
// 	if (trigger == 0)
// 		array = ft_split(line, ' ');
// 	else if (trigger = 1 && (line[i] == 34 || line[i] == 39
// 		|| line[i] == ' ' || line[i] == '\0'))
// 			array = ft_split_with_quotes(line, ' ');
// 	else if (trigger == -1)
// 		return (NULL);
// 	while (array[++i])
// 	{
// 		array[i] = cleaning_str(array[i]);
// 		if (!array[i])
// 			return (NULL);
// 		new_node(token, 0, array[i]);
// 	}	
// }
