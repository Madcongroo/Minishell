/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:12:56 by bproton           #+#    #+#             */
/*   Updated: 2024/07/23 17:49:46 by proton           ###   ########.fr       */
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
		exit (1);
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