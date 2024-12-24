/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:04:10 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/12/19 11:03:57 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	itow(t_data *data, mlx_image_t *img, int32_t x, int32_t y)
{
	mlx_image_to_window(data->mlx, img, x, y);
}

void	display_moves(t_data *data)
{
	int32_t		x;
	int32_t		y;
	int			i;
	mlx_image_t	*image;

	image = ft_texture_to_image(data, "textures/moves.png", PIX_D * 4, PIX_D);
	itow(data, image, PIXEL, 30);
	x = PIX_D * 7;
	y = 30;
	i = 0;
	while (i < 10)
	{
		itow(data, data->digit[i], x, y);
		itow(data, data->digit[i], x + PIX_D, y);
		itow(data, data->digit[i], x + (2 * PIX_D), y);
		if (i != 0)
		{
			data->digit[i]->instances[0].enabled = false;
			data->digit[i]->instances[1].enabled = false;
			data->digit[i]->instances[2].enabled = false;
		}
		i++;
	}
}

void	moves_moves(t_data *data)
{
	int	arr[3];
	int	i;
	int	index;

	arr[0] = data->moves / 100;
	arr[1] = (data->moves % 100) / 10;
	arr[2] = data->moves % 10;
	i = 0;
	while (i < 3)
	{
		index = 0;
		while (index < 10)
		{
			data->digit[index]->instances[i].enabled = arr[i] == index;
			index++;
		}
		i++;
	}
}
