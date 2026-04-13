/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:09:44 by vorhansa          #+#    #+#             */
/*   Updated: 2025/09/12 13:14:19 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	to_trim(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static	char	*new_str(const char *s1, size_t start, size_t end)
{
	char	*str;
	size_t	i;

	if (end <= 0 || start >= ft_strlen(s1))
		return (ft_strdup(""));
	str = ft_calloc(end + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < end)
	{
		str[i] = s1[start + i];
		i++;
	}
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (to_trim(set, s1[i]))
		i++;
	while (to_trim(set, s1[j]))
		j--;
	return (new_str(s1, i, j - (i - 1)));
}

// int	main()
// {
// 	char	s1[] = "abcdab abcdfab";
// 	char	s2[] = "abc";
// 	char	*res = ft_strtrim(s1, s2);
// 	printf("%s", res);
// 	free(res);
// 	return (0);
// }