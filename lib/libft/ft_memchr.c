/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:51:23 by stalash           #+#    #+#             */
/*   Updated: 2024/03/19 12:03:20 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return (&ptr[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
//     char *str = "Hello World";
// 	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};

//     char *ptr = ft_memchr(str, 'o', sizeof(str));
// 	printf("%s", (char *)ft_memchr(tab, -1, 7));

//     printf("%ld",str - ptr );
//     return (0);
// }
