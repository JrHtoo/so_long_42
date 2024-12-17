/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:16:10 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/12/16 17:40:11 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	find_collection(t_data *data, t_pos pos)
{
	int	i;

	i = 0;
	while (i < data->map.to_collect)
	{
		if (data->collect[i].pos.x == pos.x
			&& data->collect[i].pos.y == pos.y)
			return (i);
		i++;
	}
	return (-1);
}

void	collected_function(t_data *data)
{
	t_pos	pos;
	int		i;
	int		index;

	pos.x = data->player.position.x;
	pos.y = data->player.position.y;
	if (data->map.map[pos.y][pos.x] == COIN)
	{
		data->collected++;
		index = find_collection(data, pos);
		if (data->collect[index].status == TOCOLLECT)
		{
			i = 0;
			while (i < 5)
			{
				data->collect[index].img[i]
					->instances->enabled = false;
				data->collect[index].status = COLLECTED;
				i++;
			}
		}
	}
}
