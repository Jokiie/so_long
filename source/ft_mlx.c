/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 23:55:59 by ccodere           #+#    #+#             */
/*   Updated: 2024/08/10 12:52:10 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_img(t_game *game, t_img img, int x, int y)
{
	if (img.xpm_ptr)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img.xpm_ptr, x
			* img.width, y * img.height);
}

t_img	ft_define_img(void *mlx, char *path, t_game *game)
{
	t_img	img;

	img.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &img.width, &img.height);
	if (!img.xpm_ptr)
		ft_perror("Pointer to img is NULL.", game);
	return (img);
}

void	ft_load_img(t_game *game)
{
	game->wall = ft_define_img(game->mlx_ptr, WALL_XPM, game);
	game->floor = ft_define_img(game->mlx_ptr, FLOOR_XPM, game);
	game->coffee = ft_define_img(game->mlx_ptr, COFFEE_XPM, game);
	game->open_exit = ft_define_img(game->mlx_ptr, OPEN_EXIT_XPM, game);
	game->closed_exit = ft_define_img(game->mlx_ptr, CLOSED_EXIT_XPM, game);
	game->player_left = ft_define_img(game->mlx_ptr, PLAYER_LEFT_XPM, game);
	game->player_right = ft_define_img(game->mlx_ptr, PLAYER_RIGHT_XPM, game);
	game->player_front = ft_define_img(game->mlx_ptr, PLAYER_FRONT_XPM, game);
	game->player_back = ft_define_img(game->mlx_ptr, PLAYER_BACK_XPM, game);
}

void	ft_load_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		free(game->mlx_ptr);
		ft_perror("Pointer to mlx_init() is NULL.", game);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.width * IMG_WIDTH,
			game->map.height * IMG_HEIGHT, "so_long");
	if (!game->win_ptr)
	{
		free(game->win_ptr);
		ft_perror("Pointer to mlx_new_window() is NULL.", game);
	}
}
