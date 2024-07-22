/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:17:50 by bproton           #+#    #+#             */
/*   Updated: 2023/11/06 11:02:24 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isinset(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static	size_t	ft_findstart(const char *s, const char *set)
{
	size_t	i;

	i = 0;
	while (ft_isinset(s[i], set))
		i++;
	return (i);
}

static	size_t	ft_findend(const char *s, const char *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	while (i > 0 && ft_isinset(s[i - 1], set))
	{
		j++;
		i--;
	}
	return (j);
}

static	char	*ft_print(size_t len, const char *s1, char *str, size_t start)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (i < len)
		{
			str[i] = s1[start];
			start++;
			i++;
		}
		str[len] = '\0';
	}
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = ft_findstart(s1, set);
	end = ft_findend(s1, set);
	if (start == ft_strlen(s1))
	{
		str = (char *)malloc(1);
		if (str)
			str[0] = '\0';
		return (str);
	}
	len = ft_strlen(s1) - start - end;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str = ft_print(len, s1, str, start);
	return (str);
}

/*int	main(void)
{
	const char s1[] = "lorem \n ipsum \t dolor \n sit \t amet";
	char *s2;

	s2 = ft_strtrim(s1, " ");
	printf("%s", s2);
	free(s2);
}*/
/*int	main(void)
{
	const char s1[] = "  hello world  ";
	char *s2;

	s2 = ft_strtrim(s1, " ");
	printf("%s", s2);
	free(s2);
}*/