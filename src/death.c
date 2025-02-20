/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:56:44 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/12/24 15:54:29 by juhtoo-h         ###   ########.fr       */
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
			if (i / SPEED_D == 2)
				ft_printf("GAME OVER!!GOOD LUCK NEXT TIME!\n");
		}
		i++;
	}
	frame++;
}

void	is_death(t_data *data)
{
	int		i;
	int		index;
	t_pos	p;
	t_pos	m;

	i = 0;
	p.x = data->player.idle[0]->instances->x;
	p.y = data->player.idle[0]->instances->y;
	while (i < data->map.mon_num)
	{
		index = 1;
		while (index < 5)
		{
			m.x = data->mon[1]->instances[i].x;
			m.y = data->mon[1]->instances[i].y;
			if (p.x < (m.x + DIE_R) && (p.x + DIE_R) > m.x
				&& p.y < (m.y + DIE_R) && (p.y + DIE_R) > m.y)
				death_animation(data);
			index++;
		}
		i++;
	}
}
