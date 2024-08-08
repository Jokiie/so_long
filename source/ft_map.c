/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 23:02:15 by ccodere           #+#    #+#             */
/*   Updated: 2024/08/08 14:29:51 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin_free(char *s1, char const *s2)
{
	char			*strs;
	size_t			len;
	unsigned int	i;
	unsigned int	j;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	strs = (char *)malloc((len + 1) * sizeof(char));
	if (!strs)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[j])
			strs[i++] = s1[j++];
	j = 0;
	while (s2[j])
		strs[i++] = s2[j++];
	strs[i] = '\0';
	free(s1);
	return (strs);
}

void	ft_read_map(t_game *game, char *argv)
{
	char	*map;
	char	*line;
	int		map_fd;

	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		ft_error_notification("Can't open the map.", game);
	map = ft_strdup("");
	while (TRUE)
	{
		line = get_next_line(map_fd);
		if (!line)
			break ;
		map = ft_strjoin_free(map, line);
		free(line);
	}
	close(map_fd);
	game->map.tab = ft_split(map, '\n');
	game->map.created = TRUE;
	free(map);
}

void	ft_render_map(t_game *game)
{
	int	y;
	int	x;

	if (game->map.tab != NULL)
	{
		y = 0;
		while (y < game->map.height)
		{
			x = 0;
			while (x < game->map.width)
			{
				ft_draw_tiles(game, x, y);
				x++;
			}
			y++;
		}
		ft_render_player(game, game->map.player_pos.x, game->map.player_pos.y);
	}
}

void	ft_draw_tiles(t_game *game, int x, int y)
{
	if (game->map.tab[y][x] == FLOOR)
		ft_put_img(game, game->floor, x, y);
	else if (game->map.tab[y][x] == WALL)
		ft_put_img(game, game->wall, x, y);
	else if (game->map.tab[y][x] == COFFEE)
		ft_put_img(game, game->coffee, x, y);
	else if (game->map.tab[y][x] == MAP_EXIT)
	{
		if (game->map.nb_coffees == 0)
			ft_put_img(game, game->open_exit, x, y);
		else
			ft_put_img(game, game->closed_exit, x, y);
	}
}

void	ft_render_player(t_game *game, int x, int y)
{
	if (game->player_dir == RIGHT)
		ft_put_img(game, game->player_right, x, y);
	else if (game->player_dir == LEFT)
		ft_put_img(game, game->player_left, x, y);
	else if (game->player_dir == FRONT)
		ft_put_img(game, game->player_front, x, y);
	else if (game->player_dir == BACK)
		ft_put_img(game, game->player_back, x, y);
}
