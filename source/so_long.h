/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodere <ccodere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:45:19 by ccodere           #+#    #+#             */
/*   Updated: 2024/08/08 14:44:42 by ccodere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

# define IMG_WIDTH 64
# define IMG_HEIGHT 64

# define WALL '1'
# define FLOOR '0'
# define COFFEE 'C'
# define PLAYER 'P'
# define MAP_EXIT 'E'

# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define GREY "\033[0;90m"
# define CYAN "\033[1;96m"
# define RESET "\033[0m"

# define WALL_XPM "img/wall.xpm"
# define FLOOR_XPM "img/floor.xpm"
# define COFFEE_XPM "img/coffee.xpm"
# define CLOSED_EXIT_XPM "img/closed_exit.xpm"
# define OPEN_EXIT_XPM "img/open_exit.xpm"
# define PLAYER_RIGHT_XPM "img/player_idle_right.xpm"
# define PLAYER_LEFT_XPM "img/player_idle_left.xpm"
# define PLAYER_FRONT_XPM "img/player_idle_front.xpm"
# define PLAYER_BACK_XPM "img/player_idle_back.xpm"

# define FRONT 1
# define LEFT 2
# define RIGHT 3
# define BACK 4

# define MAX_WIDTH 40
# define MAX_HEIGHT 21

typedef enum e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef enum e_key
{
	KEY_Q = 12,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_ESC = 53,
	KEY_UP = 126,
	KEY_LEFT = 123,
	KEY_DOWN = 125,
	KEY_RIGHT = 124
}				t_key;

typedef struct s_img
{
	void		*xpm_ptr;
	int			width;
	int			height;
}				t_img;

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct s_map
{
	int			width;
	int			height;
	int			nb_coffees;
	int			nb_players;
	int			nb_exit;
	char		**tab;
	t_bool		created;
	t_pos		player_pos;
	t_bool		exit_ok;
	int			coffees;
}				t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_img		wall;
	t_img		floor;
	t_img		coffee;
	t_img		closed_exit;
	t_img		open_exit;
	t_img		player_right;
	t_img		player_left;
	t_img		player_front;
	t_img		player_back;
	int			player_dir;
	int			moves_count;
}				t_game;

int				ft_depth_first_search(t_game *game);
int				ft_is_path_valid(t_game *game, char **tmp_map);

void			ft_check_map(t_game *game);
void			ft_verify_game_elements(t_game *game);
void			ft_check_is_valid_map(t_game *game, int y, int x);

int				ft_define_controls(int key, t_game *game);
void			ft_move_player(t_game *game, int new_y, int new_x,
					int player_dir);
void			ft_render_new_pos(t_game *game, int new_x, int new_y,
					int player_dir);
void			ft_print_moves(t_game *game);
void			ft_print_win(t_game *game);

void			ft_free_img(t_game *game);
void			ft_mlx_destroy_display(t_game *game);
void			ft_free_map(t_game *game);
void			ft_free_tmp_map(char **tmp_map);
void			ft_free_game(t_game *game);

void			ft_init_vars(t_game *game);
void			ft_count_elements(t_game *game, int y, int x);
void			ft_count_tiles(t_game *game);

char			*ft_strjoin_free(char *s1, char const *s2);
void			ft_read_map(t_game *game, char *argv);
void			ft_render_map(t_game *game);
void			ft_draw_tiles(t_game *game, int y, int x);
void			ft_render_player(t_game *game, int y, int x);

void			ft_put_img(t_game *game, t_img img, int x, int y);
t_img			ft_define_img(void *mlx, char *path, t_game *game);
void			ft_load_img(t_game *game);
void			ft_load_mlx(t_game *game);

char			**ft_make_tmp_map(t_game *game, char **zone);
void			ft_floodfill(char **map, t_pos size, t_pos begin);
void			ft_fill(char **map, t_pos size, t_pos cur, char visited);

int				ft_error_notification(char *why, t_game *game);
void			ft_check_arguments(t_game *game, int argc, char *argv[]);
int				ft_close_game(void);
#endif