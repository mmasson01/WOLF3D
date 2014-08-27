/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasson <mmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 09:32:38 by mmasson           #+#    #+#             */
/*   Updated: 2014/01/18 14:35:38 by mmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "wolf3d.h"

void	cpy_img(t_env *env)
{
  int	i;
  int	x;
  int	y;

  env->draw->x = 0;
  while (env->draw->x < IMG_SIZE_X)
    {
      i = 0;
      x = (int)env->draw->x * env->img->bpp / 8;
      y = (int)env->draw->y * env->img->size_line;
      env->img->data[x + i + y] = env->background->data[x + y]; // env->background->data[x + i++ + y]
      env->img->data[x + 1 + y] = env->background->data[x +1 + y];
      env->img->data[x + 2 + y] = env->background->data[x + 2 + y];
      //env->img->data[x + y] = env->background->data[x + 1 + y];
      //env->img->data[x + y] = env->background->data[x +2 + y];
      //env->img->data[x + y] = env->background->data[x +3 + y];
      env->draw->x++;
    }
}

void	cpy_floor(t_env *env)
{
  int	i;
  int	x;
  int	y;
  int	y_floor;

  env->draw->x = 0;
  while (env->draw->x < IMG_SIZE_X)
    {
      i = 0;
      x = (int)env->draw->x * env->img->bpp / 8;
      y = (int)env->draw->y * env->img->size_line;
      y_floor = (int)((env->draw->y - 300) * env->img->size_line);
      env->img->data[x + i + y] = env->floor->data[x + y_floor];
      env->img->data[x + 1 + y] = env->floor->data[x +1 + y_floor];
      env->img->data[x + 2 + y] = env->floor->data[x +2 + y_floor];
      env->draw->x++;
    }

}

void	cpy_gun(t_env *env)
{
  int	x;
  int	y;
  int	x_gun;
  int	y_gun;

  env->draw->y = -1;
  while (++env->draw->y + 300 < IMG_SIZE_Y)
    {
      env->draw->x = -1;
      while (++env->draw->x < env->gun->x)
	{
	  x = (int)(env->draw->x + 150)* env->img->bpp / 8;
	  y = (int)(env->draw->y + 300) * env->img->size_line;
	  x_gun = (int)env->draw->x * env->gun->bpp / 8;
	  y_gun = (int)env->draw->y * env->gun->size_line;
	  if (env->gun->data[x_gun + y_gun]
	      || env->gun->data[x_gun + 1 + y_gun + 1]
	      || env->gun->data[x_gun + 2 + y_gun + 2])
	    {
	      env->img->data[x + y] = env->gun->data[x_gun + y_gun];
	      env->img->data[x + 1 + y] = env->gun->data[x_gun + 1 + y_gun];
	      env->img->data[x + 2 + y] = env->gun->data[x_gun + 2 + y_gun];
	    }
	}
    }
}
