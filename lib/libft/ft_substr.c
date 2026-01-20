/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:35:04 by stalash           #+#    #+#             */
/*   Updated: 2024/03/19 13:21:29 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	total_len;
	char	*ptr;
	size_t	lenght;
	size_t	j;

	lenght = len;
	total_len = ft_strlen(s);
	if (total_len < start + len)
		lenght = total_len - start;
	if (total_len <= start)
		lenght = 0;
	ptr = (char *)malloc((lenght + 1) * (sizeof (char)));
	if (ptr == NULL)
		return (NULL);
	ptr[lenght] = '\0';
	if (lenght == 0)
		return (ptr);
	j = 0;
	while (s[start] != '\0' && len > j && lenght != 0)
	{
		ptr[j] = s[start];
		j++;
		start++;
	}
	return (ptr);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     char str[] = "42 is a good palce to learn codes ";
//     printf("from my maded function  = %s\n", ft_substr(str, 8, 10));
//     return (0);
// }
