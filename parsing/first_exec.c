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

/// @brief fonction qui renvoie -1 si il y a un probleme,
// 0 si il n y a pas de problemes et 1 si il y a des quotes a genrer
/// @param char *
/// @return -1 == probleme, 0 == pas probleme, 1 == quotes
int		is_line_tokenable(char *line)
{
	int	i;
	int	quote_count;

	i = -1;
	quote_count = 0;
	if (!line)
		return (-1);
	while (line[i])
	{
		if (line[i] == 39 || line[i] == 34)
			quote_count += 1;
	}
	if (quote_count % 2 == 1)
		return (-1);
	else if (quote_count % 2 == 0 && quote_count != 0)
		return (1);
	else
		return (0);
}

char	*ft_get_word(char *line)
{
	int		i;
	char	*word;

	i = -1;
	while (line[i] != ' ' && line[i] != '\n')
		i++;
	word = (char *)malloc(sizeof(char) * i + 1);
	i = -1;
	while (line[i] != ' ' && line[i] != '\n')
	{

	}
}

t_tocken	*find_last_node(t_tocken *tocken)
{
	t_tocken	*temp;

	temp = tocken;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	new_node(t_tocken **tocken, int status, char *arg)
{
	t_tocken	*new_node;

	new_node = (t_tocken *)malloc(sizeof(t_tocken));
	if (!new_node)
		return ;
	if (!(*tocken))
		(*tocken) = new_node;
	else
		find_last_node(tocken)->next = new_node;
	new_node->next = NULL;
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
			word = ft_get_word(line);
	}
}

