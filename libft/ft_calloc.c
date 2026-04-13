/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:15:00 by vorhansa          #+#    #+#             */
/*   Updated: 2025/09/15 15:09:14 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if ((((size_t)-1) / nmemb <= size) || (((size_t)-1) / size <= nmemb))
		return (NULL);
	tmp = malloc(nmemb * size);
	if (!tmp)
		return (NULL);
	while (i < nmemb * size)
		tmp[i++] = 0;
	return (tmp);
}

// int main() 
// {
// 	int *students;
// 	int numStudents = 12;
// 	students = ft_calloc(numStudents, sizeof(*students));
// 	printf("%lu\n", numStudents * sizeof(*students)); // 48 bytes
// 	free(students);
// 	return (0);
//   }
