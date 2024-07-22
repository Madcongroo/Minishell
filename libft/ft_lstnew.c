/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:18:11 by bproton           #+#    #+#             */
/*   Updated: 2023/11/07 14:03:43 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elm1;

	elm1 = (t_list *)malloc(sizeof(t_list));
	if (!elm1)
		return (NULL);
	elm1->content = content;
	elm1->next = NULL;
	return (elm1);
}
