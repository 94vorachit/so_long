/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:33:36 by vorhansa          #+#    #+#             */
/*   Updated: 2025/09/08 12:34:48 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// NAME
//     memmove -- copy byte string
// SYNOPSIS
//     void *memmove(void *dst, const void *src, size_t len);
// DESCRIPTION
//     The memmove() function copies len bytes from string src to string dst.
//     The two strings may overlap; the copy is always done in 
// 	   a non-destructive manner.
// RETURN VALUES
//     The memmove() function returns the original value of dst.

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	temp_dest = (unsigned char *) dest;
	temp_src = (unsigned char *) src;
	i = 1;
	if (temp_src < temp_dest)
	{
		while (i <= n)
		{
			temp_dest[n - i] = temp_src[n - i];
			i++;
		}
	}
	else
		ft_memcpy(temp_dest, temp_src, n);
	return (dest);
}

// int main()
// {
//     char str[100] = "Learningisfun";
//     char *first, *second;
//     first = str;
//     second = str;
//     printf("Original string :%s\n ", str);
//     // when overlap happens then it just ignore it
//     memcpy(first + 8, first, 10);
//     printf("memcpy overlap : %s\n ", str);
//     // when overlap it start from first position
//     memmove(second + 8, first, 10);
//     printf("memmove overlap : %s\n ", str);
//     return 0;
// }