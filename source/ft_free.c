/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 23:09:19 by ccodere           #+#    #+#             */
/*   Updated: 2024/08/10 12:22:42 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_game *game)
{
	int	i;

	i = -1;
	if (game->map.tab)
	{
		while (game->map.tab && game->map.tab[++i])
			free(game->map.tab[i]);
		game->map.tab[i] = NULL;
	}
	free(game->map.tab);
	game->map.tab = NULL;
	game->map.created = FALSE;
}
