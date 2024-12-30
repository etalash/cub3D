/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:42:52 by stalash           #+#    #+#             */
/*   Updated: 2024/03/19 13:20:19 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[i])
	{
		i++;
	}
	while (i >= 0)
	{
		if ((char)c == str[i])
			return (str + i);
		i--;
	}
	return (0);
}

// #include <stdio.h>

// int main(void)
// {
//     const char *str = "computer science";
//     int p = 'c';
//     printf("the last occurrence of the %c in
// 	the %s is %s", p, str, ft_strrchr(str, p));
//     return (0);
// }
