/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:55:11 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/10/23 15:28:42 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static t_pos	get_distance(t_data data)
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

static void	player_walking(t_data *data, int x, int y)
{
	int			i;
	t_pos		distance;
	static int	frame;

	i = 1;
	while (i <= 7 * SPEED)
	{
		if (i % SPEED == 0 && i == frame)
		{
			data->player.idle[0]->instances->enabled = false;
			data->player.idle[1]->instances->enabled = false;
			distance = get_distance(*data);
			data->player.walking[i / SPEED]->instances->x = x + distance.x * (i / SPEED);
			data->player.walking[i / SPEED]->instances->y = y + distance.y * (i / SPEED);
			data->player.walking[(i / SPEED) - 1]->instances->enabled = false;
			data->player.walking[(i / SPEED)]->instances->enabled = true;
		}
		i++;
	}
	frame++;
	if (frame > 7 * SPEED)
	{
		data->player.status = IDILE;
		get_position_img(*data, data->player.idle[0], data->player.walking[7]);
		frame = 1;
	}
}

static void	player_idling(t_data *data)
{
	int			i;
	static int	frame;

	i = 0;
	data->player.idle[1]->instances->x
		= data->player.idle[0]->instances->x;
	data->player.idle[1]->instances->y
		= data->player.idle[0]->instances->y;
	while (i <= 2 * SPEED)
	{
		if (i == 0)
		{
			data->player.idle[0]->instances->enabled = true;
			data->player.idle[1]->instances->enabled = false;
		}
		else if (i == SPEED)
		{
			data->player.idle[1]->instances->enabled = true;
			data->player.idle[0]->instances->enabled = false;
		}
		i++;
	}
	frame++;
	if (frame > 2 * SPEED)
		frame = 1;
}

static void	animate_player(t_data *data)
{
	if (data->player.status == IDILE)
		player_idling(data);
	else if (data->player.status == MOVING)
	{
		player_walking(data, data->player.idle[0]->instances->x,
			data->player.idle[0]->instances->y);
	}
}

void	animate(void *param)
{
	t_data		*data;

	data = (t_data *)param;
	animate_player(data);
}
