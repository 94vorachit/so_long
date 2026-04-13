/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:41:09 by vorhansa          #+#    #+#             */
/*   Updated: 2025/09/03 14:01:54 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (dst == NULL || src == NULL)
		return (0);
	i = 0;
	if (size > 0)
	{
		while (src[i] && i + 1 < size)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

// int main() 
// {
//     char src[] = "Hello, world!";
//     char dest[10];
//     printf("Src: \"%s\"\n", src);
//     printf("Dest: \"%s\"\n", dest);
// 	size_t cpy_length = ft_strlcpy(dest, src, sizeof(dest));
//     printf("Length that would have been copied: %zu\n", cpy_length);
// 	printf("Dest after strlcpy: \"%s\"\n", dest);
//     if (cpy_length >= sizeof(dest))
//         printf("Warning: String was truncated.\n");
//     return 0;
// }