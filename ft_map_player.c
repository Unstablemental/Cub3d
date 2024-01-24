/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:57:49 by mlahlafi          #+#    #+#             */
/*   Updated: 2024/01/24 02:11:51 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_has_wall_at(t_cub3d *cub, float x, float y)
{
	int	mapgrid_index_x;
	int	mapgrid_index_y;

	if (x < 0 || x > map_num_cols * tile_size || y < 0
		|| y > map_num_rows * tile_size)
		return (TRUE);
	mapgrid_index_x = floor(x / tile_size);
	mapgrid_index_y = floor(y / tile_size);
	if (mapgrid_index_x > map_num_cols)
	{
		mapgrid_index_x = map_num_cols;
	}
	if (mapgrid_index_y > map_num_rows)
	{
		mapgrid_index_y = map_num_rows;
	}
	// printf("mapgrid_index_y %d ;; mapgrid_index_x %d\n",mapgrid_index_y , mapgrid_index_x);
	return (cub->map[mapgrid_index_y][mapgrid_index_x] != '0');
}

void	ft_move_player(t_cub3d *cub)
{
	float	move_step;
	float	move_step2;
	float	new_player_x;
	float	new_player_y;

	cub->p.rotation_angle += cub->p.turnDirection * cub->p.turnSpeed * 0.2;
	move_step = cub->p.walkDirection * cub->p.walkSpeed * 0.1;
	move_step2 = cub->p.sideWalkDirection * cub->p.walkSpeed / 4 * 0.1;
	new_player_x = cub->p.x + cos(cub->p.rotation_angle) * move_step * 0.2
		+ cos(cub->p.rotation_angle + M_PI / 2) * move_step2;
	new_player_y = cub->p.y + sin(cub->p.rotation_angle) * move_step * 0.2
		+ sin(cub->p.rotation_angle + M_PI / 2) * move_step2;
	if (!map_has_wall_at(cub, new_player_x, cub->p.y))
	{
		cub->p.x = new_player_x;
	}
	if (!map_has_wall_at(cub, cub->p.x, new_player_y))
	{
		cub->p.y = new_player_y;
	}
}

void	ft_render_player(t_cub3d *cube)
{
	mlx_put_pixel(cube->image, 149, 99, 0x0000FFFF);
	mlx_put_pixel(cube->image, 150, 99, 0x0000FFFF);
	mlx_put_pixel(cube->image, 151, 99, 0x0000FFFF);
	mlx_put_pixel(cube->image, 149, 100, 0x0000FFFF);
	mlx_put_pixel(cube->image, 150, 100, 0x0000FFFF);
	mlx_put_pixel(cube->image, 151, 100, 0x0000FFFF);
	mlx_put_pixel(cube->image, 149, 101, 0x0000FFFF);
	mlx_put_pixel(cube->image, 150, 101, 0x0000FFFF);
	mlx_put_pixel(cube->image, 151, 101, 0x0000FFFF);
	ft_DDA(300, 200, 300 + (float) cos(cube->p.rotation_angle)
		* 40, 200 + sin(cube->p.rotation_angle) * 40, cube);
}

void	ft_set_color(t_cub3d *cub, int startX, int startY, int i)
{
	int		x;
	int		y;
	int		tile_color;
	int		j;

	j = 0;
	while (j < 300)
	{
		x = (startX + j) / tile_size - 1;
		y = (startY + i) / tile_size - 1;
		if (x < 0 || y < 0)
			tile_color = ft_pixel(0, 0, 0, 0);
		else if (x < map_num_cols && y < map_num_rows && cub->map[y][x] == '0')
			tile_color = 0xFFFFFFFF;
		else if (x < map_num_cols && y < map_num_rows && cub->map[y][x] == '1')
			tile_color = 0x808080FF;
		else
			tile_color = ft_pixel(0, 0, 0, 0);
		mlx_put_pixel(cub->image, j, i, tile_color);
		j++;
	}
}

void	ft_render_map(t_cub3d *cub)
{
	int		i;
	int		j;
	int		tile_color;
	int		start_x;
	int		start_y;

	1 && (i = 0) && (j = 0) && (tile_color = 0);
	i = 0;
	j = 0;
	start_x = cub->p.x - 150 + tile_size;
	start_y = cub->p.y - 100 + tile_size;
	while (i < 200)
	{
		j = 0;
		ft_set_color(cub, start_x, start_y, i);
		i++;
	}
}
