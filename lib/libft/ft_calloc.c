/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:59:36 by stalash           #+#    #+#             */
/*   Updated: 2024/03/19 11:55:51 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	total;
	void			*ptr;
	unsigned int	i;

	total = count * size;
	ptr = (char *)malloc(total);
	i = 0;
	if (ptr != NULL)
	{
		while (i < total)
		{
			*((char *)ptr + i) = 0;
			i++;
		}
	}
	return (ptr);
}

// #include <stdio.h>

// int main(void)
// {
//     size_t i = 5;

//     char *ptr;

//     ptr = ft_calloc(5, sizeof(i));

//     printf("Result is : ");
//     for (int g = 0; g < 5; g++)
//     {
//         printf("%d", *((char *)ptr + g));
//     }
//     printf("\n");

//     // Free the allocated memory
//     free(ptr);

//     return (0);
// }
