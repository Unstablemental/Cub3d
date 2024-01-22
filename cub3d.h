/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 03:36:35 by mlahlafi          #+#    #+#             */
/*   Updated: 2024/01/22 04:03:21 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"
// #define WIDTH 512
// #define HEIGHT 512
#define TRUE 1
#define FALSE 0
#define TILE_SIZE 128
#define MAP_NUM_ROWS 104
#define MAP_NUM_COLS 65
// #define MAP_NUM_ROWS 13
// #define MAP_NUM_COLS 20
// #define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
#define WINDOW_WIDTH 1280
#define TEXTURE_HEIGHT 128
#define TEXTURE_WIDTH 128
// #define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)
#define WINDOW_HEIGHT 768
#define FOV_ANGLE (80 * M_PI / 180)
#define NUM_RAYS WINDOW_WIDTH
#define SACALE_FACTOR 0.5

// const int map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
//     {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1' ,'1', '1', '1', '1', '1', '1', '1'},
//     {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
//     {'1', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
//     {'1', '0', '0', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '0', '1'},
//     {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
//     {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '1'},
//     {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '1'},
//     {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '1'},
//     {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '0', '0', '1'},
//     {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
//     {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
//     {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
//     {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
// };
const  char map[104][65]= {
{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
{'1','0','0','0','0','0','1','0','0','0','0','0','0','0','1','1','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','0','0','0','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','0','0','0','0','1','1','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','0','0','0','0','0','1','1','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','1','1','0','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','1','0','0','0','0','1','1','0','0','0','0','0','0','1','2','2','2','2','2','2','1','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','0','0','0','0','0','0','1','0','0','0','0','0','0','1','2','2','2','2','2','2','1','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','0','0','0','0','0','0','1','0','0','0','0','0','0','1','2','2','2','2','2','2','1','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','0','0','0','0','0','0','1','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','0','0','0','0','0','0','1','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','1','1','1','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','1','0','0','0','0','1','1','0','0','0','0','0','0','1','0','0','1','1','1','0','0','0','0','0','0','0','0','0','0','1','1','0','0','1','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','1','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','1','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','1','1','0','0','0','0','0','0','0','0','0','0','0','1','1','0','0','1','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','1','1','1','0','0','0','1','1','1','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','N','0','0','0','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','1','1','1','1','1','1','1','1','1','1','1','1','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','1','0','0','0','0','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','1','0','0','0','0','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','1','0','0','0','0','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','1','0','0','0','0','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','0','0','0','0','0','1','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','1','0','0','0','0','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','1','0','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','2','2','2','2','2','1','1','1','1','1','0','1','1','1','1','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','1','0','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','1','1','1','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','1','0','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','1','0','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','1','1','1','1','1','0','0','0','0','0','0','0','0','0','0','0','0','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','0','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','1','0','0','0','1','1','1','1','1','1','0','1','1','1','1','1','1','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','1','0','0','0','0','0','0','0','1','0','0','0','1','2','2','2','2','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','1','0','0','0','0','0','0','0','0','0','0','0','1','2','2','2','2','1','0','0','0','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','1','0','0','0','0','0','0','0','1','0','0','0','1','2','2','2','2','1','0','0','0','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','1','1','1','1','0','1','1','1','1','0','0','0','1','2','2','2','2','1','0','0','0','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','2','1','0','0','0','1','2','1','0','1','0','1','2','2','2','2','1','0','0','0','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','2','1','0','0','0','1','1','1','0','1','1','1','2','2','2','2','1','0','0','0','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','2','1','0','0','0','0','0','0','0','0','0','1','2','2','2','2','1','0','0','0','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','2','1','1','1','1','1','1','0','0','0','0','1','2','2','2','2','1','1','1','1','1','1','0','1','1','1','1','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','1','1','0','0','0','1','2','2','2','2','2','2','2','2','1','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','1','0','0','0','1','2','2','2','2','2','2','2','2','1','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','1','0','0','0','1','2','2','2','2','2','2','2','1','0','1','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','1','2','2','2','2','2','2','1','1','1','1','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','0','0','1','0','0','0','1','0','0','0','0','0','1','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','1','0','1','0','0','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','1','1','0','1','0','1','0','1','0','1','0','1','1','1','0','1','0','1','1','1','0','1','1','1','0','1','1','1','0','1','1','1','0','1','0','1','1','1','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','1','0','0','0','1','0','1','0','1','0','1','0','1','0','0','0','1','0','0','0','0','0','1','0','1','0','1','0','0','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','0','1','1','1','0','1','1','1','1','1','0','1','0','1','1','1','1','1','1','1','0','1','0','1','0','1','1','1','0','1','1','1','1','1','1','1','1','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','0','1','0','1','0','1','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','1','0','1','0','0','0','1','0','1','0','0','0','1','0','0','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','0','1','0','1','1','1','1','1','0','1','0','1','1','1','1','1','1','1','0','1','0','1','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','0','1','0','1','0','0','0','1','0','0','0','0','0','1','0','1','0','0','0','0','0','1','0','0','0','0','0','1','0','1','0','0','0','0','0','1','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','0','1','0','1','0','1','0','1','1','1','0','1','1','1','0','1','1','1','0','1','0','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','0','0','1','0','1','0','1','0','0','0','0','0','1','0','0','0','0','0','1','0','1','0','1','0','0','0','1','0','0','0','1','0','0','0','0','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','0','1','0','1','0','1','1','1','1','1','1','1','0','1','1','1','0','1','1','1','1','1','0','1','0','1','1','1','1','1','0','1','0','1','1','1','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','0','1','0','0','0','0','0','0','0','1','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','1','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','1','1','0','1','0','1','0','1','1','1','1','1','0','1','1','1','0','1','0','1','0','1','0','1','1','1','0','1','1','1','0','1','1','1','1','1','1','1','1','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','0','1','0','1','0','0','0','0','0','0','0','1','0','0','0','0','0','1','0','1','0','0','0','1','0','0','0','0','0','1','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','0','1','1','1','0','1','1','1','0','1','0','1','1','1','0','1','0','1','0','1','1','1','1','1','1','1','1','1','0','1','0','1','1','1','1','1','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','1','0','0','0','0','0','1','0','1','0','0','0','1','0','1','0','1','0','1','0','0','0','0','0','0','0','1','0','0','0','0','0','1','0','1','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','1','1','0','1','1','1','0','1','1','1','0','1','0','1','0','1','1','1','1','1','0','1','1','1','0','1','1','1','0','1','1','1','0','1','0','1','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','0','0','0','1','0','0','0','1','0','1','0','1','0','1','0','0','0','0','0','1','0','0','0','1','0','0','0','1','0','0','0','1','0','1','0','1','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','1','1','0','1','0','1','0','1','0','1','1','1','0','1','1','1','1','1','0','1','0','1','1','1','0','1','1','1','1','1','0','1','0','1','0','1','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','0','0','0','1','0','1','0','1','0','0','0','1','0','1','0','0','0','1','0','0','0','0','0','1','0','0','0','1','0','1','0','1','0','1','0','0','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','1','1','0','1','0','1','0','1','1','1','0','1','0','1','1','1','0','1','0','1','0','1','1','1','1','1','1','1','0','1','1','1','0','1','1','1','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','0','1','0','1','0','1','0','0','0','0','0','1','0','1','0','0','0','0','0','1','0','0','0','1','0','0','0','1','0','0','0','1','0','1','0','1','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','0','1','1','1','0','1','0','1','1','1','1','1','1','1','1','1','0','1','0','1','1','1','1','1','0','1','1','1','0','1','0','1','0','1','0','1','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','1','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','1','0','0','0','1','0','0','0','0','0','1','0','1','0','1','0','1','0','1','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','0','1','0','1','1','1','0','1','0','1','0','1','0','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','0','1','1','1','0','1','0','1','1','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','0','1','0','1','0','0','0','1','0','1','0','1','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','1','0','0','0','1','0','0','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','0','1','0','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','0','1','1','1','1','1','1','1','1','1','1','1','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','0','1','0','0','0','1','0','1','0','0','0','0','0','1','0','0','0','0','0','1','0','0','0','1','0','1','0','0','0','0','0','1','0','0','0','0','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','1','1','0','1','1','1','0','1','0','1','1','1','1','1','1','1','0','1','0','1','1','1','1','1','0','1','0','1','0','1','0','1','1','1','0','1','1','1','1','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','1','0','0','0','0','0','0','0','1','0','0','0','0','0','1','0','1','0','0','0','1','0','0','0','0','0','1','0','1','0','0','0','0','0','0','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','1','1','1','1','1','1','1','1','0','1','1','1','0','1','0','1','0','1','0','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','0','0','0','0','0','0','0','1','0','0','0','0','0','1','0','1','0','0','0','0','0','1','0','0','0','0','0','1','0','0','0','1','0','1','0','0','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','1','1','0','1','0','1','0','1','1','1','1','1','0','1','1','1','0','1','1','1','1','1','0','1','0','1','1','1','1','1','1','1','0','1','0','1','0','1','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','1','0','1','0','1','0','0','0','0','0','1','0','0','0','0','0','0','0','1','0','1','0','1','0','0','0','0','0','1','0','0','0','1','0','1','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','0','1','1','1','0','1','0','1','0','1','1','1','0','1','1','1','1','1','0','1','1','1','0','1','0','1','1','1','0','1','1','1','0','1','0','1','1','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','0','1','0','0','0','1','0','1','0','1','0','0','0','0','0','1','0','0','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','1','0','0','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','0','1','0','1','1','1','0','1','0','1','0','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','0','1','0','1','1','1','0','1','0','1','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','0','1','0','0','0','0','0','1','0','1','0','1','0','1','0','0','0','0','0','0','0','0','0','0','0','1','0','1','0','0','0','1','0','0','0','1','0','1','2','2','2','2','2','2','2','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','0','1','1','1','1','1','1','1','0','1','0','1','0','1','0','1','1','1','0','1','1','1','1','1','0','1','0','1','1','1','0','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','1','0','0','0','0','0','1','0','0','0','1','0','0','0','1','0','1','0','0','0','0','0','0','0','1','0','1','0','1','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','0','0','0','0','0','0','0','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','0','0','0','0','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','0','0','0','0','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','0','0','0','0','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','0','0','0','0','0','0','0','1'},
{'1','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','2','1','1','1','1','1','1','1','1','1'},
};


//"1"1
typedef struct info
{
    int		facingDown;
	int		facingRight;
	float	xIntercept;
	float	yIntercept;
	float	xStep;
	float	yStep;
	float	wallHitX;
	float	wallHitY;
	int		wallContent;
	float	nextX;
	float	nextY;
	float	xCheck;
	float	yCheck;
	int		foundWallHit;
} info;

typedef struct Ray
{
    float   rayAngle;
    float   wallHitX;
    float   wallHitY;
    float   distance;
    int     wasHitVertical;
    int     wasHitHorz;
    int     isFacingUp;
    int     isFacingDown;
    int     isFacingLeft;
    int     isFacingRight;
    int     wallHitContent;
} Rays;

typedef struct Player
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turnDirection;
	int		walkDirection;
	float	rotationAngle;
	float	walkSpeed;
	float	turnSpeed;
    int     turnDirection2;
    int     sideWalkDirection;
} Player;

typedef struct cub3d
{
    mlx_t			*mlx;
    mlx_image_t		*image;
    Player			p;
    Rays			rays[NUM_RAYS];
    mlx_texture_t   *texture[4];
    uint32_t		*choice;
    uint32_t		**tab;
    char			**map;
    unsigned int	HEIGHT;
    unsigned int	WIDTH;
    uint32_t         F;
    uint32_t         S;
} cub3d_t;

int		    mapHasWallAt(cub3d_t *cub,float x, float y);
void	    ft_horizentalIntersection(float rayAngle, int id, info * info1, cub3d_t *cub);
void	    ft_verticalIntersection(float rayAngle, int id, info * info2, cub3d_t *cub);
void	    ft_chooseSmallestDistance(info info1, info info2, int id, float rayAngle, cub3d_t *cub);
void        ft_hook(void* param);
void        ft_my_keyhook(mlx_key_data_t keydata, void *param);
void	    ft_renderMap(cub3d_t *cub);
void	    ft_renderPlayer(cub3d_t *cube);
void	    ft_move_player(cub3d_t *cub);
void	    ft_cast_rays(cub3d_t *cub);
void	    ft_generate_projection(cub3d_t *cub, uint32_t tileColor);
void	    ft_DDA(int X0, int Y0, int X1, int Y1, cub3d_t *cub);
uint32_t    ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);

#endif