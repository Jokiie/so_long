/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 23:09:19 by ccodere           #+#    #+#             */
/*   Updated: 2024/07/17 14:54:04 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_mlx(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->floor.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->coffee.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->open_exit.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->closed_exit.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_right.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_left.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_front.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_back.xpm_ptr);
	free(game->win_ptr);
	free(game->mlx_ptr);
}

void	ft_free_tmp_map(t_game *game, char **tmp_map)
{
	int	i;

	i = 0;
	while (i < game->map.height)
		free(tmp_map[i++]);
	free(tmp_map);
}

void	ft_free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.tab)
	{
		while (game->map.tab[i])
			free(game->map.tab[i++]);
	}
	free(game->map.tab);
}

void	ft_free_game(t_game *game)
{
	ft_free_mlx(game);
	ft_printf("\nSuccessfuly freed mlx\n");
	ft_free_map(game);
	ft_printf("\nSuccessfuly freed map\n");
	free(game);
	ft_printf("\nSuccessfuly freed all memory\n");
}

int	ft_close_game(t_game *game)
{
	ft_free_game(game);
	exit(0);
}
