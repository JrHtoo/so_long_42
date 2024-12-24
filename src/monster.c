/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:08:47 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/12/24 11:58:59 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	fill_monster(t_data *data, t_pos pos)
{
	static int	index;
	int			i;

	i = 0;
	while (i < 5)
	{
		mlx_image_to_window(data->mlx, data->mon[i],
			(pos.x + 1) * PIXEL, (pos.y + 1) * PIXEL);
		if (i != 1)
			data->mon[i]->instances[index].enabled = false;
		i++;
	}
	index++;
	data->map.mon_num++;
}

static int	next_move_valid(t_data *data, t_move dir, int x, int y)
{
	x = (x / PIXEL) - 1;
	y = (y / PIXEL) - 1;
	printf("%d %d\n", x, y);
	if (dir == UP && data->map.map[y][x] == WALL)
		return (0);
	else if (dir == DOWN && data->map.map[y + 1][x] == WALL)
		return (0);
	else if (dir == LEFT && data->map.map[y][x - 1] == WALL)
		return (0);
	else if (dir == RIGHT && data->map.map[y][x + 1] == WALL)
		return (0);
	return (1);
}

static t_pos	get_distance(t_data *data, int x, int y)
{
	t_pos	pos;
	t_move	dir;

	dir = INVALID;
	pos.x = 0;
	pos.y = 0;
	if (dir == INVALID && next_move_valid(data, UP, x, y))
		dir = UP;
	else if (dir == INVALID)
		dir = DOWN;
	if (dir == UP && next_move_valid(data, dir, x, y))
		pos.y = -STEP_SIZE;
	else
		dir = DOWN;
	if (dir == DOWN && next_move_valid(data, dir, x, y))
		pos.y = STEP_SIZE;
	else
		dir = UP;
	return (pos);
}

static void	monster_animation_utils(t_data *data, int i)
{
	int				index;
	static t_pos	step[30];

	index = 0;
	while (index < data->map.mon_num)
	{
		step[index] = get_distance(data, data->mon[i / SPEED_M]
				->instances[index].x, data->mon[i / SPEED_M]
				->instances[index].y);
		if ((i / SPEED_M) == 1)
			data->mon[4]->instances[index].enabled = false;
		data->mon[i / SPEED_M]->instances[index].enabled = true;
		data->mon[(i / SPEED_M) - 1]->instances[index].enabled = false;
		data->mon[i / SPEED_M]->instances[index].x += step[index].x;
		data->mon[i / SPEED_M]->instances[index].y += step[index].y;
		index++;
		printf("Monster %d : STEP-SIZEL: %d %d\n", index,  step[index].x, step[index].y);
	}
}

void	monster_animation(t_data *data)
{
	static int	frame;
	int			i;

	i = SPEED_M;
	while (i <= 4 * SPEED_M)
	{
		if (i == frame && i % SPEED_M == 0)
			monster_animation_utils(data, i);
		i++;
	}
	frame++;
	if (frame > 4 * SPEED_M)
		frame = 1;
}
