/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:38:12 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/12/17 15:24:18 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	fill_exit(t_data *data, t_pos pos)
{
	int	i;

	data->exit.pos.x = pos.x;
	data->exit.pos.y = pos.y;
	data->exit.status = CANNOT;
	i = 0;
	while (i < 5)
	{
		mlx_image_to_window(data->mlx, data->exit.img[i],
			(pos.x + 1) * PIXEL, (pos.y + 1) * PIXEL);
		if (i != 1)
			data->exit.img[i]->instances->enabled = false;
		i++;
	}
}

void	can_exit(t_data *data)
{
	if ((data->player.position.x == data->exit.pos.x
			&& data->player.position.y == data->exit.pos.y)
		&& data->exit.status == CAN)
		ft_exit(data, "Well Done! Game Finished\n");
}

void	open_exit(t_data *data)
{
	int			i;
	static int	frame;

	if (data->collected == data->map.to_collect)
	{
		i = SPEED_E;
		while (i < 5 * SPEED_E)
		{
			if (i == frame && i % SPEED_E == 0)
			{
				if ((i / SPEED_E) == 1)
					data->exit.img[4]->instances->enabled = false;
				data->exit.img[(i / SPEED_E)]->instances->enabled = true;
				data->exit.img[(i / SPEED_E) - 1]->instances->enabled = false;
				printf("exit %d %d\n", i / SPEED_E, (i / SPEED_E) - 1);
			}
			i++;
		}
		data->exit.status = CAN;
	}
	frame++;
	if (frame > 5 * SPEED_E)
		frame = 1;
}
