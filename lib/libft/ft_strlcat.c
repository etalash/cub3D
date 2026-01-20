/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:47:34 by stalash           #+#    #+#             */
/*   Updated: 2024/03/19 13:12:55 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	total_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	total_len = dst_len + src_len;
	i = dst_len;
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (*src && i < dstsize - 1)
	{
		dst[i] = *src;
		src++;
		i++;
	}
	dst[i] = '\0';
	return (total_len);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char dest1[14] = "a";
// 	char dest2[10] = "a";
// 	char dest3[10] = "a";

// 	printf("%zu\n", ft_strlcat(dest1, "lorem ipsum dolor sit amet", 15));
// 	printf("%zu\n" , ft_strlcat(dest2, "lorem ipsum dolor sit amet", 0));
// 	printf("%zu\n", ft_strlcat(dest3, "lorem ipsum dolor sit amet", 1));

// 	return (0);
// }
