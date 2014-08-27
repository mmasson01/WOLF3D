/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasson <mmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 09:32:38 by mmasson           #+#    #+#             */
/*   Updated: 2014/01/18 12:55:05 by mmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "wolf3d.h"

void	init_perso(t_perso *perso, t_file *file)
{
  int	i;
  int	j;

  i = 0;
  while (i < file->nbr_lines)
    {
      j = 0;
      while (j < file->size_line)
	       if (!file->map[i][j])
	         {
	           perso->x = (j + 0.25) * CASE_SIZE_X(file->size_line);
	           perso->y = (i + 0.25) * CASE_SIZE_Y(file->nbr_lines);
	           perso->angle = 0;
	           return ;
	         }
	       else
	         j++;
      i++;
    }
  ft_putstr("ERROR MAP ici. \n");
  exit (0);
}

t_env	  *init_struct(t_env *env)
{
  env = malloc(sizeof(*env));
  env->file = malloc(sizeof(*(env->file)));
  env->win = malloc(sizeof(*(env->win)));
  env->img = malloc(sizeof(*(env->img)));
  env->perso = malloc(sizeof(*(env->perso)));
  env->draw = malloc(sizeof(*(env->draw)));
  if (env == NULL
      || env->file == NULL
      || env->win == NULL
      || env->img == NULL
      || env->perso == NULL
      || env->draw == NULL)
    {
      ft_putstr("INIT_STRUCT ERROR: MALLOC FAIL. \n");
      exit(0);
    }
  env->perso->precision = 0.01; //test
  env->perso->speed = 15;
  return (env);
}

void	transform_in_int(char *tmp, int *line_map, int *size_line)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (tmp[i])
    {
      while (tmp[i] == ' ' || tmp[i] == '\t')
	i++;
      if (tmp[i] && (tmp[i] == '0' || tmp[i] == '1'))
	line_map[j++] = ft_getnbr(&tmp[i]);
      else if (tmp[i] && tmp[i] != '0' && tmp[i] != '1')
	{
    ft_putstr("MAP ERROR.\n");
	  exit(0);
	}
      while (tmp[i] && tmp[i] != ' ' && tmp[i] != '\t')
	i++;
    }
  *size_line = j;
}

void	check_map(t_file *data_file)
{
  int	i;
  int	j;

  i = 0;
  while (i < data_file->nbr_lines)
    {
      j = 0;
      while (j < data_file->size_line)
	{
	  if (((!i || i == data_file->nbr_lines - 1) && !data_file->map[i][j])
	      || ((!j || j == data_file->size_line - 1) && !data_file->map[i][j]))
	{
    ft_putstr("NO WALLS IN MAP.\n");
	  exit(0);
	}
	  j++;
	}
      i++;
    }
}

void	gimme_env(t_file *data_file, char *file)
{
  int	fd;

  if ((fd = open(file, O_RDONLY)) == -1)
    {
      ft_putstr("OPEN MAP FAIL test.\n");
      exit(0);
    }
  data_file->nbr_lines = gimme_nbr_lines(file);
  gimme_map(fd, data_file);
  check_map(data_file);
  close(fd);
}
