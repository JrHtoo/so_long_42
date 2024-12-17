/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:07:09 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/12/17 17:47:32 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"

# define IMG_W 32
# define IMG_H 32

# define PIXEL 80
# define COL_SIZE 50
# define STEP_SIZE 10
# define SPACE 160
# define SPEED_W 5
# define SPEED_C 10
# define SPEED_E 20
# define FPS 24
# define MAX_COL 50

# define PLAYER	'P'
# define COIN 'C'
# define EXIT 'E'
# define WALL '1'
# define ROUTE '0'
# define MONSTER 'M'

# define GAME_TITLE "SO LONG"

# define IMG_BACKGROUND "./textures/texture.png"

typedef enum status
{
	IDILE,
	MOVING,
	WIN,
	DIE,
}					t_status;

typedef enum move
{
	INVALID,
	UP,
	DOWN,
	LEFT,
	RIGHT,
}					t_move;

typedef enum colstatus
{
	COLLECTED,
	TOCOLLECT,
}					t_colstatus;

typedef enum exitstatus
{
	CAN,
	CANNOT,
}					t_exitstatus;

typedef struct s_pos
{
	int		x;
	int		y;
}					t_pos;

typedef struct s_map
{
	char	**map;
	int		to_collect;
	t_pos	size;
}					t_map;

typedef struct s_anime
{
	t_status	status;
	t_move		face_toward;
	t_pos		position;
	mlx_image_t	*walking[29];
	mlx_image_t	*idle[2];
	mlx_image_t	*death[12];
}					t_anime;

typedef struct s_collect
{
	t_pos		pos;
	t_colstatus	status;
	mlx_image_t	*img[5];
}					t_collect;

typedef struct s_exit
{
	t_pos			pos;
	t_exitstatus	status;
	mlx_image_t		*img[5];
}					t_exit;

typedef struct s_data
{
	mlx_t		*mlx;
	t_map		map;
	t_anime		player;
	t_collect	collect[MAX_COL];
	t_exit		exit;	
	int			collected;
	int			moves;
	mlx_image_t	*digit[10];
}					t_data;

void		fill_coin(t_data *data, t_pos pos);
void		ft_print_error(t_data *data, char *error_msg);
void		read_map(t_data *data, char *map_path);
void		rendering(t_data *data);
void		ft_freemap(char **map, int size);
char		**ft_copy_map(t_data data);
void		flood_fill(char **map, t_pos size, int row, int col);
int			ft_mapchr(char **map, t_pos size, char c);
t_pos		ft_findpos(t_data *data, char c);
mlx_image_t	*ft_texture_to_image(t_data *data, char *path,
				int width, int height);
void		put_pic(t_data *data);
void		detect_keys(mlx_key_data_t keydata, void *param);
void		ft_exit(t_data *data, char *error_msg);
void		animate(void *param);
void		player_walking(t_data *data, int x, int y);
t_pos		get_distance(t_data data);
void		animate_collection(t_data *data);
void		collected_function(t_data *data);
void		fill_exit(t_data *data, t_pos pos);
void		open_exit(t_data *data);
void		can_exit(t_data *data);
int32_t		i2win(mlx_t *mlx, mlx_image_t *img, int32_t x, int32_t y);
mlx_image_t	*ft_texture_to_image(t_data *data, char *path, int width, int height);

#endif
