/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:27:45 by bproton           #+#    #+#             */
/*   Updated: 2023/11/02 11:17:42 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	c = '0';
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		(n *= -1);
		write (fd, "-", 1);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	if (n < 10 && n != -2147483648)
	{
		n += c;
		write (fd, &n, 1);
	}
}
/*int	main(void)
{
	int fd = 1;

	ft_putnbr_fd(-4353, fd);
}*/