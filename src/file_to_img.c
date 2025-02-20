/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:21:49 by juhtoo-h          #+#    #+#             */
/*   Updated: 2025/02/11 14:40:40 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	fill_background(t_data *data)
{
	int				x;
	int				y;

	data->asset[0] = ft_texture_to_image(data, IMG_BACKGROUND, PIXEL, PIXEL);
	y = 1;
	while (y <= data->map.size.y)
	{
		x = 1;
		while (x < data->map.size.x)
		{
			mlx_image_to_window(data->mlx, data->asset[0],
				PIXEL * x, PIXEL * y);
			x++;
		}
		y++;
	}
}

static void	fill_wall(t_data *data)
{
	t_pos		p;

	data->asset[1] = ft_texture_to_image(data,
			"textures/wall.png", PIXEL, PIXEL);
	p.y = 0;
	while (p.y < data->map.size.y)
	{
		p.x = 0;
		while (p.x < data->map.size.x)
		{
			if (data->map.map[p.y][p.x] == WALL)
				mlx_image_to_window(data->mlx, data->asset[1],
					PIXEL * (p.x + 1), (PIXEL * (p.y + 1)) - 5);
			p.x++;
		}
		p.y++;
	}
}

static void	fill_everything(t_data *data)
{
	t_pos		pos;

	pos.y = 1;
	while (pos.y < data->map.size.y)
	{
		pos.x = 1;
		while (pos.x < data->map.size.x - 2)
		{
			if (data->map.map[pos.y][pos.x] == MONSTER)
				fill_monster(data, pos);
			else if (data->map.map[pos.y][pos.x] == PLAYER)
				mlx_image_to_window(data->mlx, data->player.idle[0],
					PIXEL * (pos.x + 1), PIXEL * (pos.y + 1));
			else if (data->map.map[pos.y][pos.x] == COIN)
				fill_coin(data, pos);
			else if (data->map.map[pos.y][pos.x] == EXIT)
				fill_exit(data, pos);
			pos.x++;
		}
		pos.y++;
	}
}

static void	render_sprite(t_data data)
{
	int	i;

	i = 0;
	while (i < 28)
	{
		mlx_image_to_window(data.mlx, data.player.walking[i],
			PIXEL * (data.player.position.x + 1),
			PIXEL * (data.player.position.y + 1));
		data.player.walking[i]->instances->enabled = false;
		i++;
	}
	mlx_image_to_window(data.mlx, data.player.idle[1],
		PIXEL * (data.player.position.x + 1),
		PIXEL * (data.player.position.y + 1));
	data.player.idle[1]->instances->enabled = false;
}

void	rendering(t_data *data)
{
	fill_background(data);
	fill_wall(data);
	put_pic(data);
	fill_everything(data);
	render_sprite(*data);
	display_moves(data);
}
