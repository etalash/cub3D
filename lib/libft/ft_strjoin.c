/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:50:08 by stalash           #+#    #+#             */
/*   Updated: 2024/03/19 13:11:51 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (s1 == NULL || s1 == NULL)
		return (NULL);
	result = (char *)ft_calloc(len, 1);
	if (result == NULL)
		return (NULL);
	ft_strlcat(result, s1, len);
	ft_strlcat(result, s2, len);
	return (result);
}

// #include <stdio.h>

// int main(void)
// {
//     char ptr1[] = "Hello ";
//     char ptr2[] = "World";

//     printf("%s", ft_strjoin(ptr1, ptr2));
//     return (0);
// }
