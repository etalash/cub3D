/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:05:46 by stalash           #+#    #+#             */
/*   Updated: 2024/03/19 12:09:24 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (ptr);
}

// #include <stdio.h>

// int main(void)
// {
//     char arry[10];

//     ft_memset(arry, 0, sizeof(arry));

//     printf("Result after from function \n");

//     int i = 0;
//     while(i <  10)
//     {
//         printf("%d", arry[i]);
//         i++;
//     }

//     return (0);
// }
