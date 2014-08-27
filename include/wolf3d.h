/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasson <mmasson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 09:32:38 by mmasson           #+#    #+#             */
/*   Updated: 2014/01/17 15:19:07 by mmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

#include <stdarg.h>

# define  couleur(param) ft_printf("\033[%sm",param)

/*
** Maccros Win
*/
# define WIN_SIZE_X 600
# define WIN_SIZE_Y 650
# define WIN_NAME "Wolf3d by mmasson"

/*
** Maccros Img
*/
# define IMG_SIZE_X	600
# define IMG_SIZE_Y	600
# define IMG_POS_X	0
# define IMG_POS_Y	0

/*
** Maccros Keys
*/
# define ESC		65307
# define LEFT		65361
# define RIGHT		65363
# define UP			65362
# define DOWN		65364

/*
** Maccros déplacement
*/
# define CASE_SIZE_X(x)	IMG_SIZE_X / (x)
# define CASE_SIZE_Y(x)	IMG_SIZE_Y / (x)

/*
** Maccros angle
*/
# define ANGLE_MIN(x)	(x) - 30
# define ANGLE_MAX(x)	(x) + 30
# define RADIAN(x)	(x) * 3.14 / 180

# define BUFF_SIZE 10

typedef struct	s_perso
{
  float		x;
  float		y;
  float		precision;
  int		angle;
  int		speed;
}		t_perso;

typedef struct	s_win
{
  void		*win_ptr;
  void		*mlx_ptr;
}		t_win;

typedef struct	s_img
{
  void		*img_ptr;
  int		bpp;
  int		size_line;
  int		endian;
  char		*data;
  int		x;
  int		y;
}		t_img;

typedef struct	s_file
{
  int		nbr_lines;
  int		size_line;
  int		**map;
}		t_file;

typedef struct	s_draw
{
  float		x;
  float		y;
  int		blue;
  int		green;
  int		red;
}		t_draw;

typedef struct	s_env
{
  t_file		*file;
  t_win			*win;
  t_img			*img;
  t_img			*background;
  t_img			*floor;
  t_img			*gun;
  t_draw		*draw;
  t_perso		*perso;
}				t_env;

/*
** ft_tools.c
*/
int   ft_getnbr(char *);
void  ft_putchar(char);
void  ft_putnbr(int);
void  ft_putstr(char *src);
int ft_strcmp(char *, char *);
int ft_strlen(char *);
char  *ft_strcat(char *, char*);

char  *gimme_good_line(char *file_buffer);
int check_buffer(char *file_buffer);
char  *get_next_line(const int fd);

/*
** ft_color.c
*/
void  color_one(t_env *);
void  color_two(t_env *);
void  color_three(t_env *);
void  color_four(t_env *);

/*
** ft_copy.c
*/
void  cpy_img(t_env *);
void  cpy_floor(t_env *);
void  cpy_gun(t_env *);

/*
** ft_draw.c
*/
void  put_wall(t_env *, double);
void  lets_draw(t_env *);
void  find_intersection(t_env *, int, int, float);
void  search_walls(t_env *);

/*
** ft_get_param.c
*/
void  gimme_map(int, t_file *);
void  gimme_win(t_win *);
void  gimme_img(t_win *, t_img *);
int gimme_nbr_lines(char *);
void  gimme_color(t_env *, double, double, double);

/*
** ft_get_pattern.c
*/
void  gimme_gun(t_env *);
void  gimme_sky(t_env *);
void  gimme_floor(t_env *);

/*
** ft_hook.c
*/
int check_expose_hook(t_env *);
int check_key_hook(int , t_env *);
void  free_all(t_env *);
void  check_actions(t_env *, int);

/*
** ft_init.c
*/
t_env *init_struct(t_env *);
void  transform_in_int(char *, int *, int *);
void  gimme_env(t_file *, char *);
void  init_perso(t_perso *, t_file *);
void  check_map(t_file *);

/*
** ft_keys.c
*/
void  right(t_env *); // a verifier
void  left(t_env *);
void  up(t_env *);
void  down(t_env *);

/*
** ft_pixel_put_to_image.c
*/
void  ft_pixel_put_to_image(t_img *, t_win *, t_draw *);

/*
**  ft_printf.c
*/
int   ft_count(int n);
int   ft_check_cent(const char *format, int i, va_list ap);
int   ft_printf(const char *format, ...);

/*
**  ft_print_format.c
*/
int   ft_format_s(va_list ap, char *p);
int   ft_format_d(va_list ap, int n);
int   ft_format_c(va_list ap);
int   ft_format_cent(void);

/*
** ft_sky.c
*/
void  put_background(t_env *);

/*
** Main.c
*/
void  myheader(char *a, char *b);
void	check_macro();
void 	menu(t_env *env);
void	wolf(char *file);

#endif /* !WOLF3D_H_ */