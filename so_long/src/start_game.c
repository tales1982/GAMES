/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <tlima-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:25:20 by tlima-de          #+#    #+#             */
/*   Updated: 2024/06/05 18:20:17 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_image(void **img, void *mlx, char *path, t_data *data)
{
	*img = mlx_xpm_file_to_image(mlx, path, &data->img_width,
			&data->img_height);
	if (!(*img))
	{
		printf("Error loading image: %s\n", path);
		exit(1);
	}
}

void	copy_sprite_images(t_data *data, t_image_data *img_data, int i,
		int sprite_width, int sprite_height)
{
	data->img_player_down[i] = mlx_new_image(data->mlx, sprite_width,
			sprite_height);
	data->img_player_left[i] = mlx_new_image(data->mlx, sprite_width,
			sprite_height);
	data->img_player_right[i] = mlx_new_image(data->mlx, sprite_width,
			sprite_height);
	data->img_player_up[i] = mlx_new_image(data->mlx, sprite_width,
			sprite_height);
	img_data->dest_img = data->img_player_down[i];
	img_data->src_x = i * sprite_width;
	img_data->src_y = 0;
	copy_image_part(img_data);
	img_data->dest_img = data->img_player_left[i];
	img_data->src_y = sprite_height;
	copy_image_part(img_data);
	img_data->dest_img = data->img_player_right[i];
	img_data->src_y = 2 * sprite_height;
	copy_image_part(img_data);
	img_data->dest_img = data->img_player_up[i];
	img_data->src_y = 3 * sprite_height;
	copy_image_part(img_data);
}

void	initialize_direction_images(t_data *data, void *sprite_sheet,
		int sprite_width, int sprite_height)
{
	int				i;
	t_image_data	img_data;

	i = 0;
	img_data.mlx = data->mlx;
	img_data.src_img = sprite_sheet;
	img_data.width = sprite_width;
	img_data.height = sprite_height;
	while (i < 3)
	{
		copy_sprite_images(data, &img_data, i, sprite_width, sprite_height);
		i++;
	}
}

void	initialize_images(t_data *data)
{
	void	*sprite_sheet;
	int		sprite_width;
	int		sprite_height;

	load_image(&sprite_sheet, data->mlx, "./img/pacMan.xpm", data);
	sprite_width = data->img_width / 3;
	sprite_height = data->img_height / 4;
	initialize_direction_images(data, sprite_sheet, sprite_width,
		sprite_height);
	data->img_player_current = data->img_player_down[0];
	data->frame = 0;
	load_image(&data->img_floor, data->mlx, "./img/0.xpm", data);
	load_image(&data->img_wall, data->mlx, "./img/1.xpm", data);
	load_image(&data->img_collectible, data->mlx, "./img/C.xpm", data);
	load_image(&data->img_exit, data->mlx, "./img/E.xpm", data);
}

void	start_game(t_data *data)
{
	initialize_game_window(data);
	initialize_images(data);
	data->x = 1 * TILE_SIZE;
	data->y = 1 * TILE_SIZE;
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img_player_current,
		data->x, data->y);
	mlx_key_hook(data->win, key_event, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop(data->mlx);
}
/*
° Estas funções trabalham em conjunto para carregar e inicializar as imagens do jogo,
criar uma janela e desenhar o mapa do jogo. O fluxo é o seguinte:
° Carregar e inicializar as imagens de sprites e elementos do jogo.
° Configurar a janela do jogo.
° Desenhar o mapa do jogo.
° Iniciar o loop de eventos para detectar e responder às entradas do usuário.
*/