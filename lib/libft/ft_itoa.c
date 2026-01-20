/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:21:31 by stalash           #+#    #+#             */
/*   Updated: 2024/03/19 12:02:14 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digits(int n)
{
	int	length;
	int	temp;

	length = 0;
	temp = n;
	if (temp == 0)
	{
		length++;
		return (length);
	}
	while (temp != 0)
	{
		length++;
		temp /= 10;
	}
	return (length);
}

int	get_sign(int n)
{
	int	sign;

	if (n < 0)
		sign = 1;
	else
		sign = 0;
	return (sign);
}

void	convert_to_string(char *str, int n, int length, int sign)
{
	int	i;
	int	digit;

	i = length - 1;
	while (i >= 0)
	{
		digit = n % 10;
		if (digit < 0)
			digit = -digit;
		str[i + sign] = '0' + digit;
		n /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	int		sign;
	int		length;
	char	*str;

	sign = get_sign(n);
	length = count_digits(n);
	str = (char *)malloc(length + sign + 1);
	if (str == NULL)
		return (NULL);
	else if (str != NULL)
	{
		if (sign)
			str[0] = '-';
		convert_to_string(str, n, length, sign);
		str[length + sign] = '\0';
	}
	return (str);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     char *str = ft_itoa(0);
//     printf("%s", str);
//     free(str);
//     return (0);
// }
