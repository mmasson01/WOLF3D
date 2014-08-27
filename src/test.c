#include <mlx.h>

int main()
{
  void *mlx;
  void *win;

  mlx = mlx_init();
  win = mlx_new_window(mlx, 400, 400, "test");
  sleep(30);
  return (0);
}
