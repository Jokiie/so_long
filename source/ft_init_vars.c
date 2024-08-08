/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:07:56 by ccodere           #+#    #+#             */
/*   Updated: 2024/08/08 13:56:34 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_vars(t_game *game)
{
	game->map.player_pos.x = 0;
	game->map.player_pos.y = 0;
	game->map.nb_coffees = 0;
	game->map.nb_exit = 0;
	game->map.nb_players = 0;
	game->map.width = 0;
	game->map.height = 0;
	game->map.coffees = 0;
	game->map.exit_ok = FALSE;
	game->moves_count = 0;
	game->player_dir = FRONT;
	ft_count_tiles(game);
}

void	ft_count_elements(t_game *game, int y, int x)
{
	if (game->map.tab[y][x] == PLAYER)
		game->map.nb_players++;
	else if (game->map.tab[y][x] == COFFEE)
		game->map.nb_coffees++;
	else if (game->map.tab[y][x] == MAP_EXIT)
		game->map.nb_exit++;
}

void	ft_count_tiles(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.tab[y])
	{
		x = 0;
		while (game->map.tab[y][x])
		{
			if (game->map.tab[y][x] == PLAYER)
			{
				game->map.player_pos.x = x;
				game->map.player_pos.y = y;
			}
			ft_count_elements(game, y, x);
			x++;
			if (x > 0)
				game->map.width = x;
		}
		y++;
		game->map.height = y;
	}
}
