/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:32:49 by bproton           #+#    #+#             */
/*   Updated: 2023/11/06 11:45:59 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	t;
	size_t	re_i;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (i < n && haystack[i])
	{
		t = 0;
		if (haystack[i] == needle[t])
		{
			re_i = i;
			while (haystack[i] == needle[t] && needle[t] && i < n)
			{
				i++;
				t++;
			}
			if (!needle[t])
				return ((char *)haystack + re_i);
			i = re_i;
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	const char haystack[] = "je vais bien";
	const char needle[] = "ais";

	printf("%s", ft_strnstr("fake", ((void *)0), 3));
}*/