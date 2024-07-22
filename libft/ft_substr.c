/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:50:49 by bproton           #+#    #+#             */
/*   Updated: 2023/11/02 13:16:25 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ns;
	size_t	i;
	size_t	lens;

	if (!s || start >= ft_strlen(s))
		return (ft_strdup(""));
	lens = ft_strlen(s + start);
	if (lens < len)
		len = lens;
	i = 0;
	ns = malloc(sizeof(char) * len + 1);
	if (ns == NULL)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		ns[i] = s[start];
		start++;
		i++;
	}
	ns[i] = '\0';
	return (ns);
}
/*int main(void)
{
	char s[] = "0123456789";
	char *s1;

	s1 = ft_substr(s, 9, 10);
	printf("%s", s1);
	free(s1);
}*/