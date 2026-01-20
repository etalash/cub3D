/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:24:16 by stalash           #+#    #+#             */
/*   Updated: 2024/03/21 11:51:30 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// int main() {
//     char x[] = "abcdefghi";
//     memcpy(&x[3], &x[0], 6);
//     printf("after the original function: %s\n", x);
//     char y[] = "abcdefghi";
//     ft_memcpy(&y[3], &y[0], 6);
//     printf("after my function:  %s\n", y);
// }
