/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_mv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:42:44 by hchairi           #+#    #+#             */
/*   Updated: 2023/03/19 20:01:58 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_enmy(t_data *slg, int j, int i, int t)
{
	mlx_put_image_to_window(slg->mlx, slg->win, slg->enemy,
		slg->en->x * W, slg->en->y * W);
	if (t)
		mlx_put_image_to_window(slg->mlx, slg->win, slg->road,
			(slg->en->x + j) * W, (slg->en->y + i) * W);
}

int	enemy_mv_y(t_data *slg, char **tab, t_pos *en, int i)
{
	int	t;

	t = 1;
	if (tab[en->y + i][en->x] == '1' || tab[en->y + i][en->x] == 'E'
		|| tab[en->y + i][en->x] == 'C')
		t = 0;
	if (tab[en->y + i][en->x] == 'P')
		ft_exit(slg);
	if (tab[en->y + i][en->x] != '1' && tab[en->y + i][en->x] != 'E'
		&& tab[en->y + i][en->x] != 'C')
	{
		tab[en->y][en->x] = '0';
		en->y = en->y + i;
		tab[en->y][en->x] = 'N';
	}
	return (t);
}

int	enemy_mv_x(t_data *slg, char **tab, t_pos *en, int i)
{
	int	t;

	t = 1;
	if (tab[en->y][en->x + i] == '1' || tab[en->y][en->x + i] == 'E'
		|| tab[en->y][en->x + i] == 'C')
		t = 0;
	if (tab[en->y][en->x + i] == 'P')
		ft_exit(slg);
	if (tab[en->y][en->x + i] != '1' && tab[en->y][en->x + i] != 'E'
		&& tab[en->y][en->x + i] != 'C')
	{
		tab[en->y][en->x] = '0';
		en->x = en->x + i;
		tab[en->y][en->x] = 'N';
	}
	return (t);
}

int	animation(t_data *slg)
{
	static int	an;

	an++;
	if (an == 1000)
	{	
		mlx_put_image_to_window(slg->mlx, slg->win, slg->d1,
			slg->p_e->x * W, slg->p_e->y * W);
		if (slg->ply->x == slg->p_e->x && slg->ply->y == slg->p_e->y)
			mlx_put_image_to_window(slg->mlx, slg->win, slg->player[slg->vue],
				slg->ply->x * W, slg->ply->y * W);
	}
	else if (an == 5000)
	{
		mlx_put_image_to_window(slg->mlx, slg->win, slg->d2,
			slg->p_e->x * W, slg->p_e->y * W);
		if (slg->ply->x == slg->p_e->x && slg->ply->y == slg->p_e->y)
			mlx_put_image_to_window(slg->mlx, slg->win, slg->player[slg->vue],
				slg->ply->x * W, slg->ply->y * W);
	}
	else if (an > 5000)
		an = 0;
	return (0);
}

int	enemy_mv(t_data *slg)
{
	static int	enn;

	srand(time(0));
	enn++;
	if (enn == 1000)
	{
		if (rand() % 4 == 0)
			print_enmy(slg, 0, 1, enemy_mv_y(slg, slg->map, slg->en, -1));
		else if (rand() % 4 == 1)
			print_enmy(slg, 0, -1, enemy_mv_y(slg, slg->map, slg->en, 1));
		else if (rand() % 4 == 2)
			print_enmy(slg, -1, 0, enemy_mv_x(slg, slg->map, slg->en, 1));
		else if (rand() % 4 == 3)
			print_enmy(slg, 1, 0, enemy_mv_x(slg, slg->map, slg->en, -1));
		enn = 0;
	}
	animation(slg);
	return (0);
}
