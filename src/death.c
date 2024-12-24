/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:56:44 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/12/24 11:30:44 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	death_animation(t_data *data)
{
	static int	frame;
	int			i;

	data->status = LOSS;
	data->player.status = DIE;
	i = SPEED_W;
	while (i < 3 * SPEED_D)
	{
		if (i == frame && i % SPEED_D == 0)
		{
			data->player.idle[0]->instances->enabled = false;
			data->player.idle[1]->instances->enabled = false;
			mlx_image_to_window(data->mlx, data->player.death[i / SPEED_D],
				(data->player.position.x + 1) * PIXEL,
				(data->player.position.y + 1) * PIXEL);
			data->player.death[i / SPEED_D]->instances->enabled = true;
			if (i / SPEED_D != 1)
				data->player.death[(i / SPEED_D) - 1]
					->instances->enabled = false;
		}
		i++;
	}
	frame++;
}

void	is_death(t_data *data)
{
	int	i;

	i = 1;
	while (i < data->map.mon_num)
	{
		if ((data->player.idle[0]->instances->x / PIXEL)
			== (data->mon[i]->instances[i].x / PIXEL)
			&& (data->player.idle[0]->instances->y / PIXEL)
			== (data->mon[i]->instances[i].y / PIXEL))
			death_animation(data);
		i++;
	}
}
