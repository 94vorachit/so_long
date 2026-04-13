/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:12:49 by vorhansa          #+#    #+#             */
/*   Updated: 2025/09/01 16:02:26 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// NAME
//     strlen -- find length of string
// SYNOPSIS
//     size_t(const char *s);
// DESCRIPTION
//     The strlen() function computes the length of the string s.
// RETURN VALUES
//     The strlen() function returns the number of characters that 
// 	   precede the terminating NUL character.
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (0);
	while (s && s[len])
		len++;
	return (len);
}

// int	main(void)
// {
// 	char	s[] = "12345";
// 	printf("%zu\n", strlen(s));
// 	printf("%zu", ft_strlen(s));
// }