/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:25:40 by bproton           #+#    #+#             */
/*   Updated: 2023/10/31 15:14:58 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *srcs, size_t n)
{
	unsigned char	*des;
	unsigned char	*src;

	des = (unsigned char *)dest;
	src = (unsigned char *)srcs;
	if (!srcs && !dest)
		return (dest);
	if (dest < srcs)
		return (ft_memcpy(dest, srcs, n));
	while (n--)
		des[n] = src[n];
	return (des);
}
/*int main(void)
{
	char dest[] = "salut";
	char src[] = "babbu";
	char *s;

	s = ft_memmove(dest, src, 4);
	printf("%s", s);
}*/