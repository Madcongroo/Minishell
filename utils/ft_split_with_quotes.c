//
//
//
//
//
//
//

#include "../minishell.h"

int	find_quoted_word_length(const char *s, int i)
{
	char	c;
	int		j;

	j = i;
	c = s[i];
	i++;
	while (s[i] != c)
		i++;
	return (i - j);
}

static	size_t	ft_wordcount(const char *s, char c)
{
	size_t	i;
	size_t	wcnt;
	char	quote;

	i = 0;
	wcnt = 0;
	quote = 'v';
	while (s[i] != '\0')
	{
		if (s[i] == 34 || s[i] == 39)
			{
				quote = s[i];
				while (s[++i] != quote)
				{
				}
			}
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			wcnt++;
		i++;
	}
	return (wcnt);
}

static	char	*ft_printwords(const char *s, size_t word)
{
	size_t	j;
	size_t	i;
	char	*str;

	j = 0;
	i = -1;
	str = (char *)malloc(sizeof(char) * (word + 1));
	if (!str)
		return (NULL);
	while (++i < word)
	{
		str[j] = s[i];
		j++;
	}
	str[j] = '\0';
	// return (cleaning_str(str));
	return (str);
}

static	char	**ft_wordlength(char **str, const char *s, char c, size_t j)
{
	size_t	sep;
	size_t	word;
	size_t	i;
	int		quote;

	sep = 0;
	i = -1;
	while (++i < j)
	{
		word = 0;
		while (s[sep] == c)
			sep++;
		while (s[sep + word] != c && s[sep + word])
		{
			quote = 0;
			if (s[sep + word] == 34 || s[sep + word] == 39)
				quote = find_quoted_word_length(s, sep + word);
			if (quote != 0)
				word += quote;
			word++;
		}
		str[i] = ft_printwords(s + sep, word);
		sep += word;
	}
	return (str);
}

static	void	ft_free(char **str, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_split_with_quotes(char const *s, char c)
{
	size_t	j;
	char	**str;

	if (s == NULL)
		return (NULL);
	j = ft_wordcount(s, c);
	str = (char **)malloc(sizeof(char *) * (j + 1));
	if (!str)
		return (NULL);
	str = ft_wordlength(str, s, c, j);
	if (!str)
		ft_free(str, j);
	str[j] = NULL;
	return (str);
}
