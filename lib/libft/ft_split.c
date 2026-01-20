/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stalash <stalash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:24:25 by stalash           #+#    #+#             */
/*   Updated: 2024/03/19 17:51:25 by stalash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static size_t	ft_word_length(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*ft_extract_word(const char *s, char c)
{
	size_t	len;
	char	*word;
	size_t	i;

	len = ft_word_length(s, c);
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static char	**ft_extract_words(const char *s, char c, int word_count)
{
	char	**words;
	int		i;

	words = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		words[i] = ft_extract_word(s, c);
		if (!words[i])
		{
			while (i-- > 0)
				free(words[i]);
			free(words);
			return (NULL);
		}
		s += ft_word_length(s, c);
		i++;
	}
	words[word_count] = NULL;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**empty;
	int		word_count;

	if (!s || !*s)
	{
		empty = (char **)malloc(1 * sizeof(char *));
		if (empty)
			empty[0] = NULL;
		return (empty);
	}
	word_count = ft_word_count(s, c);
	if (word_count == 0)
	{
		empty = (char **)malloc(1 * sizeof(char *));
		if (empty)
			empty[0] = NULL;
		return (empty);
	}
	return (ft_extract_words(s, c, word_count));
}

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int main()
// {
//     // const char *s1 = "hello!";
// 	const char *s2 = "hello!zzzzzzzz";
//     char c = 'z';

//     char **words = ft_split(s2, c);
//     if (words == NULL) {
//         printf("Memory allocation failed.\n");
//         return 1;
//     }

//     for (size_t i = 0; words[i] != NULL; i++) {
//         printf("Word %zu: %s\n", i, words[i]);
//         free(words[i]);
//     }
//     free(words);

//     return 0;
// }
