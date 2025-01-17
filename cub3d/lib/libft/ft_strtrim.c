/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:59:34 by stalash           #+#    #+#             */
/*   Updated: 2024/03/19 13:21:01 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_in_set(char c, char const *set);
char	*for_malloc(size_t n, size_t start, char const *str);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*trimmed_str;

	start = 0;
	end = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = start;
	while (s1[end])
		end++;
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	len = end - start;
	trimmed_str = for_malloc(len, start, s1);
	return (trimmed_str);
}

int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*for_malloc(size_t n, size_t start, char const *str)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)malloc((n + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		ptr[i] = str[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// #include <stdio.h>
// int main() {
//     char const *s1 = "bababbaHello, world!ababba";
//     char const *set = "ab";
//     char *trimmed_str = ft_strtrim(s1, set);
//     if (trimmed_str) {
//         printf("Trimmed string: \"%s\"\n", trimmed_str);
//         free(trimmed_str);
//     } else {
//         printf("Memory allocation failed.\n");
//     }
//     return 0;
// }
