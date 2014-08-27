/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasson <mmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 09:32:38 by mmasson           #+#    #+#             */
/*   Updated: 2014/01/17 15:20:46 by mmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
  write(1, &c, 1);
}

void	ft_putstr(char *str)
{
    int i;

    i = 0;
    if (str == NULL)
      return ;
    while (str[i])
    {
      ft_putchar(str[i]);
      i++;
    }
}

void  ft_putnbr(int nbr)
{
  if (nbr > 9)
  {
    ft_putnbr(nbr / 10);
    ft_putnbr(nbr % 10);
  }
  else if (nbr < 0)
  {
    ft_putchar('-');
    nbr *= -1;
    ft_putnbr(nbr);
  }
  else
  {
    ft_putchar(48 + nbr);
  }
}

int	obtain_nbr(char *str, int nbr)
{
  if (!(*str >= '0' && *str <= '9'))
    return (nbr);
  nbr = nbr * 10 + (*str - '0');
  return (obtain_nbr(str + 1, nbr));
}

int	ft_getnbr(char *str)
{
  int	nbr_sign;

  nbr_sign = 1;
  while (*str == '-' || *str == '+')
    {
      if (*str == '-')
	nbr_sign *= -1;
      str = str + 1;
    }
  return (obtain_nbr(str, 0) * nbr_sign);
}

int	ft_strlen(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    while (str[i])
      i++;
  return (i);
}

char	*ft_strcat(char *str1, char *str2)
{
  int	i;
  int	j;
  char	*new_str;

  i = 0;
  j = 0;
  new_str = (char*)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
  if (new_str == NULL)
    return (NULL);
  while (str1[i])
    {
      new_str[i] = str1[i];
      i++;
    }
  while (str2[j])
    new_str[i++] = str2[j++];
  new_str[i] = '\0';
  return (new_str);
}

int	ft_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i])
    {
      if (s1[i] < s2[i])
	return (s1[i] - s2[i]);
      else if (s1[i] > s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  if (!(s1[i]) && !(s2[i]))
    return (0);
  else if (s1[i])
    return (s1[i]);
  else
    return (s2[i] * (-1));
}

char		*gimme_good_line(char *file_buffer)
{
  static int	i;
  int		j;
  char		*line_to_return;

  j = 0;
  line_to_return = (char*)malloc(ft_strlen(file_buffer) + 1);
  if (line_to_return == NULL)
    return (NULL);
  if (i >= ft_strlen(file_buffer))
    return (NULL);
  while (file_buffer[i] != '\n' && file_buffer[i])
    line_to_return[j++] = file_buffer[i++];
  i = i + 1;
  line_to_return[j] = '\0';
  return (line_to_return);
}

int		check_buffer(char *file_buffer)
{
  static int	i;

  while (file_buffer[i])
    if (file_buffer[i] == '\n' || !file_buffer[i++])
      {
	i = i + 1;
	return (1);
      }
  return (0);
}

char		*get_next_line(const int fd)
{
  static char	*file_buffer;
  char		*buffer;
  int		ret;

  if (BUFF_SIZE < 0 || fd < 0)
    return (NULL);
  if (!file_buffer)
    file_buffer = (char*)malloc(1);
  buffer = (char*)malloc(BUFF_SIZE + 1);
  if (buffer == NULL || file_buffer == NULL)
    return (NULL);
  while (!check_buffer(file_buffer) && (ret = read(fd, buffer, BUFF_SIZE)))
    {
      if (ret == -1)
	return (NULL);
      buffer[ret] = '\0';
      file_buffer = ft_strcat(file_buffer, buffer);
      if (file_buffer == NULL)
	return (NULL);
    }
  free(buffer);
  return (gimme_good_line(file_buffer));
}