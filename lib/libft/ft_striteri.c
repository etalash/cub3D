/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:00:36 by stalash           #+#    #+#             */
/*   Updated: 2024/03/19 12:41:11 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>
// #include <stdlib.h>
// void my_function(unsigned int index, char *c);
// int main()
// {
//     char str[] = "Hello, World"; /* if we use char *str instead of char str[]
//               we have to allocate memory for it other weise it won't work! */
//     ft_striteri(str, &my_function);
//     printf("new string is: %s\n", str);
//     return 0;
// }
// void my_function(unsigned int index, char *c)
// {
//     if (*c >= 'a' && *c <= 'z')
//     {
//         *c -= 32;
//     }
//     else if (*c >= 'A' && *c <= 'Z')
//     {
//         *c += 32;
//     }
// }
