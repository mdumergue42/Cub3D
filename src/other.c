
void	f_c_color(void *mlx, void *win, t_pars *pars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;

	while (y <= (400 / 2)) //changer 400 par le define
	{
		x = 0;
		while (x <= 800) //changer 800 par le define
		{
			mlx_pixel_put(mlx, win, x, y, pars->c_color);
			mlx_pixel_put(mlx, win, x, 400 - y, pars->f_color); // changer 400 par le define
			x++;
		}
		y++;
	}
}
