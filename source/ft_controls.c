/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 00:48:23 by ccodere           #+#    #+#             */
/*   Updated: 2024/08/10 13:05:21 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_define_controls(int key, t_game *game)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->map.player_pos.x;
	pos_y = game->map.player_pos.y;
	if (key == KEY_UP || key == KEY_W)
		ft_move_player(game, pos_y - 1, pos_x, BACK);
	else if (key == KEY_DOWN || key == KEY_S)
		ft_move_player(game, pos_y + 1, pos_x, FRONT);
	else if (key == KEY_LEFT || key == KEY_A)
		ft_move_player(game, pos_y, pos_x - 1, LEFT);
	else if (key == KEY_RIGHT || key == KEY_D)
		ft_move_player(game, pos_y, pos_x + 1, RIGHT);
	else if (key == KEY_ESC || key == KEY_Q)
		ft_close_game();
	else
		return (0);
	return (0);
}

void	ft_move_player(t_game *game, int new_y, int new_x, int player_dir)
{
	if (new_x < 0 || new_x >= game->map.width || new_y < 0
		|| new_y >= game->map.height)
		return ;
	if (game->map.tab[new_y][new_x] == WALL
		|| (game->map.tab[new_y][new_x] == MAP_EXIT
			&& game->map.nb_coffees > 0))
		return ;
	else if (game->map.tab[new_y][new_x] == COFFEE)
		game->map.nb_coffees--;
	if (game->map.tab[new_y][new_x] == MAP_EXIT && game->map.nb_coffees == 0)
	{
		ft_print_win(game);
		ft_close_game();
	}
	ft_render_new_pos(game, new_x, new_y, player_dir);
	ft_render_map(game);
	ft_print_moves(game);
}

void	ft_render_new_pos(t_game *game, int new_x, int new_y, int player_dir)
{
	int	last_y;
	int	last_x;

	last_y = game->map.player_pos.y;
	last_x = game->map.player_pos.x;
	ft_put_img(game, game->floor, last_x, last_y);
	game->map.player_pos.x = new_x;
	game->map.player_pos.y = new_y;
	game->player_dir = player_dir;
	if (game->map.tab[last_y][last_x] == COFFEE)
		game->map.tab[last_y][last_x] = FLOOR;
	game->map.tab[new_y][new_x] = PLAYER;
	game->moves_count++;
}

void	ft_print_moves(t_game *game)
{
	char	*moves;
	char	*txt;

	moves = ft_itoa(game->moves_count);
	txt = ft_strjoin("MOVES : ", moves);
	mlx_string_put(game->mlx_ptr, game->win_ptr, (game->map.width * IMG_WIDTH)
		- 100, 30, 0x000000, txt);
	free(moves);
	free(txt);
}

void	ft_print_win(t_game *game)
{
	ft_printf(CYAN"\n::: === :::====  :::  ===   :::  ===  === ::: :::= ===\n");
	ft_printf("::: === :::  === :::  ===   :::  ===  === ::: :::=====\n");
	ft_printf(" =====  ===  === ===  ===   ===  ===  === === ========\n");
	ft_printf("  ===   ===  === ===  ===    ===========  === === ====\n");
	ft_printf("  ===    ======   ======      ==== ====   === ===  ===\n"RESET);
	ft_printf(GREEN"\n\t\tYou won with %d moves!\n"RESET, (game->moves_count + 1));
}
