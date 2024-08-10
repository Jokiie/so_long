/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 23:05:07 by ccodere           #+#    #+#             */
/*   Updated: 2024/08/10 12:53:17 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map(t_game *game)
{
	int	x;
	int	y;

	if (game->map.width == 0 || game->map.height == 0)
		ft_perror("Empty map", game);
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (y >= 0 && y < game->map.height && x >= 0 && x < game->map.width)
			{
				ft_verify_game_elements(game);
				ft_check_is_valid_map(game, y, x);
			}
			else
				ft_perror("Invalid map", game);
			x++;
		}
		y++;
	}
}

void	ft_verify_game_elements(t_game *game)
{
	if (game->map.nb_players > 1)
		ft_perror("There is more than one player", game);
	else if (game->map.nb_players < 1)
		ft_perror("There is no player", game);
	else if (game->map.nb_exit > 1)
		ft_perror("There is more than one exit", game);
	else if (game->map.nb_exit < 1)
		ft_perror("There is no exit", game);
	else if (game->map.nb_coffees < 1)
		ft_perror("There is no coffee", game);
}

void	ft_check_is_valid_map(t_game *game, int y, int x)
{
	if (y == 0 || y == game->map.height || x == 0 || x == game->map.width - 1)
	{
		if (game->map.tab[y][x] != WALL)
			ft_perror("Map must be surrounded by walls", game);
	}
	else if (game->map.width > MAX_WIDTH || game->map.height > MAX_HEIGHT)
		ft_perror("Map is too large", game);
	else if (game->map.height == game->map.width)
		ft_perror("Map must be rectangular", game);
	else if (!ft_strchr("CEP01", game->map.tab[y][x]))
		ft_perror("Map must contain only 'CEP01' characters", game);
	else if (ft_depth_first_search(game) == FALSE)
		ft_perror("Invalid Path detected", game);
}
