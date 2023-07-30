/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:40:19 by hchairi           #+#    #+#             */
/*   Updated: 2023/03/18 21:46:07 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_img_b(t_data *slg, int i, int j)
{
	if (slg->map[i][j] == '1')
		mlx_put_image_to_window(slg->mlx, slg->win, slg->floor,
			j * W, i * W);
	else if (slg->map[i][j] == 'P')
		mlx_put_image_to_window(slg->mlx, slg->win, slg->player[slg->vue],
			j * W, i * W);
	else if (slg->map[i][j] == 'C')
		mlx_put_image_to_window(slg->mlx, slg->win, slg->coll,
			j * W, i * W);
	else if (slg->map[i][j] == 'N')
		mlx_put_image_to_window(slg->mlx, slg->win, slg->enemy,
			j * W, i * W);
}

void	images_to_map_b(t_data *slg)
{
	int		i;
	int		j;

	i = -1;
	while (slg->map[++i])
	{
		j = -1;
		while (slg->map[i][++j])
		{
			mlx_put_image_to_window(slg->mlx, slg->win, slg->road,
				j * W, i * W);
			mlx_put_image_to_window(slg->mlx, slg->win, slg->floor, 0, 0);
			mlx_put_image_to_window(slg->mlx, slg->win, slg->floor, 64, 0);
			mlx_string_put(slg->mlx, slg->win, 20, 20, 8, "move: ");
			mlx_string_put(slg->mlx, slg->win, 70, 20, 8, slg->str);
			check_img_b(slg, i, j);
		}
	}
}

void	start_b(t_data *slg)
{
	slg->vue = 0;
	slg->mlx = mlx_init();
	slg->win = mlx_new_window(slg->mlx, ft_strlen(slg->map[0]) * W,
			slg->ct_line * W, "so_long_bonus");
	s_start(slg);
	images_to_map_b(slg);
	mlx_hook(slg->win, 2, 0, c_moves_b, slg);
	mlx_loop_hook(slg->mlx, enemy_mv, slg);
	mlx_hook(slg->win, 17, 0, ft_exit, slg);
}
