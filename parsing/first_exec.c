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

/*trigger a 1 dans ce cas : mot' 'mot (output = 1 mot)
  trigger a 2 dans ce cas : mot ' 'mot (output = 2 mots)
  trigger a 3 dans ce cas : mot' ' mot (output = 2 mots)
  trigger a 4 dans ce cas : mot ' ' mot (output = 3 mots)
  meme chose avec les doubles guillemets.
*/

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

// char	*first_line_cut(char *line, int i, char c, int quote)
// {
// 	static int	j = 0;
// 	int			space;

	
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

// char	**ft_get_words(char *line)
// {
// 	int		i;
// 	char	c;
// 	int		trigger;
// 	char	**array;

// 	i = 0;
// 	trigger = is_there_quotes(line);
// 	if (trigger == 0)
// 		array = ft_split(line, ' ');
// 	else if (trigger = 1)
// 		array = ft_split_with_quotes(line, ' ');
// 	else
// 		return (NULL);
// 	return (array);
// }

// void	lexing_words(t_token **tokens, char *line)
// {
// 	char	**words;
// 	int		i;

// 	if (!line)
// 		return ;
// 	words = ft_get_words(line);
// 	if (!words)
// 		return ;
// 	i = -1;
// 	while (words[++i])
// 	{
// 		if (!new_node(tokens, 0. words[i]))
// 			free_list(tokens);
// 	}
// }
