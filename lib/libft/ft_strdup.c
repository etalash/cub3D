/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:41:29 by stalash           #+#    #+#             */
/*   Updated: 2024/03/19 12:38:40 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(ft_strlen(s1) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     char str[] = "42 is the Best";

//     const char *ptr1 = ft_strdup(str);
//     const char *ptr2 = strdup(str);

//     printf("my function function  =  %s\n", ptr1);
//     printf("The original function  =  %s", ptr2);
//     return (0);
// }
