/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:55:11 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/12/17 15:27:32 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	idle_utils(t_data *data, int frame)
{
	int			i;
	static int	turn;

	i = 0;
	while (i <= 5 * SPEED_W)
	{
		if (i == SPEED_W && i == frame)
		{
			if (turn == 0)
			{
				data->player.idle[0]->instances->enabled = true;
				data->player.idle[1]->instances->enabled = false;
				turn = 1;
			}
			else if (turn == 1)
			{
				data->player.idle[1]->instances->enabled = true;
				data->player.idle[0]->instances->enabled = false;
				turn = 0;
			}
		}
		i++;
	}
}

static void	player_idling(t_data *data)
{
	static int	frame;

	idle_utils(data, frame);
	data->player.idle[1]->instances->x
		= data->player.idle[0]->instances->x;
	data->player.idle[1]->instances->y
		= data->player.idle[0]->instances->y;
	frame++;
	if (frame >= 5 * SPEED_W)
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
	animate_collection(data);
	animate_player(data);
	open_exit(data);
	can_exit(data);
}
