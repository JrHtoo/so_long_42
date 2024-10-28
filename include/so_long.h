/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:07:09 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/10/23 15:29:37 by juhtoo-h         ###   ########.fr       */
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
# define STEP_SIZE 10
# define SPACE 160
# define SPEED 6
# define FPS 24

# define PLAYER	'P'
# define COIN 'C'
# define EXIT 'E'
# define WALL '1'
# define ROUTE '0'
# define MONSTER 'M'

# define GAME_TITLE "SO LONG"

# define IMG_BACKGROUND "./textures/texture.png"

# define S_IMG_IDILE01 "./textures/character/s_idile1.png"
# define S_IMG_IDILE02 "./textures/character/s_idile2.png"
# define S_IMG_IDILE03 "./textures/character/s_idile3.png"
# define S_IMG_IDILE04 "./textures/character/s_idile4.png"
# define S_IMG_IDILE05 "./textures/character/s_idile5.png"
# define S_IMG_IDILE06 "./textures/character/s_idile6.png"
# define S_IMG_IDILE07 "./textures/character/s_idile7.png"
# define S_IMG_IDILE08 "./textures/character/s_idile8.png"

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
	mlx_image_t	*walking[8];
	mlx_image_t	*idle[6];
	mlx_image_t	*spin[12];
}					t_anime;

typedef struct s_data
{
	mlx_t	*mlx;
	t_map	map;
	t_anime	player;
	int		collected;
	int		moves;
}					t_data;

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

#endif
