/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:49:51 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/12/17 17:47:32 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	fill_coin_utils(t_data *data, mlx_image_t **img)
{
	img[0] = ft_texture_to_image(data,
			"textures/collect/collect1.png", COL_SIZE, COL_SIZE);
	img[1] = ft_texture_to_image(data,
			"textures/collect/collect1.png", COL_SIZE, COL_SIZE);
	img[2] = ft_texture_to_image(data,
			"textures/collect/collect2.png", COL_SIZE, COL_SIZE);
	img[3] = ft_texture_to_image(data,
			"textures/collect/collect3.png", COL_SIZE, COL_SIZE);
	img[4] = ft_texture_to_image(data,
			"textures/collect/collect4.png", COL_SIZE, COL_SIZE);
}

void	fill_coin(t_data *data, t_pos pos)
{
	int			i;
	static int	index;
	mlx_image_t	*img[5];

	fill_coin_utils(data, img);
	data->collect[index].status = TOCOLLECT;
	i = 0;
	while (i < 5)
	{
		data->collect[index].pos.x = pos.x;
		data->collect[index].pos.y = pos.y;
		data->collect[index].img[i] = img[i];
		mlx_image_to_window(data->mlx, data->collect[index].img[i],
			((pos.x + 1) * PIXEL) + 10, ((pos.y + 1) * PIXEL) + 10);
		if (i != 1)
			data->collect[index].img[i]->instances->enabled = false;
		i++;
	}
	index++;
	data->map.to_collect = index;
}

void	animate_collection_utils(t_data *data, int frame)
{
	int			i;
	int			x;

	i = SPEED_C;
	while (i < 5 * SPEED_C)
	{
		if (i == frame && i % SPEED_C == 0)
		{
			x = 0;
			while (x < data->map.to_collect)
			{
				if (data->collect[x].status == TOCOLLECT)
				{
					if ((i / SPEED_C) == 1)
						data->collect[x].img[4]->instances->enabled = false;
					data->collect[x]
						.img[i / SPEED_C]->instances->enabled = true;
					data->collect[x]
						.img[(i / SPEED_C) - 1]->instances->enabled = false;
				}
				x++;
			}
		}
		i++;
	}
}

void	animate_collection(t_data *data)
{
	static int	frame;

	animate_collection_utils(data, frame);
	frame++;
	if (frame > 5 * SPEED_C)
		frame = 1;
}
