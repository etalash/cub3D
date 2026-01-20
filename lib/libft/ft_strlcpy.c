/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:34:49 by stalash           #+#    #+#             */
/*   Updated: 2024/03/19 13:15:39 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	copylen;
	size_t	j;

	i = 0;
	while (src[i] != '\0')
		i++;
	if (dstsize == 0)
		copylen = 0;
	else if (dstsize - 1 < i)
		copylen = dstsize - 1;
	else
		copylen = i;
	j = 0;
	while (j < copylen)
	{
		dst[j] = src[j];
		j++;
	}
	if (dstsize > 0)
		dst[copylen] = '\0';
	return (i);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	// char	src[] = {"Deutschland"};
// 	char	dest[] = "";

// 	printf ("%zu", ft_strlcpy(dest, "lorem ipsum dolor sit amet", 0));
// 	return (0);
// }
