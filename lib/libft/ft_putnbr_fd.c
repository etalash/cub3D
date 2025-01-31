/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:33:13 by stalash           #+#    #+#             */
/*   Updated: 2024/03/19 12:16:25 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd);
void	ft_combination_com(int nb, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd ("-2147483648", fd);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar_fd ('-', fd);
		n *= -1;
	}
	ft_combination_com (n, fd);
}

void	ft_combination_com(int nb, int fd)
{
	int		y;
	char	x;

	if (nb < 10)
	{
		ft_putchar_fd (nb + '0', fd);
	}
	else if (nb >= 10)
	{
		x = nb % 10;
		y = nb / 10;
		ft_combination_com (y, fd);
		ft_putchar_fd (x + '0', fd);
	}
}
