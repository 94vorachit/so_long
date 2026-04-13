/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:49:27 by vorhansa          #+#    #+#             */
/*   Updated: 2025/09/08 15:49:26 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	dest = (char *) malloc(sizeof (*s) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// int main() 
// {
//     const char *original = "Hello, world!";
//     char *duplicate = ft_strdup(original);
//     if (duplicate == NULL) {
//         fprintf(stderr, "strdup failed to allocate memory.\n");
//         return 1;
//     }
//     printf("Original: %s\n", original);
//     printf("Duplicate: %s\n", duplicate);
//     if (strcmp(original, duplicate) == 0) {
//         printf("Test passed: Strings are identical.\n");
//     } else {
//         printf("Test failed: Strings are different.\n");
//     }
//     free(duplicate); // Important to free the allocated memory
//     return 0;
// }