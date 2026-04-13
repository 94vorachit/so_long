/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:53:26 by vorhansa          #+#    #+#             */
/*   Updated: 2025/09/08 12:34:29 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// NAME
//     memcpy -- copy memory area
// SYNOPSIS
//     void *memcpy(void *dst, const void *src, size_t n);
// DESCRIPTION
//     The memcpy() function copies n bytes from memory area src to 
// 	memory area dst. If dstt and src overlap, behavior is undefined. 
// 	Applications in which dst and src might overlap should use 
// 	memove(3) instead.
// RETURN VALUES
//     The memcpy() function returns the original value of dst

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp_src;
	unsigned char	*temp_dest;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest == src)
		return (dest);
	i = 0;
	temp_dest = (unsigned char *) dest;
	temp_src = (unsigned char *) src;
	while (n > 0)
	{
		temp_dest[i] = temp_src[i];
		i++;
		n--;
	}
	return (dest);
}

// int main() 
// {
//     char str1[] = "Iamyourfather";
//     char str2[20] = "";
// 	char str3[20] = "";
//     memcpy(str2, str1, 4);
// 	printf("-----memcpy()-----\n");
//     printf("str2 after memcpy: %s\n\n", str2);
// 	ft_memcpy(str3, str1, sizeof(str1));
// 	printf("-----ft_memcpy()-----\n");
// 	printf("str3 after ft_memcpy: %s\n", str3);
//     return 0;
// }