/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_walking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:08:18 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/12/17 15:06:39 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_pos	get_distance(t_data data)
{
	t_pos	distance;

	distance.x = 0;
	distance.y = 0;
	if (data.player.face_toward == UP)
		distance.y = -STEP_SIZE;
	else if (data.player.face_toward == DOWN)
		distance.y = STEP_SIZE;
	else if (data.player.face_toward == LEFT)
		distance.x = -STEP_SIZE;
	else if (data.player.face_toward == RIGHT)
		distance.x = STEP_SIZE;
	return (distance);
}

static void	get_position_img(t_data data,
	mlx_image_t *img_des, mlx_image_t *img)
{
	t_pos	distance;

	distance = get_distance(data);
	img_des->instances->x = img->instances->x + distance.x;
	img_des->instances->y = img->instances->y + distance.y;
	img->instances->enabled = false;
	img_des->instances->enabled = true;
}

static int	facing_value(t_data *data)
{
	if (data->player.face_toward == UP)
		return (20);
	else if (data->player.face_toward == DOWN)
		return (1);
	else if (data->player.face_toward == RIGHT)
		return (7);
	else if (data->player.face_toward == LEFT)
		return (14);
	else
		return (1);
}

static int	walking_utils(t_data *data, int x, int y, int frame)
{
	int		i;
	int		index;
	t_pos	distance;

	i = 1;
	index = facing_value(data);
	while (i <= 7 * SPEED_W)
	{
		if (i % SPEED_W == 0 && i == frame)
		{
			index = index + (i / SPEED_W);
			data->player.idle[0]->instances->enabled = false;
			data->player.idle[1]->instances->enabled = false;
			distance = get_distance(*data);
			data->player.walking[index]->instances->x
				= x + distance.x * (i / SPEED_W);
			data->player.walking[index]->instances->y
				= y + distance.y * (i / SPEED_W);
			if (i / SPEED_W != 1)
				data->player.walking[index - 1]->instances->enabled = false;
			data->player.walking[index]->instances->enabled = true;
		}
		i++;
	}
	return (index);
}

void	player_walking(t_data *data, int x, int y)
{
	static int	frame;
	int			index;

	index = walking_utils(data, x, y, frame);
	frame++;
	if (frame > 7 * SPEED_W)
	{
		data->player.status = IDILE;
		get_position_img(*data, data->player.idle[0],
			data->player.walking[index]);
		frame = 1;
		collected_function(data);
	}
}
