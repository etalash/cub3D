/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:47:17 by stalash           #+#    #+#             */
/*   Updated: 2024/03/19 11:43:01 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	x;
	int	sign;
	int	out;

	x = 0;
	sign = 1;
	out = 0;
	while (str[x] && (str[x] == ' ' || (str[x] >= 9 && str[x] <= 13)))
		x++;
	if (str[x] == '-')
	{
		sign = -1 * sign;
		x++;
	}
	else if (str[x] == '+')
		x++;
	while (str[x] && (str[x] >= '0' && str[x] <= '9'))
	{
		out = out * 10 + str[x] - '0';
		x++;
	}
	return (out * sign);
}

// #include <stdio.h>

// int main()
// {
// 	const char tpt[20] = " -1234ab567";

// 	printf("%d", ft_atoi(tpt));
// 	return (0);
// }
