/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sky.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasson <mmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 09:32:38 by mmasson           #+#    #+#             */
/*   Updated: 2014/01/18 12:36:43 by mmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "wolf3d.h"

void		put_background(t_env *env)
{
  env->draw->y = 0;
  while (env->draw->y < IMG_SIZE_Y)
    {
      if (env->draw->y < IMG_SIZE_Y / 2
	  && env->background->x == IMG_SIZE_X
	  && env->background->y == IMG_SIZE_Y / 2)
	cpy_img(env);
        else if (env->draw->y > IMG_SIZE_Y / 2
	       && env->floor->x == IMG_SIZE_X
	       && env->floor->y == IMG_SIZE_Y / 2)
	cpy_floor(env);
      env->draw->y++;
    }
}