/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put_to_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasson <mmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 09:32:38 by mmasson           #+#    #+#             */
/*   Updated: 2014/01/18 12:50:36 by mmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "wolf3d.h"

void	ft_pixel_put_to_image(t_img *img, t_win *win, t_draw *draw)
{
  int	i;
  int	x;
  int	y;

  i = 0;
  x = (int)draw->x * img->bpp / 8;
  y = (int)draw->y * img->size_line;
  img->data[x + i++ + y] = mlx_get_color_value(win->mlx_ptr, draw->blue); //i++
  img->data[x + i++ + y] = mlx_get_color_value(win->mlx_ptr, draw->green);
  img->data[x + i++ + y] = mlx_get_color_value(win->mlx_ptr, draw->red);
}