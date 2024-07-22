/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:14:53 by bproton           #+#    #+#             */
/*   Updated: 2023/10/31 11:45:41 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *dest, const char *s1)
{
	size_t	i;
	size_t	t;

	i = 0;
	t = 0;
	while (s1[i] != '\0')
	{
		dest[t + i] = s1[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	o;

	i = 0;
	o = ft_strlen(s1);
	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == NULL)
		return (NULL);
	s3 = ft_strcat(s3, s1);
	while (s2[i] != '\0')
	{
		s3[o] = s2[i];
		i++;
		o++;
	}
	s3[o] = '\0';
	return (s3);
}
/*int main(void)
{
	char s1[] = "salut";
	char s2[] = " ca va";
	char *s3;

	s3 = ft_strjoin(s1, s2);
	printf("%s", s3);
	free(s3);
}*/