/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:08:10 by stalash           #+#    #+#             */
/*   Updated: 2024/03/19 13:17:04 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*str;
	int		i;

	len = ft_strlen(s);
	str = (char *)malloc((len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[len] = '\0';
	return (str);
}

// #include <stdio.h>
// #include <stdlib.h>
// char my_function(unsigned int index, char c);
// int main()
// {
//     const char *str = "Hello, World";
//     char *result = ft_strmapi(str, &my_function);
//     printf("Original string: %s\n", str);
//     printf("Transformed string: %s\n", result);
//     free(result);
//     return 0;
// }
// char my_function(unsigned int index, char c)
// {
//     if (c >= 'a' && c <= 'z')
//     {
//         return c - 32;
//     }
//     else if (c >= 'A' && c <= 'Z')
//     {
//         return c + 32;
//     }
//     else
//     {
//         return c;
//     }
// }
