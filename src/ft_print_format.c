/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasson <mmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 15:08:44 by mmasson           #+#    #+#             */
/*   Updated: 2014/01/17 15:13:00 by mmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int	ft_format_s(va_list ap, char *p)
{
	int	len;

	len = 0;
	p = va_arg(ap, char*);
	if (p == NULL)
		ft_putstr("(null)");
	ft_putstr(p);
	len = ft_strlen(p);
	return (len);
}

int	ft_format_d(va_list ap, int n)
{
	int	len;

	len = 0;
	n = va_arg(ap, int);
	ft_putnbr(n);
	len = ft_count(n);
	return (len);
}

int	ft_format_c(va_list ap)
{
	int	len;

	len = 0;
	ft_putchar(va_arg(ap, int));
	len++;
	return (len);
}

int	ft_format_cent(void)
{
	int	len;

	len = 0;
	ft_putchar('%');
	len++;
	return (len);
}