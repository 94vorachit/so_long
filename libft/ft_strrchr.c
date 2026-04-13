/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:04:04 by vorhansa          #+#    #+#             */
/*   Updated: 2025/09/03 16:50:13 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == (char) c)
			return ((char *) s + i);
		i--;
	}
	return (NULL);
}

// int main()
// {
//     // initializing string
//     char str[] = "GeeksforGeeks";

//     // character to be searched
//     char chr = '\0';

//     // Storing pointer returned by
//     char* ptr = ft_strrchr(str, chr);
// 	printf("Result of strchr: %s\n", ptr);
//     // getting the position of the character
//     if (ptr) {
//         printf("Last occurrence of %c in %s is at index %d",
//                chr, str, ptr - str);
//     }
//     // condition for character not present
//     else {
//         printf("%c is not present in %s ", chr, str);
//     }
//     return 0;
// }