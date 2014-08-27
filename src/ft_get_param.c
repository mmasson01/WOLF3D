/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasson <mmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 09:32:38 by mmasson           #+#    #+#             */
/*   Updated: 2014/01/18 12:51:29 by mmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "mlx.h"
#include "wolf3d.h"

void	gimme_map(int fd, t_file *data_file)
{
  int	i;
  int	last_size;
  char	*tmp;

  i = 0;
  data_file->map = malloc((data_file->nbr_lines + 1)* sizeof(int *)); // pas de cast a lorigine
  if (data_file->map == NULL)
    exit (-1);
  while ((tmp = get_next_line(fd)) != NULL)
    {
      if (i && last_size != ft_strlen(tmp))
	{
    ft_putstr("ERROR MAP: WRONG SIZE LINE.\n");
	  exit(0);
	}
      last_size = ft_strlen(tmp);
      data_file->map[i] = malloc(ft_strlen(tmp) * sizeof(int)); // ici no plus
      if (data_file->map[i] == NULL)
	exit(0);
      transform_in_int(tmp, data_file->map[i++], &data_file->size_line);
      free(tmp);
    }
  data_file->map[i] = NULL;
}

void	gimme_win(t_win *win)
{
  if (!(win->mlx_ptr = mlx_init()))
    {
      ft_putstr("ERROR MLX: MLX_INIT FAIL.\n");
      exit (1);
    }
  win->win_ptr = mlx_new_window(win->mlx_ptr,
				WIN_SIZE_X,
				WIN_SIZE_Y,
				WIN_NAME);
  if (win->win_ptr == NULL)
    {
      ft_putstr("ERROR MLX: NO NEW_WINDOW");
      exit (-1);
    }
}

void	gimme_img(t_win *win, t_img *img)
{
  img->img_ptr = mlx_new_image(win->mlx_ptr, IMG_SIZE_X, IMG_SIZE_Y);
  if (img->img_ptr == NULL)
    {
      ft_putstr("ERROR MLX: NO NEW IMAGE.\n");
      exit(-1);
    }
  img->data = mlx_get_data_addr(img->img_ptr,
				&(img->bpp),
				&(img->size_line),
				&(img->endian));
  printf("bpp gimme img = %d\n", img->bpp); // ATTENTION
  if (img->data == NULL)
    exit(-1);
}

int	gimme_nbr_lines(char *file)
{
  int	fd;
  int	nbr_lines;

  nbr_lines = 0;
  if ((fd = open(file, O_RDONLY)) == -1)
    {
      ft_putstr("ERROR MAP test.\n");
      exit(0);
    }
  while (get_next_line(fd))
    nbr_lines++;
  close(fd);
  return (nbr_lines);
}

void	gimme_color(t_env *env, double x, double y, double angle)
{
  int	case_x;
  int	case_y;

  case_x = CASE_SIZE_X(env->file->size_line);
  case_y = CASE_SIZE_Y(env->file->nbr_lines);
  if ((int)env->draw->x / case_x > (int)x / case_x)
    color_one(env);
  else if ((int)env->draw->x / case_x < (int)x / case_x)
    color_two(env);
  else if ((int)env->draw->y / case_y > (int)y / case_y)
    color_three(env);
  else if ((int)env->draw->y / case_y < (int)y / case_y)
    color_four(env);
  else
    {
      gimme_color(env,
		  x - cos(RADIAN(angle)) * env->perso->precision * 0.1,
		  y + sin(RADIAN(angle)) * env->perso->precision * 0.1,
		  angle);
    }
}
