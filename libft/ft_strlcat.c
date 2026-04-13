/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:31:32 by vorhansa          #+#    #+#             */
/*   Updated: 2025/09/03 15:28:58 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = 0;
	if (size <= dst_len)
		return (src_len + size);
	while (src[i] && dst_len + i + 1 < size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// int main() 
// {
//     char dst[20] = "Hello";
//     char src[] = " World!";
//     size_t result_len;

//     result_len = ft_strlcat(dst, src, 20);
// 	printf("Size of dst : %lu\n", strlen(dst));
// 	printf("Size of src : %lu\n", strlen(src));
//     printf("Concatenated string: \"%s\"\n", dst);
//     printf("Length that would have been created: %zu\n", result_len);
//     if (result_len >= sizeof(dst))
//         printf("Truncation occurred.\n");
//     return 0;
// }