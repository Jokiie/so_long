/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:58:53 by ccodere           #+#    #+#             */
/*   Updated: 2024/03/07 09:29:20 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Example
// char *res = (char *)ft_calloc(6, sizeof(char));
// res = "Celia";
void	*ft_calloc(size_t count, size_t size)
{
	size_t	t_size;
	void	*ptr;

	if (count == 0 || size == 0)
		return (NULL);
	t_size = count * size;
	ptr = (void *)malloc(t_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, t_size);
	return (ptr);
}
