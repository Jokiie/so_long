/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:32:15 by ccodere           #+#    #+#             */
/*   Updated: 2024/07/10 11:53:35 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_depth_first_search(t_game *game)
{
	char	**tmp_map;
	t_pos	size;
	t_pos	start;

	start.x = game->map.player_pos.x;
	start.y = game->map.player_pos.y;
	size.x = game->map.width;
	size.y = game->map.height;
	tmp_map = ft_make_tmp_map(game, game->map.tab);
	if (!tmp_map)
		return (FALSE);
	ft_floodfill(tmp_map, size, start);
	if (ft_is_path_valid(game, tmp_map) == FALSE)
	{
		ft_free_tmp_map(game, tmp_map);
		return (FALSE);
	}
	ft_free_tmp_map(game, tmp_map);
	return (TRUE);
}

int	ft_is_path_valid(t_game *game, char **tmp_map)
{
	int	y;
	int	x;

	game->map.exit_ok = FALSE;
	game->map.coffees = 0;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (tmp_map[y][x] == 'X')
			{
				if (game->map.tab[y][x] == MAP_EXIT)
					game->map.exit_ok = TRUE;
				if (game->map.tab[y][x] == COFFEE)
					game->map.coffees++;
			}
			x++;
		}
		y++;
	}
	if (game->map.exit_ok == FALSE || game->map.coffees != game->map.nb_coffees)
		return (FALSE);
	return (TRUE);
}
