/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawsprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:36:12 by clde-ber          #+#    #+#             */
/*   Updated: 2020/08/28 09:52:16 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	register_sprite_start(int i, t_player *player, float angle, float d)
{
	player->sprite[i][4] = player->ray_x + d * sin(angle);
	player->sprite[i][5] = player->ray_y + d * cos(angle);
	player->sprite[i][7] = player->struct_screen.i;
	player->sprite[i][10] = player->struct_screen.x / d;
	check_sprite_sides(player, d, angle, i);
	player->nb_sprites++;
}

void	register_sprite_end(int i, t_player *player, float angle, float d)
{
	player->sprite[i][0] = player->ray_x + d * sin(angle);
	player->sprite[i][1] = player->ray_y + d * cos(angle);
	player->sprite[i][3] = player->struct_screen.i;
	player->sprite[i][9] = (player->map[(int)(player->ray_x + (d - EPSILON) * sin(angle))][(int)(player->ray_y + (d - EPSILON) * cos(angle))] != '2' || player->sprite[i][9] == 0) ? 
		(player->struct_screen.x) / d : player->sprite[i][9];
	if (player->distance > player->sprite[i][9])
		player->sprite[i][9] = player->distance;
}

void	draw_sprite_from_start(t_player *player, int i, int j, int count)
{
	unsigned int	color;
	int				xposition_start;
	int				xposition_end;
	double			wall_h;

	color = 0;
	wall_h = ((player->sprite[count][6] + player->sprite[count][2]) / 2);
	xposition_end =
	(int)(player->sprite[count][3] + (wall_h - (player->sprite[count][3] - player->sprite[count][7])));
	xposition_start = 
	(int)(player->sprite[count][7] - (wall_h - (player->sprite[count][3] - player->sprite[count][7])));
	if (((player->sprite[count][10] - player->sprite[count][9] >= 0 || player->sprite[count][7] == 0) && player->sprite[count][3] != player->struct_screen.x - 1))
	{
	if (j <= wall_h && i <= wall_h && i >= 0 && j >= 0)
	{
		color = set_texture_sprite(player, j * player->ids.xpm_sprite_h /
		wall_h, i * player->ids.xpm_sprite_w / wall_h);
	}
	if (
	color > 0 && xposition_start + i <= player->sprite[count][3]
		&& xposition_start + i >= player->sprite[count][7]
		&& player->struct_screen.y / 2 - wall_h / 2
		+ j >= 0 && player->struct_screen.y / 2 - wall_h / 2 + j <
		player->struct_screen.y)
			change_color(player, player->struct_screen.y / 2 - wall_h / 2 + j,
			xposition_start + i, color);
	}
	else
	{
	if (j <= wall_h && i <= wall_h && i >= 0 && j >= 0)
	{
		color = set_texture_sprite(player, j * player->ids.xpm_sprite_h /
		wall_h, (wall_h - i) * player->ids.xpm_sprite_w / wall_h);
	}
	if (
	color > 0 && xposition_end - i <= player->sprite[count][3]
		&& xposition_end - i >= player->sprite[count][7]
		&& player->struct_screen.y / 2 - wall_h / 2
		+ j >= 0 && player->struct_screen.y / 2 - wall_h / 2 + j <
		player->struct_screen.y)
			change_color(player, player->struct_screen.y / 2 - wall_h / 2 + j,
			xposition_end - i, color);
	}
}

void	pivot_textures_sprite(int i, int j, t_player *player)
{
	int count;

	count = 0;
	sort_sprite(player);
	while (player->sprite[count] && (int)player->sprite[count][0] != 0)
	{
		printf("playeri 9 %f\n", player->sprite[count][9]);
		printf("playeri 10 %f\n", player->sprite[count][10]);
		printf("count %d\n", count);
		printf("player->sprite[count][10] - player->sprite[count][9] %f\n", player->sprite[count][10] - player->sprite[count][9]);
		if (player->sprite[count][10] - player->sprite[count][9] < 0)
			printf("AAAAAAAAAAAAA");
		printf("count 3 - count 7 %f\n", player->sprite[count][3] - player->sprite[count][7]);
		printf("wall_h %f\n", ((player->sprite[count][6] + player->sprite[count][2]) / 2));
		while (--i >= 0)
		{
			while (++j < (int)(((player->sprite[count][2] +
			player->sprite[count][6]) / 2)))
			{
			//	if (player->sprite[count][7] + ((player->sprite[count][3]
			//	- player->sprite[count][7]) / 2) < player->struct_screen.x / 2)
				draw_sprite_from_start(player, i, j, count);
			//	else
			//	draw_sprite_from_end(player, i, j, count);

			}
			j = -1;
		}
		i = player->struct_screen.x;
		j = -1;
		count++;
	}
}
