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

void	is_quote_closed_with_same_quote(char *line)
{
	int	i;

	i = -1;
	
}


/// @brief fonction qui renvoie -1 si il y a un probleme,
/// 0 si il n y a pas de problemes et 1 si il y a des quotes a genrer
/// @param char *
/// @return -1 == probleme, 0 == pas probleme, 1 == quotes
int		is_line_tokenable(char *line)
{
	int		i;
	int		quote_count;

	i = -1;
	quote_count = 0;
	if (!line)
		return (-1);
	while (line[++i])
	{
		if (line[i] == 39 || line[i] == 34)
		{
			quote_count += 1;
			is_quote_closed_with_same_quote(line);
		}
	}
	if (quote_count % 2 == 1)
		return (-1);
	else if (quote_count % 2 == 0 && quote_count != 0)
		return (1);
	return (0);
}

char	*ft_get_words(char *line)
{
	
}

void	tokening_line(t_tocken **tockens, char *line)
{
	int		i;
	char	**word;
	int		check;

	i = -1;
	check = is_line_tokenable(line);
	if (check == -1)
		return (1);
	while (line[i])
	{
		if (check == 0)
			word = ft_split(line, ' ');
		else if (check == 1)
			word = split_with_quotes(line, ' ');
	}
}

