/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:30:31 by vorhansa          #+#    #+#             */
/*   Updated: 2025/09/08 12:35:18 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// NAME
//     toupper -- lower case to upper case letter conversion
// SYNOPSIS
//     int toupper(int c);
// DESCRIPTION
//     The toupper() function converts a lower-case letter to the corresponding 
// 	upper-case letter. The argument must be representable as an unsigned char 
// 	or the value of EOF.
// RETURN VALUES
// If the argument is a lower-case letter, the toupper() function returns the 
// 	corresponding upper-casse letter if there is one; otherwise, the argument is
// 	returned unchanged.

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

// int	main()
// {
// 	char l = 'a';
// 	char u = ft_toupper(l);
// 	printf("%c in uppercase is %c", l, u);
// }