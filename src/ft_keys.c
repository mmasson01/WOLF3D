/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasson <mmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 09:32:38 by mmasson           #+#    #+#             */
/*   Updated: 2014/01/17 16:51:24 by mmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "wolf3d.h"


void	right(t_env *env)
{
	int rot;

	if (env->perso->speed == 15) // de base = 15
		rot = 5;
	if (env->perso->angle < 360 - rot)
		env->perso->angle += rot;
	else
		env->perso->angle = 0;
}

void	left(t_env *env)
{
  int	rot;

  if (env->perso->speed == 15)
    rot = 5;
  if (env->perso->angle == 0)
    env->perso->angle = 360;
  env->perso->angle -= rot;
}

void	up(t_env *env)
{
	float	case_x;
	float 	case_y;
	float 	new_x;
	float 	new_y;
	float 	angle;

	case_x = CASE_SIZE_X(env->file->size_line);
	case_y = CASE_SIZE_Y(env->file->nbr_lines);
	angle = RADIAN(env->perso->angle);
	new_x = cos(angle) * case_x / env->perso->speed;
	new_y = sin(angle) * case_y / env->perso->speed;
	if (env->perso->x + new_x > 0
		&& env->perso->y - new_y > 0
		&& env->perso->x + new_x < IMG_SIZE_X
		&& env->perso->y - new_y < IMG_SIZE_Y
		&& env->file->map[(int)((env->perso->y -new_y) / case_y)]
		[(int)((env->perso->x + new_x) / case_x)] == 0)
	{
		env->perso->x += new_x;
		env->perso->y -= new_y;
	}
}

void	down(t_env *env)
{
  float	case_x;
  float	case_y;
  float	new_x;
  float	new_y;
  float	angle;

  case_x = CASE_SIZE_X(env->file->size_line);
  case_y = CASE_SIZE_Y(env->file->nbr_lines);
  angle = RADIAN(env->perso->angle);
  new_x = cos(angle) * case_x / env->perso->speed;
  new_y = sin(angle) * case_y / env->perso->speed;
  if (env->perso->x - new_x > 0
      && env->perso->y + new_y > 0
      && env->perso->x - new_x < IMG_SIZE_X
      && env->perso->y + new_y < IMG_SIZE_Y
      && env->file->map[(int)((env->perso->y + new_y) / case_y)]
      [(int)((env->perso->x - new_x) / case_x)] == 0)
    {
      env->perso->x -= new_x;
      env->perso->y += new_y;
    }
}