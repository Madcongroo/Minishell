/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:12:56 by bproton           #+#    #+#             */
/*   Updated: 2023/10/31 12:13:15 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int			len;
	const char	*ns;

	len = ft_strlen((char *)s) + 1;
	ns = malloc(sizeof(char) * len);
	if (!s)
		return (NULL);
	if (ns == NULL)
		return (NULL);
	ft_strlcpy((char *)ns, s, len);
	return ((char *)ns);
}
/*int main(void)
{
	char s[] = "";
	char *s1;

	s1 = ft_strdup(s);
	printf("%s", s1);
	free(s1);
}*/