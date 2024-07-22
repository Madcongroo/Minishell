/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:20:53 by bproton           #+#    #+#             */
/*   Updated: 2023/11/02 11:23:08 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	*s1;

	i = 0;
	s1 = (unsigned char *)s;
	while (s1[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s1[i] == (char)c)
			return ((char *)s1 + i);
		i--;
	}
	return (NULL);
}
/*int main(void)
{
	const char str[] = "shafdfbdt";

	printf("%s", ft_strrchr(str, 'a'));
}*/