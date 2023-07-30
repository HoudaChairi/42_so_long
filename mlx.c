/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:40:46 by hchairi           #+#    #+#             */
/*   Updated: 2023/03/19 11:31:39 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	s_start(t_data *slg)
{
	slg->road = mlx_xpm_file_to_image(slg->mlx, "textures/new.xpm",
			&slg->i_w, &slg->i_h);
	slg->floor = mlx_xpm_file_to_image(slg->mlx, "textures/terre.xpm",
			&slg->i_w, &slg->i_h);
	slg->player[0] = mlx_xpm_file_to_image(slg->mlx, "textures/jerry0.xpm",
			&slg->i_w, &slg->i_h);
	slg->player[1] = mlx_xpm_file_to_image(slg->mlx, "textures/jerryx1.xpm",
			&slg->i_w, &slg->i_h);
	slg->player[2] = mlx_xpm_file_to_image(slg->mlx, "textures/jerryx2.xpm",
			&slg->i_w, &slg->i_h);
	slg->player[3] = mlx_xpm_file_to_image(slg->mlx, "textures/jerry3.xpm",
			&slg->i_w, &slg->i_h);
	slg->coll = mlx_xpm_file_to_image(slg->mlx, "textures/cheese.xpm",
			&slg->i_w, &slg->i_h);
	slg->d2 = mlx_xpm_file_to_image(slg->mlx, "textures/d2.xpm",
			&slg->i_w, &slg->i_h);
	slg->d1 = mlx_xpm_file_to_image(slg->mlx, "textures/d1.xpm",
			&slg->i_w, &slg->i_h);
	slg->enemy = mlx_xpm_file_to_image(slg->mlx, "textures/enemy.xpm",
			&slg->i_w, &slg->i_h);
	if (!slg->road || !slg->floor || !slg->player[0] || !slg->player[1]
		|| !slg->player[2] || !slg->player[3] || !slg->coll || !slg->d1
		|| !slg->d2 || !slg->enemy)
		ft_exit_err(slg);
}

void	check_img(t_data *slg, int i, int j)
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
	else if (slg->map[i][j] == 'E')
	{		
		if (slg->ct_c == slg->coin)
			mlx_put_image_to_window(slg->mlx, slg->win, slg->d1,
				j * W, i * W);
		else
			mlx_put_image_to_window(slg->mlx, slg->win, slg->d2,
				j * W, i * W);
	}
}

void	images_to_map(t_data *slg)
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
			check_img(slg, i, j);
		}
	}
}

void	start(t_data *slg)
{
	slg->vue = 0;
	slg->mlx = mlx_init();
	slg->win = mlx_new_window(slg->mlx, ft_strlen(slg->map[0]) * W,
			slg->ct_line * W, "so_long");
	s_start(slg);
	images_to_map(slg);
	mlx_hook(slg->win, 2, 0, moves, slg);
	mlx_hook(slg->win, 17, 0, ft_exit, slg);
}
