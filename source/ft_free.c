/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 23:09:19 by ccodere           #+#    #+#             */
/*   Updated: 2024/08/08 14:37:08 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_img(t_game *game)
{
	if (game->wall.xpm_ptr)
	{
		mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr);
		game->wall.xpm_ptr = NULL;
	}
	if (game->floor.xpm_ptr)
	{
		mlx_destroy_image(game->mlx_ptr, game->floor.xpm_ptr);
		game->floor.xpm_ptr = NULL;
	}
	if (game->open_exit.xpm_ptr)
	{
		mlx_destroy_image(game->mlx_ptr, game->open_exit.xpm_ptr);
		game->open_exit.xpm_ptr = NULL;
	}
	if (game->coffee.xpm_ptr)
	{
		mlx_destroy_image(game->mlx_ptr, game->coffee.xpm_ptr);
		game->coffee.xpm_ptr = NULL;
	}
	if (game->closed_exit.xpm_ptr)
	{
		mlx_destroy_image(game->mlx_ptr, game->closed_exit.xpm_ptr);
		game->closed_exit.xpm_ptr = NULL;
	}
}

void	ft_free_img_player(t_game *game)
{
	if (game->player_right.xpm_ptr)
	{
		mlx_destroy_image(game->mlx_ptr, game->player_right.xpm_ptr);
		game->player_right.xpm_ptr = NULL;
	}
	if (game->player_left.xpm_ptr)
	{
		mlx_destroy_image(game->mlx_ptr, game->player_left.xpm_ptr);
		game->player_left.xpm_ptr = NULL;
	}
	if (game->player_front.xpm_ptr)
	{
		mlx_destroy_image(game->mlx_ptr, game->player_front.xpm_ptr);
		game->player_front.xpm_ptr = NULL;
	}
	if (game->player_back.xpm_ptr)
	{
		mlx_destroy_image(game->mlx_ptr, game->player_back.xpm_ptr);
		game->player_back.xpm_ptr = NULL;
	}
}

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

void	ft_free_tmp_map(char **tmp_map)
{
	int	i;

	i = -1;
	if (tmp_map)
	{
		while (tmp_map && tmp_map[++i])
			free(tmp_map[i]);
		tmp_map[i] = NULL;
	}
	free(tmp_map);
	tmp_map = NULL;
}

void	ft_free_game(t_game *game)
{
	ft_free_img(game);
	ft_free_img_player(game);
	if (game->map.created == TRUE)
		ft_free_map(game);
	if (game->mlx_ptr && game->win_ptr)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		free(game->mlx_ptr);
		game->mlx_ptr = NULL;
		game->win_ptr = NULL;
	}
	if (game)
	{
		free(game);
		game = NULL;
	}
}
