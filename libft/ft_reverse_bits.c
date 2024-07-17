/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_bits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:37:13 by ccodere           #+#    #+#             */
/*   Updated: 2024/06/13 00:02:49 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	ft_reverse_bits(unsigned char octet)
{
	unsigned char	res;
	int				i;

	res = 0;
	i = 0;
	while (i--)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
	}
	return (res);
}
