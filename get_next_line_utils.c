/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchairi <hchairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:41:14 by hchairi           #+#    #+#             */
/*   Updated: 2023/03/02 10:42:45 by hchairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	checknew(char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i])
		if (s[i] == '\n')
			return (1);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		j;
	int		i;

	if (!s1)
	{	
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	i = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc(sizeof(char) * (i + 1));
	if (!s3)
		return (NULL);
	i = -1;
	while (s1[++i])
		s3[i] = s1[i];
	j = 0;
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free(s1);
	return (s3);
}

char	*ft_line(char *s)
{
	int		i;
	char	*line;

	i = 0;
	if (!s[0])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_rst(char *s)
{
	char	*rst;
	int		i;
	int		j;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\0')
	{
		free (s);
		return (NULL);
	}
	rst = malloc(sizeof(char *) * (ft_strlen(s) - i + 1));
	if (!rst)
		return (NULL);
	i++;
	j = 0;
	while (s[i])
		rst[j++] = s[i++];
	rst[j] = '\0';
	free(s);
	return (rst);
}
