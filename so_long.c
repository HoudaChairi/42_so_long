/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:33:55 by hchairi           #+#    #+#             */
/*   Updated: 2023/03/20 12:23:26 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**seule_chaine(t_data *slg, char *av)
{	
	int			fd;
	char		*line;
	int			len;

	slg->ct_line = 0;
	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	len = ft_strlen(line);
	slg->s = NULL;
	while (line != NULL)
	{	
		if ((line[ft_strlen(line) - 1] == '\n'
				&& ft_strlen(line) != len) // Qst !!!
			|| (line[ft_strlen(line) - 1] != '\n'
				&& ft_strlen(line) != len - 1))
			len = 2;
		slg->s = ft_strjoin(slg->s, line);
		free(line);
		line = get_next_line(fd);
		slg->ct_line++;
	}
	if (len < 3 || slg->ct_line < 3)
		checkmap(slg, NULL);
	slg->cpy = ft_split(slg->s, '\n');
	return (ft_split(slg->s, '\n'));
}

int	check_file(char *s, t_data *slg)
{
	int	len;

	len = ft_strlen(s);
	len--;
	if (s[len] == 'r' && s[len - 1] == 'e'
		&& s[len - 2] == 'b' && s[len - 3] == '.')
		return (1);
	write(1, "Error\ninvalide map", 19);
	ft_exit_err(slg);
	return (0);
}

void	init(t_data *slg)
{
	slg->map = NULL;
	slg->cpy = NULL;
	slg->coin = 0;
	slg->move = 0;
}

int	main(int argc, char **argv)
{
	t_data	slg;
	t_pos	ply;
	t_pos	p_e;

	init(&slg);
	slg.ply = &ply;
	slg.p_e = &p_e;
	if (argc != 2 || !check_file(argv[1], &slg))
		return (1);
	slg.map = seule_chaine(&slg, argv[1]);
	checkmap(&slg, slg.map);
	checkpath(&slg, ply.y, ply.x);
	path(&slg);
	start(&slg);
	mlx_loop(slg.mlx);
	return (0);
}
