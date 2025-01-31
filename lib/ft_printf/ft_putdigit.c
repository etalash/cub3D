/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:46:03 by stalash           #+#    #+#             */
/*   Updated: 2024/03/27 13:46:03 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hexa(unsigned long long val, int base, char *str)
{
	int	count;
	int	check;

	count = 0;
	if (val >= (unsigned long long)base)
	{
		check = print_hexa((val / base), base, str);
		if (check == -1)
			return (-1);
		count += check;
	}
	if (write(1, &str[val % base], 1) == -1)
		return (-1);
	return (count + 1);
}

int	ft_putnbr(long long nb, int base, int uppercase)
{
	int		count;
	char	*symbol;

	count = 0;
	if (uppercase == 1)
		symbol = "0123456789ABCDEF";
	else
		symbol = "0123456789abcdef";
	if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		nb = -nb;
		count++;
	}
	return (count += print_hexa(nb, base, symbol));
}

int	print_pointer(void *ptr)
{
	char				*symbol;
	unsigned long long	int_val;
	int					count;
	int					check;

	symbol = "0123456789abcdef";
	int_val = (unsigned long long)ptr;
	count = 0;
	count += write(1, "0x", 2);
	if (count == -1)
		return (-1);
	if (int_val == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (count + 1);
	}
	check = print_hexa(int_val, 16, symbol);
	if (check == -1)
		return (-1);
	return (count + check);
}
