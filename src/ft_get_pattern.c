/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pattern.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasson <mmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 09:32:38 by mmasson           #+#    #+#             */
/*   Updated: 2014/01/18 15:57:49 by mmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "wolf3d.h"
#include "mlx.h"

void	gimme_sky(t_env *env)
{
  int	*x;
  int	*y;

  x = malloc(sizeof(int));
  y = malloc(sizeof(int));
  env->background = malloc(sizeof(*(env->background))); // malloc re
  if (x == NULL || y == NULL || env->background == NULL)
    exit (-1);
  env->background->img_ptr = mlx_xpm_file_to_image(env->win->mlx_ptr,
						    "textures/nyan.xpm", x, y);
  if (env->background->img_ptr == NULL)
    exit (-1);
  env->background->data = mlx_get_data_addr(env->background->img_ptr,
					     &(env->background->bpp),
					     &(env->background->size_line),
					     &(env->background->endian));
  if (env->background->data == NULL)
    exit (-1);
  env->background->x = *x;
  env->background->y = *y;
}

void	gimme_floor(t_env *env)
{
  int	*x;
  int	*y;

  x = malloc(sizeof(int)); // maalocu
  y = malloc(sizeof(int)); // malloc
  env->floor = malloc(sizeof(*(env->floor)));
  if (x == NULL || y == NULL || env->floor == NULL)
    exit(-1);
  env->floor->img_ptr = mlx_xpm_file_to_image(env->win->mlx_ptr,
					       "textures/floor.xpm", x, y);
  if (env->floor->img_ptr == NULL)
    exit(-1);
  env->floor->data = mlx_get_data_addr(env->floor->img_ptr,
					&(env->floor->bpp),
					&(env->floor->size_line),
					&(env->floor->endian));
  if (env->floor->data == NULL)
    exit(-1);
  env->floor->x = *x;
  env->floor->y = *y;
}

void	gimme_gun(t_env *env)
{
  int	*x;
  int	*y;

  x = malloc(sizeof(int)); //malloc
  y = malloc(sizeof(int));
  env->gun = malloc(sizeof(*(env->floor)));
  if (x == NULL || y == NULL || env->gun == NULL)
    exit(-1);
  env->gun->img_ptr = mlx_xpm_file_to_image(env->win->mlx_ptr,
					     "textures/gun.xpm", x, y);
  if (env->gun->img_ptr == NULL)
    exit(-1);
  env->gun->data = mlx_get_data_addr(env->gun->img_ptr,
				      &(env->gun->bpp),
				      &(env->gun->size_line),
				      &(env->gun->endian));
  if (env->gun->data == NULL)
    exit(-1);
  env->gun->x = *x;
  env->gun->y = *y;
}