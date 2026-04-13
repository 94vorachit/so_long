/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:34:39 by vorhansa          #+#    #+#             */
/*   Updated: 2026/02/23 18:51:41 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*wordstart;
	int		i;

	res = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			wordstart = (char *)s;
			while (*s != c && *s)
				s++;
			res[i] = ft_substr(wordstart, 0, s - wordstart);
			if (!res[i])
				return (ft_free(res));
			i++;
		}
		else
			s++;
	}
	res[i] = NULL;
	return (res);
}

// int	main(void)
// {
// 	char	s1[] = "Words .to  .be   .splitted    .in     .six      ";
// 	char	s2;
// 	char	**words;
// 	int		i;

// 	s2 = '.';
// 	words = ft_split(s1, s2);
// 	i = 0;
// 	printf("Before: [%s]\nSplitter: [%c]\nAfter: \n", s1, s2);
// 	while (words[i])
// 	{
// 		printf("words[%d] : [%s]\n", i, words[i]);
// 		free(words[i]);
// 		i++;
// 	}
// 	printf("-------------------------------------------------\n");
// 	free(words);
// }