/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:52:14 by stalash           #+#    #+#             */
/*   Updated: 2024/03/19 12:19:37 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = 0;
	ch = (char)c;
	while (s[i])
	{
		if (ch == s[i])
			break ;
		s++;
	}
	if (ch == s[i])
		return ((char *)(s + i));
	else
		return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	const char str[] = "computer science";
// 	const char str1[] = "";

// 	printf("starts from %s\n", ft_strchr(str, 'p'));
// 	printf("starts from %s\n", ft_strchr(str, 'z'));
// 	printf("starts from %s\n", ft_strchr(str, '\0'));
// 	printf("starts from %s\n", ft_strchr(str1, '\0'));

// 	return (0);
// }
