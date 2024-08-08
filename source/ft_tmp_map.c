/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tmp_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 01:47:20 by ccodere           #+#    #+#             */
/*   Updated: 2024/08/08 13:42:42 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_fill(char **map, t_pos size, t_pos cur, char visited)
{
	if (cur.y >= 0 && cur.y < size.y && cur.x >= 0 && cur.x < size.x)
	{
		if (map[cur.y][cur.x] != 'X' && map[cur.y][cur.x] != WALL)
		{
			map[cur.y][cur.x] = 'X';
			ft_fill(map, size, (t_pos){cur.x - 1, cur.y}, visited);
			ft_fill(map, size, (t_pos){cur.x + 1, cur.y}, visited);
			ft_fill(map, size, (t_pos){cur.x, cur.y - 1}, visited);
			ft_fill(map, size, (t_pos){cur.x, cur.y + 1}, visited);
		}
	}
}

void	ft_floodfill(char **map, t_pos size, t_pos begin)
{
	if (begin.y >= 0 && begin.y < size.y && begin.x >= 0 && begin.x < size.x)
	{
		if (map[begin.y][begin.x] != 'X' && map[begin.y][begin.x] != WALL)
		{
			ft_fill(map, size, begin, map[begin.y][begin.x]);
		}
	}
}

char	**ft_make_tmp_map(t_game *game, char **zone)
{
	char	**tmp_map;
	int		x;
	int		y;

	tmp_map = malloc(sizeof(char *) * (game->map.height + 1));
	if (!tmp_map)
		return (NULL);
	y = 0;
	while (y < game->map.height)
	{
		tmp_map[y] = malloc(sizeof(char) * (game->map.width + 1));
		if (!tmp_map[y])
			return (NULL);
		x = 0;
		while (x < game->map.width)
		{
			tmp_map[y][x] = zone[y][x];
			x++;
		}
		tmp_map[y][x] = '\0';
		y++;
	}
	tmp_map[y] = NULL;
	return (tmp_map);
}
