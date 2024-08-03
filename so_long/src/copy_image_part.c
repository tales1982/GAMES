/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_image_part.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <tlima-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:22:08 by tlima-de          #+#    #+#             */
/*   Updated: 2024/06/05 18:18:43 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	copy_image_part(t_image_data *data)
{
	data->src_data = mlx_get_data_addr(data->src_img, &data->src_bpp,
			&data->src_size_line, &data->src_endian);
	data->dest_data = mlx_get_data_addr(data->dest_img, &data->dest_bpp,
			&data->dest_size_line, &data->dest_endian);
	data->y = 0;
	while (data->y < data->height)
	{
		data->x = 0;
		while (data->x < data->width)
		{
			data->src_index = ((data->src_y + data->y) * data->src_size_line)
				+ ((data->src_x + data->x) * (data->src_bpp / 8));
			data->dest_index = (data->y * data->dest_size_line) + (data->x
					* (data->dest_bpp / 8));
			data->i = 0;
			while (data->i < (data->src_bpp / 8))
			{
				data->dest_data[data->dest_index
					+ data->i] = data->src_data[data->src_index + data->i];
				data->i++;
			}
			data->x++;
		}
		data->y++;
	}
}

/*
A função copy_image_part copia uma sub-região especificada da imagem fonte
para a imagem destino, processando os dados das imagens diretamente para
garantir que cada pixel sejacorretamente transferido de uma imagem para a outra.
*/