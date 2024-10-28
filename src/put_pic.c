/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:02:43 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/10/23 15:04:27 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_character_pic1(t_data *data)
{
	data->player.walking[0]
		= ft_texture_to_image(data, "textures/slime/Walk/walk01.png", PIXEL, PIXEL);
	data->player.walking[1]
		= ft_texture_to_image(data, "textures/slime/Walk/walk01.png", PIXEL, PIXEL);
	data->player.walking[2]
		= ft_texture_to_image(data, "textures/slime/Walk/walk02.png", PIXEL, PIXEL);
	data->player.walking[3]
		= ft_texture_to_image(data, "textures/slime/Walk/walk03.png", PIXEL, PIXEL);
	data->player.walking[4]
		= ft_texture_to_image(data, "textures/slime/Walk/walk04.png", PIXEL, PIXEL);
	data->player.walking[5]
		= ft_texture_to_image(data, "textures/slime/Walk/walk03.png", PIXEL, PIXEL);
	data->player.walking[6]
		= ft_texture_to_image(data, "textures/slime/Walk/walk02.png", PIXEL, PIXEL);
	data->player.walking[7]
		= ft_texture_to_image(data, "textures/slime/Walk/walk01.png", PIXEL, PIXEL);
	data->player.idle[0]
		= ft_texture_to_image(data, "textures/slime/Idle/Idle01.png", PIXEL, PIXEL);
	data->player.idle[1]
		= ft_texture_to_image(data, "textures/slime/Idle/Idle02.png", PIXEL, PIXEL);
}

static void	put_character_pic2(t_data *data)
{
	data->player.spin[0]
		= ft_texture_to_image(data, "textures/slime/spin/Spin01.png", PIXEL, PIXEL);
	data->player.spin[1]
		= ft_texture_to_image(data, "textures/slime/spin/Spin02.png", PIXEL, PIXEL);
	data->player.spin[2]
		= ft_texture_to_image(data, "textures/slime/spin/Spin03.png", PIXEL, PIXEL);
	data->player.spin[3]
		= ft_texture_to_image(data, "textures/slime/spin/Spin04.png", PIXEL, PIXEL);
	data->player.spin[4]
		= ft_texture_to_image(data, "textures/slime/spin/Spin05.png", PIXEL, PIXEL);
	data->player.spin[5]
		= ft_texture_to_image(data, "textures/slime/spin/Spin06.png", PIXEL, PIXEL);
	data->player.spin[6]
		= ft_texture_to_image(data, "textures/slime/spin/Spin07.png", PIXEL, PIXEL);
	data->player.spin[7]
		= ft_texture_to_image(data, "textures/slime/spin/Spin08.png", PIXEL, PIXEL);
	data->player.spin[8]
		= ft_texture_to_image(data, "textures/slime/spin/Spin09.png", PIXEL, PIXEL);
	data->player.spin[9]
		= ft_texture_to_image(data, "textures/slime/spin/Spin10.png", PIXEL, PIXEL);
	data->player.spin[10]
		= ft_texture_to_image(data, "textures/slime/spin/Spin11.png", PIXEL, PIXEL);
	data->player.spin[11]
		= ft_texture_to_image(data, "textures/slime/spin/Spin12.png", PIXEL, PIXEL);
}

void	put_pic(t_data *data)
{
	put_character_pic1(data);
	put_character_pic2(data);
}
