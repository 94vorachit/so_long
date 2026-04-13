/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:16:04 by vorhansa          #+#    #+#             */
/*   Updated: 2025/09/03 17:38:40 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	if (s == NULL)
		return (NULL);
	while (n--)
	{
		if (str[i] == (unsigned char) c)
			return (str + i);
		i++;
	}
	return (NULL);
}

// int main()
// {
//     // defining string and a character
//     char sr[] = "This is a sample";
//     char ch = 's';
//     int count = 2;
//     // using memchr to check for the presence of 's' in sr
// 	if (ft_memchr(sr, ch, count))
// 		printf("%c is present in first %d 
// 			characters of \"%s\"\n", ch, count, sr);
// 	else
// 		printf("%c is not present in first %d 
// 			characters of \"%s\"\n", ch, count, sr);
// 		return (0);
// }