/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:43:46 by hchairi           #+#    #+#             */
/*   Updated: 2023/03/19 18:11:13 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_pla(t_data *slg, int j, int i, int t)
{
	mlx_put_image_to_window(slg->mlx, slg->win, slg->road,
		(slg->ply->x) * W, (slg->ply->y) * W);
	mlx_put_image_to_window(slg->mlx, slg->win, slg->player[slg->vue],
		slg->ply->x * W, slg->ply->y * W);
	if (t)
		mlx_put_image_to_window(slg->mlx, slg->win, slg->road,
			(slg->ply->x + j) * W, (slg->ply->y + i) * W);
}

int	c_moves_b(int keycode, t_data *slg)
{
	if (keycode == 126)
		print_pla(slg, 0, 1, move_y(slg, slg->map, slg->ply, -1));
	else if (keycode == 125)
		print_pla(slg, 0, -1, move_y(slg, slg->map, slg->ply, 1));
	else if (keycode == 124)
		print_pla(slg, -1, 0, move_x(slg, slg->map, slg->ply, 1));
	else if (keycode == 123)
		print_pla(slg, 1, 0, move_x(slg, slg->map, slg->ply, -1));
	else if (keycode == 53)
		ft_exit(slg);
	if (keycode == 126 || keycode == 125 || keycode == 124 || keycode == 123)
	{
		free(slg->str);
		slg->str = ft_itoa(slg->move);
	}
	mlx_put_image_to_window(slg->mlx, slg->win, slg->floor, 0, 0);
	mlx_put_image_to_window(slg->mlx, slg->win, slg->floor, 64, 0);
	mlx_string_put(slg->mlx, slg->win, 20, 20, 8, "move: ");
	mlx_string_put(slg->mlx, slg->win, 70, 20, 8, slg->str);
	return (0);
}
