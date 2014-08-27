/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasson <mmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 09:32:38 by mmasson           #+#    #+#             */
/*   Updated: 2014/01/18 12:44:32 by mmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "wolf3d.h"
#include "mlx.h"

int	check_expose_hook(t_env *env)
{
  mlx_put_image_to_window(env->win->mlx_ptr,
			  env->win->win_ptr,
			  env->img->img_ptr,
			  IMG_POS_X,
			  IMG_POS_Y);
  menu(env);
  return (0);
}

void	free_all(t_env *env)
{
  int	i;

  i = 0;
  while (i < env->file->nbr_lines)
    free(env->file->map[i++]);
  free(env->file->map[i]);
  free(env->file);
  free(env->win);
  free(env->img);
  free(env->background);
  free(env->floor);
  free(env->draw);
  free(env->perso);
  free(env);
}
/*
void	check_actions(t_env *env, int key)
{
  if (key == MINIMAP)
    env->draw->minimap *= -1;
  else if (key == PLUS && env->perso->precision > 0.01)
    env->perso->precision /= 2;
  else if (key == MINUS && env->perso->precision < 10)
    env->perso->precision *= 2;
  else if (key == ENTER)
    add_block(env);
  else if (key == SPACE)
    remove_block(env);
  else if (key == SAVE)
    save(env);
  else if (key == RUN && env->perso->speed == 15)
    env->perso->speed = 5;
  else if (key == RUN && env->perso->speed == 5)
    env->perso->speed = 15;
  else
    return ;
  lets_draw(env);
}
*/
int	check_key_hook(int keycode, t_env *env)
{
  if (keycode == ESC)
    {
      sleep(1);
      myheader("36", "Good bye, hope u had fun ;)\n");
      //mlx_destroy_window(env->win->mlx_ptr, env->win->win_ptr);
      free_all(env);
      exit(1);
    }
  else if (keycode == LEFT)
    left(env);
  else if (keycode == UP)
    up(env);
  else if (keycode == RIGHT)
    right(env);
  else if (keycode == DOWN)
    down(env);
  /*else
    {
      check_actions(env, key);
      return (0);
    }*/
  lets_draw(env);
  return (0);
}
