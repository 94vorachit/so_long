/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:11:05 by vorhansa          #+#    #+#             */
/*   Updated: 2025/09/15 13:32:04 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_dgt_cnt(int n)
{
	size_t	cnt;

	cnt = 0;
	if (n == 0)
		cnt++;
	while (n != 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	dgt;
	long	nb;

	nb = n;
	dgt = ft_dgt_cnt(n);
	if (n < 0)
	{
		nb *= -1;
		dgt++;
	}
	str = (char *)malloc(sizeof(char) * (dgt + 1));
	if (!str)
		return (NULL);
	str[dgt] = '\0';
	while (dgt--)
	{
		str[dgt] = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

// int	main()
// {
// 	int	a = -1234;
// 	char	*nb = ft_itoa(a);
// 	printf("%s\n", nb);
// 	free(nb);
// }
