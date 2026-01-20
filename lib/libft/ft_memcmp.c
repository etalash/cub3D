/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:49:58 by stalash           #+#    #+#             */
/*   Updated: 2024/03/19 12:03:27 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *str1 = "Hel1o";
// 	char *str2 = "Hello";

// 	printf("%d\n", ft_memcmp(str1, str2, 5));
// 	printf("%d\n", ft_memcmp("abcdefghij", "abcdefgxyz", 7));
// 	printf("%d\n", ft_memcmp("zyxbcdefgh", "abcdefgxyz", 0));
// 	return (0);
// }
