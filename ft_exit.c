/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:18:11 by hchairi           #+#    #+#             */
/*   Updated: 2023/03/20 12:28:55 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_img(t_data *slg)
{
	mlx_destroy_image(slg->mlx, slg->floor);
	mlx_destroy_image(slg->mlx, slg->road);
	mlx_destroy_image(slg->mlx, slg->player[0]);
	mlx_destroy_image(slg->mlx, slg->player[1]);
	mlx_destroy_image(slg->mlx, slg->player[2]);
	mlx_destroy_image(slg->mlx, slg->player[3]);
	mlx_destroy_image(slg->mlx, slg->coll);
	mlx_destroy_image(slg->mlx, slg->d2);
	mlx_destroy_image(slg->mlx, slg->d1);
	mlx_destroy_image(slg->mlx, slg->enemy);
}

void	ft_exit_err(t_data *slg)
{
	int	i;

	i = 0;
	if (slg->map != NULL)
	{
		while (slg->map[i])
			free(slg->map[i++]);
		free(slg->map);
	}
	i = 0;
	if (slg->cpy != NULL)
	{
		while (slg->cpy[i])
			free(slg->cpy[i++]);
		free(slg->cpy);
	}
	free(slg->s);
	free(slg->str);
	exit(1);
}

int	ft_exit(t_data *slg)
{
	int	i;

	i = 0;
	destroy_img(slg);
	if (slg->cpy != NULL)
	{
		while (slg->cpy[i])
			free(slg->cpy[i++]);
		free(slg->cpy);
	}
	i = 0;
	if (slg->map != NULL)
	{
		while (slg->map[i])
			free(slg->map[i++]);
		free(slg->map);
	}
	free(slg->s);
	free(slg->str);
	exit(0);
	return (0);
}
