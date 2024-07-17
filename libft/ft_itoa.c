/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:01:06 by ccodere           #+#    #+#             */
/*   Updated: 2024/06/25 01:07:36 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Example
// int num = -424242;
// printf("%s\n", ft_itoa(num));
// !n -> n == 0 , len is 1 if true, or 0 if false
// sign = (n < 0) -> if true, sign will be 1 (used for the size of n)
static int	ft_numlen(int n)
{
	int	len;

	len = !n;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		num_len;
	int		sign;

	sign = (n < 0);
	num_len = sign + ft_numlen(n);
	result = (char *)malloc(sizeof(char) * (num_len + 1));
	if (!result)
		return (NULL);
	result[num_len] = 0;
	if (sign)
	{
		*result = '-';
		result[--num_len] = -(n % 10) + '0';
		n = -(n / 10);
	}
	while (num_len-- > sign)
	{
		result[num_len] = n % 10 + '0';
		n /= 10;
	}
	return (result);
}
