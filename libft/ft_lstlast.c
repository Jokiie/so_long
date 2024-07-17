/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:09:32 by ccodere           #+#    #+#             */
/*   Updated: 2024/06/10 02:18:40 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Example
// in ft_lstadd_back
t_list	*ft_lstlast(t_list *lst)
{
	int		i;
	t_list	*last;

	if (lst != NULL)
	{
		i = 1;
		last = lst;
		while (last->next != NULL)
		{
			last = last->next;
			i++;
		}
		return (last);
	}
	else
		return (0);
}
