/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:45:09 by bproton           #+#    #+#             */
/*   Updated: 2023/10/31 14:00:52 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*des;
	const char		*sr;

	i = 0;
	if (!src && !dest)
		return (dest);
	des = dest;
	sr = src;
	while (i < n)
	{
		des[i] = sr[i];
		i++;
	}
	return (des);
}
/*int main(void)
{
	char src[] = "salutsddgad";
	char dest[] = "sssss";

	printf("%s", ft_memcpy(dest, src, 5));
}*/
