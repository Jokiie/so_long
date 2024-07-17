/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:58:04 by ccodere           #+#    #+#             */
/*   Updated: 2023/12/09 09:58:09 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Example
// char str[] = "123";
// int res = ft_atoi(str);
static int	ft_isspace(int c)
{
	return (c == '\t' || c == '\v' || c == '\n'
		|| c == '\f' || c == '\r' || c == ' ');
}

int	ft_atoi(const char *str)
{
	unsigned int	num;
	int				sign;
	size_t			i;

	num = 0;
	sign = 1;
	i = 0;
	if (!str)
		return ('\0');
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)sign * num);
}
