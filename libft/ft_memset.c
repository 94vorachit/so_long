/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:24:53 by vorhansa          #+#    #+#             */
/*   Updated: 2025/09/01 16:41:50 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// NAME
//     memset -- fill a byte string with a byte value
// SYNOPSIS
//     void *memset(void *s, int c, size_t len);
// DESCRIPTION
//     The memset() function writes len bytes of value c 
//     (converted to an unsigned char) to the string s.
// RETURN VALUES
//     The memset() function returns its first argument.

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}

// int	main(void)
// {
// 	char	str1[17] = "I am your father";
// 	printf("-----memset()-----\n");
// 	printf("Before memset(): %s\n", str1);
// 	memset(str1 + 8, 'x', 5);
// 	printf("After memset(): %s\n\n", str1);
// 	char	str2[17] = "I am your father";
// 	printf("-----ft_memset()-----\n");
// 	printf("Before ft_memset(): %s\n", str2);
// 	ft_memset(str2 + 8, '.', 5);
// 	printf("After ft_memset(): %s\n", str2);
// }