//
//
//
//
//
//
//

#include "../minishell.h"

static	size_t	ft_wordcount(const char *s, char c)
{
	size_t	i;
	size_t	wcnt;

	i = 0;
	wcnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			wcnt++;
        if (s[i] == 34 || s[i] == 39)
            
		i++;
	}
	return (wcnt);
}

static	char	*ft_printwords(const char *s, char c, size_t word)
{
	size_t	j;
	char	*str;

	j = 0;
	str = (char *)malloc(sizeof(char) * word + 1);
	if (!str)
		return (NULL);
	while (*s != '\0')
	{
		while (*s != c && *s)
		{
			str[j] = *s;
			j++;
			s++;
		}
		if (*s - 1 != c && (*s == c || *s == '\0'))
		{
			str[j] = '\0';
			return (str);
		}
		s++;
	}
	str[j] = '\0';
	return (str);
}

static	char	**ft_wordlength(char **str, const char *s, char c, size_t j)
{
	size_t	sep;
	size_t	word;
	size_t	i;

	sep = 0;
	i = 0;
	while (i < j)
	{
		word = 0;
		while (s[sep] == c)
			sep++;
		while (s[sep + word] != c && s[sep + word])
			word++;
		str[i] = ft_printwords(s + sep, c, word);
		sep += word;
		i++;
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

char	**ft_split(char const *s, char c)
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
