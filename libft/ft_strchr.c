/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:40:33 by vorhansa          #+#    #+#             */
/*   Updated: 2025/09/08 17:17:17 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// NAME
//     strchr -- locate character in string
// SYNOPSIS
//     char *strchr(const char *s, int c);
// DESCRIPTION
// The strchr() function locates the first occurence of c (converted to a char)
// in the string pointed to by s. The terminating null character is considered
// to be part of the string; therefor if c is '\0', the function locate the
// terminating '\0'.
// RETURN VALUES
// The function strchr() return a pointer to the located character, or NULL if
// the character does not appear in the string.

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *) s + i);
		i++;
	}
	if (c == '\0')
		return ((char *) s + i);
	return (NULL);
}

// int main()
// {
//     // define a string
//     const char* str = "GeeksforGeeks";
//     // define a char ch to be searched in str
//     char ch = 's';

//     // Use strchr to find the first occurrence of the
//     // character 's'
//     const char* result = ft_strchr(str, ch);
// 	printf("Result of strchr: %s\n", result);
//     if (result != NULL) 
// 	{
//         // Calculate the position by subtracting the base
//         // pointer from the result pointer
//  printf("Character '%c' found at position: %ld\n", ch, result - str);
//   }
//     else 
//         printf("Character '%c' not found.\n", ch);
//     return 0;
// }