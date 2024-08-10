/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:11:40 by ccodere           #+#    #+#             */
/*   Updated: 2024/08/10 13:04:43 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <signal.h>

int	ft_close_game(void)
{
	exit(EXIT_SUCCESS);
}

int	ft_perror(char *why, t_game *game)
{
	if (game->map.created == TRUE)
		ft_free_map(game);
	free(game);
	ft_printf(RED"Error\n"GREY"%s\n"RESET, why);
	exit(EXIT_FAILURE);
}

void	ft_check_arguments(t_game *game, int argc, char *argv[])
{
	int	len;

	game->map.created = FALSE;
	if (argc != 2)
		ft_perror("Format : ./so_long maps/valid/map1.ber", game);
	len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][len - 4], ".ber", 4))
		ft_perror("The map must be a '.ber' file.", game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		ft_close_game();
	ft_check_arguments(game, argc, argv);
	ft_read_map(game, argv[1]);
	ft_init_vars(game);
	ft_check_map(game);
	ft_load_mlx(game);
	ft_load_img(game);
	ft_render_map(game);
	mlx_hook(game->win_ptr, 2, 1L << 1, ft_define_controls, game);
	mlx_hook(game->win_ptr, 17, 1L << 0, ft_close_game, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
