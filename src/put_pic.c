/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:02:43 by juhtoo-h          #+#    #+#             */
/*   Updated: 2024/12/17 17:48:27 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_character_pic1(t_data *data)
{
	data->player.walking[0]
		= ft_texture_to_image(data, "textures/sprite/down1.png", PIXEL, PIXEL);
	data->player.walking[1]
		= ft_texture_to_image(data, "textures/sprite/down2.png", PIXEL, PIXEL);
	data->player.walking[2]
		= ft_texture_to_image(data, "textures/sprite/down3.png", PIXEL, PIXEL);
	data->player.walking[3]
		= ft_texture_to_image(data, "textures/sprite/down4.png", PIXEL, PIXEL);
	data->player.walking[4]
		= ft_texture_to_image(data, "textures/sprite/down5.png", PIXEL, PIXEL);
	data->player.walking[5]
		= ft_texture_to_image(data, "textures/sprite/down2.png", PIXEL, PIXEL);
	data->player.walking[6]
		= ft_texture_to_image(data, "textures/sprite/down5.png", PIXEL, PIXEL);
	data->player.walking[7]
		= ft_texture_to_image(data, "textures/sprite/right1.png", PIXEL, PIXEL);
	data->player.walking[8]
		= ft_texture_to_image(data, "textures/sprite/right2.png", PIXEL, PIXEL);
	data->player.walking[9]
		= ft_texture_to_image(data, "textures/sprite/right3.png", PIXEL, PIXEL);
	data->player.walking[10]
		= ft_texture_to_image(data, "textures/sprite/right4.png", PIXEL, PIXEL);
	data->player.walking[11]
		= ft_texture_to_image(data, "textures/sprite/right5.png", PIXEL, PIXEL);
}

static void	put_character_pic2(t_data *data)
{
	data->player.walking[12]
		= ft_texture_to_image(data, "textures/sprite/right2.png", PIXEL, PIXEL);
	data->player.walking[13]
		= ft_texture_to_image(data, "textures/sprite/right5.png", PIXEL, PIXEL);
	data->player.walking[14]
		= ft_texture_to_image(data, "textures/sprite/left1.png", PIXEL, PIXEL);
	data->player.walking[15]
		= ft_texture_to_image(data, "textures/sprite/left2.png", PIXEL, PIXEL);
	data->player.walking[16]
		= ft_texture_to_image(data, "textures/sprite/left3.png", PIXEL, PIXEL);
	data->player.walking[17]
		= ft_texture_to_image(data, "textures/sprite/left4.png", PIXEL, PIXEL);
	data->player.walking[18]
		= ft_texture_to_image(data, "textures/sprite/left5.png", PIXEL, PIXEL);
	data->player.walking[19]
		= ft_texture_to_image(data, "textures/sprite/left2.png", PIXEL, PIXEL);
	data->player.walking[20]
		= ft_texture_to_image(data, "textures/sprite/left5.png", PIXEL, PIXEL);
	data->player.walking[21]
		= ft_texture_to_image(data, "textures/sprite/up1.png", PIXEL, PIXEL);
	data->player.walking[22]
		= ft_texture_to_image(data, "textures/sprite/up2.png", PIXEL, PIXEL);
	data->player.walking[23]
		= ft_texture_to_image(data, "textures/sprite/up3.png", PIXEL, PIXEL);
}

static void	put_character_pic3(t_data *data)
{
	data->player.walking[24]
		= ft_texture_to_image(data, "textures/sprite/up4.png", PIXEL, PIXEL);
	data->player.walking[25]
		= ft_texture_to_image(data, "textures/sprite/up5.png", PIXEL, PIXEL);
	data->player.walking[26]
		= ft_texture_to_image(data, "textures/sprite/up2.png", PIXEL, PIXEL);
	data->player.walking[27]
		= ft_texture_to_image(data, "textures/sprite/up5.png", PIXEL, PIXEL);
	data->player.idle[0]
		= ft_texture_to_image(data, "textures/sprite/idle1.png", PIXEL, PIXEL);
	data->player.idle[1]
		= ft_texture_to_image(data, "textures/sprite/idle2.png", PIXEL, PIXEL);
	data->player.death[0]
		= ft_texture_to_image(data, "textures/sprite/death1.png", PIXEL, PIXEL);
	data->player.death[1]
		= ft_texture_to_image(data, "textures/sprite/death2.png", PIXEL, PIXEL);
	data->player.death[2]
		= ft_texture_to_image(data, "textures/sprite/death3.png", PIXEL, PIXEL);
	data->exit.img[0]
		= ft_texture_to_image(data, "textures/exit/exit1.png", PIXEL, PIXEL);
	data->exit.img[1]
		= ft_texture_to_image(data, "textures/exit/exit1.png", PIXEL, PIXEL);
	data->exit.img[2]
		= ft_texture_to_image(data, "textures/exit/exit2.png", PIXEL, PIXEL);
}

static void	put_pictures(t_data *data)
{
	data->exit.img[3]
		= ft_texture_to_image(data, "textures/exit/exit3.png", PIXEL, PIXEL);
	data->exit.img[4]
		= ft_texture_to_image(data, "textures/exit/exit4.png", PIXEL, PIXEL);
	data->digit[0] = ft_texture_to_image(data, "textures/0.png", PIXEL, PIXEL);
	data->digit[1] = ft_texture_to_image(data, "textures/1.png", PIXEL, PIXEL);
	data->digit[2] = ft_texture_to_image(data, "textures/2.png", PIXEL, PIXEL);
	data->digit[3] = ft_texture_to_image(data, "textures/3.png", PIXEL, PIXEL);
	data->digit[4] = ft_texture_to_image(data, "textures/4.png", PIXEL, PIXEL);
	data->digit[5] = ft_texture_to_image(data, "textures/5.png", PIXEL, PIXEL);
	data->digit[6] = ft_texture_to_image(data, "textures/6.png", PIXEL, PIXEL);
	data->digit[7] = ft_texture_to_image(data, "textures/7.png", PIXEL, PIXEL);
	data->digit[8] = ft_texture_to_image(data, "textures/8.png", PIXEL, PIXEL);
	data->digit[9] = ft_texture_to_image(data, "textures/9.png", PIXEL, PIXEL);
}

void	put_pic(t_data *data)
{
	put_character_pic1(data);
	put_character_pic2(data);
	put_character_pic3(data);
	put_pictures(data);
}
