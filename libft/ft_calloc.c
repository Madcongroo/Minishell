/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:36:36 by bproton           #+#    #+#             */
/*   Updated: 2023/11/06 11:04:56 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elnum, size_t elsize)
{
	void	*s;

	s = malloc(elnum * elsize);
	if (s == NULL)
		return (NULL);
	ft_memset(s, 0, elnum * elsize);
	return (s);
}
/*int main(void)
{
	int *arr;

	arr = (int*)ft_calloc(5, sizeof(int));
	if (arr == NULL)
		printf("opperation a echoue");
	else
		printf("opperation reussie");
	free(arr);
}*/
