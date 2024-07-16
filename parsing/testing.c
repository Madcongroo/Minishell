//
//
//
//
//
//
//

// #include "../minishell.h"

// char	*get_clean_line(char *line)
// {
// 	int		i;
// 	char	*n_line;

// 	i = -1;
// 	while (line[i])
// 		i++;
// 	n_line = (char *)malloc(sizeof(char) * (i + 1));
// 	if (!n_line)
// 		return (NULL);
// 	i = -1;
// 	while (line[++i])
// 		n_line[i] = line[i];
// 	n_line[i] = '\0';
// 	return (n_line);
// }

// int	str_quote_length(char *line, int i, char c)
// {
// 	while (line[i] != c)
// 		i++;
// 	return (i);
// }

// int	count_word(char *line, char c)
// {
// 	static int	i = 0;
// 	int			spaces;

// 	spaces = 0;
// 	while (line[spaces] == ' ')
// 		spaces++;
// 	while (line[i] != c)
// 		i++;
// 	i++;
// 	if (c == 34 || c == 39)
// 	{
// 		while (line[i] != c)
// 			i++;
// 		if (line[i + 1] == ' ')
// 	}
	
// }

// int	search_quote_pattern(char *line, int quote, char c)
// {
// 	int	trigger;

// 	trigger = 0;
// 	if (line[quote - 1] == ' ')
// 		trigger += 2;
// 	else if (line[quote - 1] != ' ')
// 		trigger += 1;
// 	quote++;
// 	while (line[quote] != c || line[quote])
// 		quote++;
// 	if (line[quote + 1] == ' ')
// 		trigger += 2;
// 	else if (line[quote + 1] == ' ')
// 		trigger += 2;
// 	return (trigger);
// }

// int	is_there_quotes(char *line)
// {
// 	int		i;
// 	int		trigger;
// 	char	c;

// 	i = 0;
// 	c = 'q';
// 	trigger = 0;
// 	while (line[i])
// 	{
// 		if (line[i] == 34 || line[i] == 39)
// 		{
// 			c = line[i];
// 			i++;
// 			while (line[i] != c || line[i])
// 				i++;
// 			if (line[i] == '\0')
// 				return (-1);
// 			trigger = 1;
// 		}
// 		i++;
// 	}
// 	return (trigger);
// }

// void	lexing_words(t_token **tokens, char *line)
// {
// 	char	*clean_line;
// 	int		i;

// 	if (!line)
// 		return ;
// 	i = -1;
// 	while (line[i] == ' ')
// 		i++;
// 	clean_line = get_clean_line(line + i);
// 	if (!clean_line)
// 		return (NULL);
// 	free(line);
// 	if (ft_get_words(clean_line, tokens))
// 		return (NULL);
// }
	
