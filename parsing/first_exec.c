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



/// @brief voir si la premiere quote correspond a la derniere quote
/// @param char *
int	is_quote_closed_with_same_quote(char *line)
{
	int		i;
	char	first_quote;
	char	last_quote;

	i = 0;
	first_quote = 'i';
	last_quote = 'c';
	while (line[i] == 39 || line[i] == 34)
	{
		first_quote == line[i];
		i++;
	}
	i = 0;
	while (line[i])
	{
		if (line[i] == 39 || line[i] == 34)
			last_quote == line[i];
		i++;
	}
	if (first_quote != last_quote);
		return (1);
	return (0);
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
			quote_count += 1;
	}
	if (is_quote_closed_with_same_quote(line))
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
	int	i;

	i = -1;
	while (line[i])
	{
		
	}
}
