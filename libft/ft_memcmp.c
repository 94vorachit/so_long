/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:53:33 by vorhansa          #+#    #+#             */
/*   Updated: 2025/09/03 18:06:44 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;
	size_t			i;

	i = 0;
	if (!n || (s1 != NULL && s2 == s1))
		return (0);
	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	while (temp_s1[i] == temp_s2[i] && i < n - 1)
		i++;
	return (temp_s1[i] - temp_s2[i]);
}

// int main() 
// {
//     char s1[] = "GfG";
//     char s2[] = "GfG";
//     char s3[] = "gfg";
//     int l1 = ft_strlen(s1);
//     int l2 = ft_strlen(s2);
//     int l3 = ft_strlen(s3);
//     int n = l1;
//     if (n > l2)  
// 		n = l2;
//     if (n > l3) 
// 		n = l3;
//     // Compare first n bytes of s1 and s2
//     int res = ft_memcmp(s1, s2, n);
//     if (res == 0)
//         printf("s1 and s2 are equal.\n");
//     else
//         printf("s1 and s2 are not equal.\n");

//     // Compare first strlen(s3) bytes of s1 and s3
//     res = ft_memcmp(s1, s3, ft_strlen(s3));
//     if (res == 0)
//         printf("s1 and s3 are equal.");
//     else
//         printf("s1 and s3 are not equal.");
//     return (0);
// }