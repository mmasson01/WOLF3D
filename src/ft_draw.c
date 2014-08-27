/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasson <mmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 12:10:46 by mmasson           #+#    #+#             */
/*   Updated: 2014/01/18 14:12:00 by mmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx.h"
#include "wolf3d.h"

void		put_wall(t_env *env, double angle)
{
  float	dist;
  float	size;

  dist = pow(env->draw->x - env->perso->x, 2);
  dist += pow(env->draw->y - env->perso->y, 2);
  dist = sqrt(dist);
  size = IMG_SIZE_Y / dist * 25 / cos(RADIAN(env->perso->angle - angle));
  if (size > IMG_SIZE_Y - 1)
    size = IMG_SIZE_Y - 1;
  env->draw->x = angle - ANGLE_MIN(env->perso->angle) + 360;
  env->draw->x *= (IMG_SIZE_X / 60);
  env->draw->y = (IMG_SIZE_Y - size) / 2;
  while (env->draw->y < (IMG_SIZE_Y + size) / 2)
    {
      ft_pixel_put_to_image(env->img, env->win, env->draw);
      env->draw->y++;
    }
}

void	find_intersection(t_env *env, int case_x, int case_y, float angle)
{
  while (env->draw->y >= 0
	 && env->draw->x >= 0
	 && env->draw->y < IMG_SIZE_Y
	 && env->draw->x < IMG_SIZE_X
	 && env->file->map[(int)env->draw->y / case_y]
	 [(int)env->draw->x / case_x] == 0)
    {
      env->draw->x += cos(RADIAN(angle)) * 2;
      env->draw->y -= sin(RADIAN(angle)) * 2;
    }
  while (env->draw->y >= 0
	 && env->draw->x >= 0
	 && env->draw->y < IMG_SIZE_Y
	 && env->draw->x < IMG_SIZE_X
	 && env->file->map[(int)env->draw->y / case_y]
	 [(int)env->draw->x / case_x])
    {
      env->draw->x -= cos(RADIAN(angle)) * env->perso->precision * 1;
      env->draw->y += sin(RADIAN(angle)) * env->perso->precision * 1;
    }
} 

void	search_walls(t_env *env)
{
  int		case_x;
  int		case_y;
  float	angle;

  case_x = CASE_SIZE_X(env->file->size_line);
  case_y = CASE_SIZE_Y(env->file->nbr_lines);
  angle = ANGLE_MIN(env->perso->angle) + 360;
  while (angle < ANGLE_MAX(env->perso->angle) + 360)
    {
      env->draw->x = env->perso->x;
      env->draw->y = env->perso->y;
      find_intersection(env, case_x, case_y, angle);
      env->draw->x += cos(RADIAN(angle)) * env->perso->precision;
      env->draw->y -= sin(RADIAN(angle)) * env->perso->precision;
      gimme_color(env,
		  env->draw->x - cos(RADIAN(angle)) * env->perso->precision,
		  env->draw->y + sin(RADIAN(angle)) * env->perso->precision,
		  angle);
      put_wall(env, angle);
      angle += 0.1;
    }
}

void		lets_draw(t_env *env)
{
  put_background(env);
  search_walls(env);
  if (env->gun->x == 450 && env->gun->y == 350)
    cpy_gun(env);
  //mlx_clear_window(env->win->mlx_ptr, env->win->win_ptr);
  mlx_put_image_to_window(env->win->mlx_ptr,
			  env->win->win_ptr,
			  env->img->img_ptr,
			  IMG_POS_X,
			  IMG_POS_Y);
}
