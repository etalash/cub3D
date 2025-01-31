/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:25:00 by stalash           #+#    #+#             */
/*   Updated: 2024/03/19 13:33:05 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*str;
// 	char	x[] = {" 2 4 5 6 7 8 9"};

// 	str = &x[0];
// 	printf ("%d", ft_strlen(str));
// }
