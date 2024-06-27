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
int	search_quote_pattern(char *line, int quote, char c)
{
	int	trigger;

	trigger = 0;
	if (line[quote - 1] == ' ')
		trigger += 2;
	else if (line[quote - 1] != ' ')
		trigger += 1;
	quote++;
	while (line[quote] != c || line[quote])
		quote++;
	if (line[quote + 1] == ' ')
		trigger += 2;
	else if (line[quote + 1] == ' ')
		trigger += 2;
	return (trigger);
}

char	*first_line_cut(char *line, int *i, char c, int quote)
{
	int			i;
	static int	j;

	i = 0;
	while (line[i] == ' ')
		i++;
	n_line = split_for_token(line, ' ');
	if (!n_line)
		return (1);
	
}

char	*ft_get_words(char *line)
{
	
}

void	lexing_words(t_tocken **tockens, char *line)
{
	char	*word;
	int		i;
	int		quote;
	
	quote = 0;
	if (!line)
		return ;
	i = -1;
	while (line[i])
	{
		if (line[i] == "'" || line[i] == '"' || line[i] == ' ')
		{
			if (line[i] == 34 || line[i] == 39)
				quote = search_quote_pattern(line, i, line[i]);
			word = first_line_cut(line, &i, line[i], quote);
		}
		i++;
	}
	
}
