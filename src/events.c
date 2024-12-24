/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:57:48 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/12/19 14:16:34 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_valid_move(t_data data, t_move dir)
{
	int	x;
	int	y;

	x = data.player.position.x;
	y = data.player.position.y;
	if (dir == UP)
		return (data.map.map[y - 1][x] != WALL);
	else if (dir == DOWN)
		return (data.map.map[y + 1][x] != WALL);
	else if (dir == RIGHT)
		return (data.map.map[y][x + 1] != WALL);
	else if (dir == LEFT)
		return (data.map.map[y][x - 1] != WALL);
	return (0);
}

static t_move	direction(t_data data, keys_t key)
{
	t_move	dir;

	dir = INVALID;
	if (key == MLX_KEY_UP || key == MLX_KEY_W)
		dir = UP;
	else if (key == MLX_KEY_DOWN || key == MLX_KEY_S)
		dir = DOWN;
	else if (key == MLX_KEY_RIGHT || key == MLX_KEY_D)
		dir = RIGHT;
	else if (key == MLX_KEY_LEFT || key == MLX_KEY_A)
		dir = LEFT;
	if (dir != INVALID)
	{
		if (!is_valid_move(data, dir))
			return (INVALID);
	}
	return (dir);
}

static void	get_face_toward(t_data *data, t_move dir)
{
	if (dir == UP)
		data->player.face_toward = UP;
	else if (dir == DOWN)
		data->player.face_toward = DOWN;
	else if (dir == RIGHT)
		data->player.face_toward = RIGHT;
	else if (dir == LEFT)
		data->player.face_toward = LEFT;
}

static void	get_new_position(t_data *data, t_move dir)
{
	if (dir == UP)
		data->player.position.y -= 1;
	else if (dir == DOWN)
		data->player.position.y += 1;
	else if (dir == RIGHT)
		data->player.position.x += 1;
	else if (dir == LEFT)
		data->player.position.x -= 1;
	get_face_toward(data, dir);
	data->moves += 1;
	data->player.status = MOVING;
}

void	detect_keys(mlx_key_data_t keydata, void *param)
{
	t_data	*data;
	t_move	dir;

	data = (t_data *)param;
	if (data->status == YET)
	{
		if (keydata.action == MLX_PRESS)
		{
			if (keydata.key == MLX_KEY_ESCAPE)
				ft_exit(data, "Escape from the game!\n");
			dir = direction(*data, keydata.key);
			if (dir != INVALID && data->player.status == IDILE)
			{
				get_new_position(data, dir);
				ft_printf("%d moves\n", data->moves);
			}
		}
	}
}
