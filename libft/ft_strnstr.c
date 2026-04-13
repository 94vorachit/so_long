/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:11:55 by vorhansa          #+#    #+#             */
/*   Updated: 2025/09/10 16:23:47 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == 0)
		return ((char *) big);
	while (big[i] && i < len)
	{
		while (big[i + j] == little[j] && big[i + j] && i + j < len)
		{
			j++;
			if (little[j] == 0)
				return ((char *) big + i);
		}
		i++;
		j = 0;
	}
	return (0);
}

// int	main()
// {
// 	char s1[] = "GeeksforGeeks";
//     char s2[] = "for";
//     char* p;
// 	int	len;

//     // Find first occurrence of s2 in s1
// 	len = 8;
//     p = ft_strnstr(s1, s2, len);

//     // Prints the result
//     if (p) 
// 	{
//         printf("String found\n");
//         printf("First occurrence of string '%s' in '%s' in length '%d' is "
//                "'%s'", s2, s1, len, p);
//     }
//     else
//         printf("String not found\n");

//     return 0;
// }