/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:04:19 by vorhansa          #+#    #+#             */
/*   Updated: 2025/09/01 16:43:48 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// NAME
//     bzero -- write zeroes to a bye string
// SYNOPSIS
//     void bzero(void *s, size_t n);
// DESCRIPTION
//     The bzero() function writes n zeroed bytes to the string s.
//     If n is zero, bzero() does nothing.
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

// int main(void) 
// {
//     char buffer1[] = "This is a test string.";
//     printf("-----bzero-----\n");
//     printf("Before bzero: \"%s\"\n", buffer1);
//     printf("Buffer content (hex): ");
//     for (int i = 0; i < 23; i++)
//         printf("%02x ", (unsigned char)buffer1[i]);
//     printf("\n");
//     // Apply bzero to a portion of the buffer
//     bzero(buffer1 + 5, 1); // Zero out 4 bytes starting from index 5
//     printf("After bzero: \"%s\"\n", buffer1); 
//     //Note: puts() or printf with %s might stop at the first null byte
//     // To see the effect of bzero on the entire buffer, print byte by byte
//     printf("Buffer content (hex): ");
//     for (int i = 0; i < 23; i++)
//         printf("%02x ", (unsigned char)buffer1[i]);
//     printf("\n\n");
//     char buffer2[] = "This is a test string.";
//     printf("-----ft_bzero-----\n");
//     printf("Before ft_bzero: \"%s\"\n", buffer2);
//     printf("Buffer content (hex): ");
//     for (int i = 0; i < 23; i++)
//         printf("%02x ", (unsigned char)buffer2[i]);
//     printf("\n");
//     ft_bzero(buffer2 + 5, 1);
//     printf("After ft_bzero: \"%s\"\n", buffer2);
//     printf("Buffer content (hex): ");
//     for (int i = 0; i < 23; i++)
//         printf("%02x ", (unsigned char)buffer2[i]);
//     printf("\n");
//     return 0;
// }