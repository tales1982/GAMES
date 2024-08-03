/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <tlima-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:22:21 by tlima-de          #+#    #+#             */
/*   Updated: 2024/06/05 18:18:51 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_element(t_data *data, int x, int y, void *img)
{
	mlx_put_image_to_window(data->mlx, data->win, img, x * TILE_SIZE, y
		* TILE_SIZE);
}

void	draw_player(t_data *data, int x, int y)
{
	draw_element(data, x, y, data->img_floor);
	draw_element(data, x, y, data->img_player_current);
	data->x = x * TILE_SIZE;
	data->y = y * TILE_SIZE;
}

void	draw_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map[y][x] == 1)
				draw_element(data, x, y, data->img_wall);
			else if (data->map[y][x] == 0)
				draw_element(data, x, y, data->img_floor);
			else if (data->map[y][x] == 2)
				draw_element(data, x, y, data->img_collectible);
			else if (data->map[y][x] == 4)
				draw_player(data, x, y);
			x++;
		}
		y++;
	}
}

/*
A função draw_map percorre a matriz data->map,
	desenhando imagens de parede ou chão em cada
posição na janela do jogo,
	de acordo com os valores presentes na matriz. Usa a biblioteca
MiniLibX para colocar as imagens na janela do jogo,
	formando a visualização completa do mapa.
*/
