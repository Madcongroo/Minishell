/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:09:03 by bproton           #+#    #+#             */
/*   Updated: 2023/11/01 17:04:58 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	lensrc;
	size_t	lendest;

	i = 0;
	lensrc = ft_strlen(src);
	lendest = ft_strlen(dest);
	if (n <= lendest)
		return (n + lensrc);
	while (src[i] && lendest + i < n - 1)
	{
		dest[lendest + i] = src[i];
		i++;
	}
	dest[lendest + i] = '\0';
	return (lendest + lensrc);
}
/*int main(void)
{
	char    dest[19] = "salut";
	char    src[] = "bonjour";

	printf("%zu", ft_strlcat(dest, src, 7));
}*/