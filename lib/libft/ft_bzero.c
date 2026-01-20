/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:19:15 by stalash           #+#    #+#             */
/*   Updated: 2024/03/19 11:51:03 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char			*ptr;
	unsigned int	i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

// #include <stdio.h>
// int main(void)
// {
// 	char str[13] = "42 Heilbronn";
// 	ft_bzero(str, sizeof(str));
// 	printf("Result is \t");
// 	int i;

// 	i = 0;
// 	while (i < 13)
// 	{
// 		printf("%d", str[i]);
// 		i++;
// 	}
// 	return (0);
// }
