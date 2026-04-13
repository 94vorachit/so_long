/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:26:05 by vorhansa          #+#    #+#             */
/*   Updated: 2025/09/10 15:42:04 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char) s1[i] != (unsigned char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}

// int main()
// {
//case 1 
// char* str1 = "GeeksforGeeks";
// char* str2 = "Geeks For Geeks";
// int value = ft_strncmp(str1, str2, 5);
// if (!value) 
//     printf("%s", "The first 5 characters are same.\n");
// else 
//     printf("%s", "The first 5 characters are not equal.\n");
// return (0);
//case2 Greater than zero ( >0 )
// 	char str1[10] = "aksh";
//     char str2[10] = "akash";
//     int result = strncmp(str1, str2, 4);
//     if (result == 0)
//         printf("str1 is equal to str2 up to num characters\n");
//     else if (result > 0)
//         printf("str1 is greater than str2\n");
//     else
//         printf("str2 is greater than str1\n");
//     printf("Value returned by strncmp() is: %d\n", result);
//     return (0);
// }