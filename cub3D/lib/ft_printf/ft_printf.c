/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:40:00 by stalash           #+#    #+#             */
/*   Updated: 2024/03/27 12:40:00 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += (ft_putchar((va_arg(args, int))));
	else if (format == 's')
		count += (ft_putstr((va_arg(args, char *))));
	else if (format == 'd' || format == 'i')
		count += (ft_putnbr((va_arg(args, int)), 10, 0));
	else if (format == 'x')
		count += (ft_putnbr(va_arg(args, unsigned int), 16, 0));
	else if (format == 'X')
		count += (ft_putnbr(va_arg(args, unsigned int), 16, 1));
	else if (format == 'p')
		count += (print_pointer(va_arg(args, void *)));
	else if (format == 'u')
		count += (ft_putnbr(va_arg(args, unsigned int), 10, 0));
	else if (format == '%')
		count += (ft_putchar('%'));
	return (count);
}

static int	process_format(va_list args, const char *str, int *i, int *length)
{
	int	check;

	if ((str[*i] == '%') && (ft_strchr("cspdiuxX%", str[*i + 1])))
	{
		check = ft_format(args, str[*i + 1]);
		if (check == -1)
			return (-1);
		*length += check;
		(*i)++;
	}
	else
	{
		check = ft_putchar(str[*i]);
		if (check == -1)
			return (-1);
		*length += check;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		length;
	int		check;

	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i])
	{
		check = process_format(args, str, &i, &length);
		if (check == -1)
		{
			va_end(args);
			return (-1);
		}
		i++;
	}
	va_end(args);
	return (length);
}
