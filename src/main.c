/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasson <mmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 09:32:38 by mmasson           #+#    #+#             */
/*   Updated: 2014/01/18 14:31:08 by mmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include </usr/X11/include/X11/X.h>
#include <stdlib.h>
#include "mlx.h"
#include "wolf3d.h"

void  myheader(char *a, char *b)
{
  couleur(a);
  ft_printf(b);
  couleur("0");
}

void	check_macro()
{
	if (WIN_SIZE_X != 600 || WIN_SIZE_Y != 650 || IMG_SIZE_X != 600
		|| IMG_SIZE_Y != 600 || IMG_POS_X != 0 || IMG_POS_Y != 0)
	{
		ft_putstr("Wrong maccros.\n");
		exit (0);
	}
}

void 	menu(t_env *env)
{
	mlx_string_put(env->win->mlx_ptr, env->win->win_ptr, 10,
		WIN_SIZE_Y - 30, 0x00ff00, "Wolf3D");
	mlx_string_put(env->win->mlx_ptr, env->win->win_ptr, 10,
		 WIN_SIZE_Y - 10, 0x00FF00, "mmasson");
	mlx_string_put(env->win->mlx_ptr, env->win->win_ptr, 70,
		 WIN_SIZE_Y - 30, 0xFFFFFF, "LEFT - RIGHT: Turn");
  	mlx_string_put(env->win->mlx_ptr, env->win->win_ptr, 70,
		 WIN_SIZE_Y - 10, 0xFFFFFF, "UP - DOWN: Move");
  	mlx_string_put(env->win->mlx_ptr, env->win->win_ptr, 190,
		 WIN_SIZE_Y - 10, 0xFFFFFF, "ESC: Exit");
  }

  void	wolf(char *file)
  {
  		t_env	*env;

  		check_macro();
  		env = init_struct(env);
  		gimme_env(env->file, file);
  		init_perso(env->perso, env->file);
  		gimme_win(env->win);
  		gimme_img(env->win, env->img);
  		gimme_sky(env);
  		gimme_floor(env);
  		gimme_gun(env);
  		menu(env);
  		lets_draw(env);
  		mlx_expose_hook(env->win->win_ptr, &check_expose_hook, env);
  		mlx_hook(env->win->win_ptr, KeyPress, KeyRelease, &check_key_hook, env);
      mlx_clear_window(env->win->mlx_ptr, env->win->win_ptr); //why
  		mlx_loop(env->win->mlx_ptr);
  }

  int 	main(int argc, char **argv)
  {
  	if (argc == 2)
  		wolf(argv[1]);
  	else
  		ft_putstr("Please insert a map.\n");
  	return (0);
  }