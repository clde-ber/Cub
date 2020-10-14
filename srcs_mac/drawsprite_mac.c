/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawsprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:36:12 by clde-ber          #+#    #+#             */
/*   Updated: 2020/10/14 10:53:17 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_mac.h"

void	draw_sprite_from_mid(t_player *player, int i, int j, int count)
{
	unsigned int	color;
	int				start;
	int				wall_h;
	int 			wall_h2;

	color = 0;
	wall_h = (int)(player->sprite[count][2]);
	wall_h2 = (int)((player->sprite[count][2] + player->sprite[count][6]) / 2);;
	if (player->sprite[count][7] == 0)
		start = (int)(player->sprite[count][3] - (wall_h2 / 2) -
		((wall_h - wall_h2) / 2));
	else if (player->sprite[count][3] == player->struct_screen.x - 1)
		start = (int)(player->sprite[count][7] + (wall_h2 / 2) +
		((wall_h - wall_h2) / 2));
	else
		start = (int)(player->sprite[count][7] + (wall_h2 / 2));
	if (j <= wall_h2 && i <= wall_h2 / 2 && i >= 0 && j >= 0)
		color = set_texture_sprite(player, j * player->ids.xpm_sprite_h /
		wall_h2, (wall_h2 / 2 - i) * player->ids.xpm_sprite_w / wall_h2);
	if (color > 0 && start - i <= player->sprite[count][12] && start - i >=
	player->sprite[count][13] && player->struct_screen.y / 2 - wall_h2 / 2 + j >=
	0 && player->struct_screen.y / 2 - wall_h2 / 2 + j < player->struct_screen.y)
		change_color(player, player->struct_screen.y / 2 - wall_h2 / 2 + j,
		start - i, color);
	if (j <= wall_h2 && i <= wall_h2 / 2 && i >= 0 && j >= 0)
		color = set_texture_sprite(player, j * player->ids.xpm_sprite_h /
		wall_h2, (wall_h2 / 2 + i) * player->ids.xpm_sprite_w / wall_h2);
	if (color > 0 && start + i <= player->sprite[count][12] && start + i >=
	player->sprite[count][13] && player->struct_screen.y / 2 - wall_h2 / 2 + j >=
	0 && player->struct_screen.y / 2 - wall_h2 / 2 + j < player->struct_screen.y)
		change_color(player, player->struct_screen.y / 2 - wall_h2 / 2 + j,
		start + i, color);
}

void	draw_sprite_from_start(t_player *player, int i, int j, int count)
{
	unsigned int	color;
	int				start;
	int				wall_h;
	int 			wall_h2;

	color = 0;
	wall_h = (int)(player->sprite[count][2]);
	wall_h2 = (int)((player->sprite[count][2] + player->sprite[count][6]) / 2);;
	if (player->sprite[count][7] == 0)
		start = (int)(player->sprite[count][3] - (wall_h2 / 2) -
		((wall_h - wall_h2) / 2));
	else if (player->sprite[count][3] == player->struct_screen.x - 1)
		start = (int)(player->sprite[count][7] + (wall_h2 / 2) +
		((wall_h - wall_h2) / 2));
	else
		start = (int)(player->sprite[count][7] + (wall_h2 / 2));
	if (j <= wall_h2 && i <= wall_h2 / 2 && i >= 0 && j >= 0)
		color = set_texture_sprite(player, j * player->ids.xpm_sprite_h /
		wall_h2, (wall_h2 / 2 - i) * player->ids.xpm_sprite_w / wall_h2);
	if (color > 0 && start - i <= player->sprite[count][12] && start - i >=
	player->sprite[count][13] && player->struct_screen.y / 2 - wall_h2 / 2 + j >=
	0 && player->struct_screen.y / 2 - wall_h2 / 2 + j < player->struct_screen.y)
		change_color(player, player->struct_screen.y / 2 - wall_h2 / 2 + j,
		start - i, color);
	if (j <= wall_h2 && i <= wall_h2 / 2 && i >= 0 && j >= 0)
		color = set_texture_sprite(player, j * player->ids.xpm_sprite_h /
		wall_h2, (wall_h2 / 2 + i) * player->ids.xpm_sprite_w / wall_h2);
	if (color > 0 && start + i <= player->sprite[count][12] && start + i >=
	player->sprite[count][13] && player->struct_screen.y / 2 - wall_h2 / 2 + j >=
	0 && player->struct_screen.y / 2 - wall_h2 / 2 + j < player->struct_screen.y)
		change_color(player, player->struct_screen.y / 2 - wall_h2 / 2 + j,
		start + i, color);
}

void	draw_sprite_from_end(t_player *player, int i, int j, int count)
{
	unsigned int	color;
	int				end;
	int				wall_h;
	int				wall_h2;

	color = 0;
	wall_h = (int)(player->sprite[count][2]);
	wall_h2 = (int)((player->sprite[count][2] + player->sprite[count][6]) / 2);
	if (player->sprite[count][7] == 0)
		end = (int)(player->sprite[count][3] - (wall_h2 / 2) -
		((wall_h - wall_h2) / 2));
	else if (player->sprite[count][3] == player->struct_screen.x - 1)
		end = (int)(player->sprite[count][7] + (wall_h2 / 2) +
		((wall_h - wall_h2) / 2));
	else
		end = (int)(player->sprite[count][3] - (wall_h2 / 2));
	if (j <= wall_h2 && i <= wall_h2 / 2 && i >= 0 && j >= 0)
		color = set_texture_sprite(player, j * player->ids.xpm_sprite_h /
		wall_h2, (wall_h2 / 2 - i) * player->ids.xpm_sprite_w / wall_h2);
	if (color > 0 && end - i <= player->sprite[count][12] && end - i >=
	player->sprite[count][13] && player->struct_screen.y / 2 - wall_h2 / 2 + j >=
	0 && player->struct_screen.y / 2 - wall_h2 / 2 + j < player->struct_screen.y)
		change_color(player, player->struct_screen.y / 2 - wall_h2 / 2 + j,
		end - i, color);
	if (j <= wall_h2 && i <= wall_h2 / 2 && i >= 0 && j >= 0)
		color = set_texture_sprite(player, j * player->ids.xpm_sprite_h /
		wall_h2, (wall_h2 / 2 + i) * player->ids.xpm_sprite_w / wall_h2);
	if (color > 0 && end + i <= player->sprite[count][12] && end + i >=
	player->sprite[count][13] && player->struct_screen.y / 2 - wall_h2 / 2 + j >=
	0 && player->struct_screen.y / 2 - wall_h2 / 2 + j < player->struct_screen.y)
		change_color(player, player->struct_screen.y / 2 - wall_h2 / 2 + j,
		end + i, color);
}

void	draw_sprite(t_player *player, int i, int j, int count)
{
//	if ((int)player->sprite[count][14] - (int)player->sprite[count][15] == 0)
//		draw_sprite_from_mid(player, i, j, count);
	if ((int)player->sprite[count][14] - (int)player->sprite[count][15] > 0)
		draw_sprite_from_start(player, i, j, count);
	else
		draw_sprite_from_end(player, i, j, count);
}

void	pivot_textures_sprite(int i, int j, t_player *player)
{
	int count;

	count = 0;
	sort_sprite(player);
	while (player->sprite[count] && (int)player->sprite[count][0] != 0)
	{
		if ((int)(player->sprite[count][2])  <= player->struct_screen.y)
		{
			while (++i < (int)(((player->sprite[count][6] +
			player->sprite[count][2]) / 2)))
			{
				while (++j < (int)(((player->sprite[count][6] +
				player->sprite[count][2]) / 2)))
					draw_sprite(player, i, j, count);
				j = -1;
			}
		}
		i = -1;
		j = -1;
		count++;
	}
}
