/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasson <mmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 09:32:38 by mmasson           #+#    #+#             */
/*   Updated: 2014/01/16 10:27:02 by mmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	color_one(t_env *env)
{
  env->draw->blue = 140;
  env->draw->red = 102;
  env->draw->green = 46;
}

void	color_two(t_env *env)
{
  env->draw->blue = 140;
  env->draw->red = 23;
  env->draw->green = 82;
}

void	color_three(t_env *env)
{
  env->draw->blue = 140;
  env->draw->red = 112;
  env->draw->green = 135;
}

void	color_four(t_env *env)
{
  env->draw->blue = 129;
  env->draw->red = 51;
  env->draw->green = 140;
}