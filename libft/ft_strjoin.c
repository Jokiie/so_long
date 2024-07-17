/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:07:50 by ccodere           #+#    #+#             */
/*   Updated: 2024/06/25 00:28:27 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*strs;
	size_t			total_len;
	size_t			s1_len;
	size_t			s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len;
	strs = (char *)ft_calloc(total_len + 1, sizeof(char));
	if (!strs)
		return (NULL);
	ft_strlcpy(strs, s1, s1_len + 1);
	ft_strlcat(strs, s2, total_len + 1);
	return (strs);
}
