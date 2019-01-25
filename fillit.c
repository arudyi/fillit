/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrynish <vgrynish@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:13:22 by vgrynish          #+#    #+#             */
/*   Updated: 2018/11/15 19:11:33 by arudyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fillit(int fd)
{
	char	*tmp;
	char	**mas;
	int		n;

	tmp = (char *)malloc(sizeof(char) * 546);
	n = read_fd(fd, &tmp);
	if (n == -1)
	{
		write(1, "error\n", 6);
		return (-1);
	}
	mas = ft_strsplit(tmp, 'd');
	free(tmp);
	robota_n(&mas);
	if (go_left(&(mas)) == -1)
		return (-1);
	ft_rename(&(mas));
	ft_solve(mas, n);
	return (1);
}

void	robota_n(char ***mas)
{
	char	c[17];
	int		i;
	int		k;
	int		j;

	i = 0;
	while ((*mas)[i])
	{
		k = 0;
		j = 0;
		while ((*mas)[i][j])
		{
			if ((*mas)[i][j] != '\n')
			{
				c[k] = (*mas)[i][j];
				k++;
			}
			j++;
		}
		c[k] = '\0';
		(*mas)[i] = ft_strcpy((*mas)[i], c);
		i++;
	}
}

void	gopush(char v[19][20])
{
	ft_strcpy(v[0], "####\0");
	ft_strcpy(v[1], "#...#...#...#\0");
	ft_strcpy(v[2], "##..##\0");
	ft_strcpy(v[3], "###..#\0");
	ft_strcpy(v[4], "#...##..#\0");
	ft_strcpy(v[5], ".#..###\0");
	ft_strcpy(v[6], ".#..##...#\0");
	ft_strcpy(v[7], ".#...#..##\0");
	ft_strcpy(v[8], "###...#\0");
	ft_strcpy(v[9], "##..#...#\0");
	ft_strcpy(v[10], "#...###\0");
	ft_strcpy(v[11], "#...#...##\0");
	ft_strcpy(v[12], "..#.###\0");
	ft_strcpy(v[13], "##...#...#\0");
	ft_strcpy(v[14], "###.#\0");
	ft_strcpy(v[15], ".##.##\0");
	ft_strcpy(v[16], "#...##...#\0");
	ft_strcpy(v[17], "##...##\0");
	ft_strcpy(v[18], ".#..##..#\0");
}

int		ft_strvstr(char *c, char *v)
{
	int i;
	int j;

	i = 0;
	while (c[i])
	{
		j = 0;
		if (c[i + j] == v[j])
		{
			while (c[i + j] && v[j] && c[i + j] == v[j])
				j++;
			if (v[j] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

int		go_left(char ***mas)
{
	char	v[19][20];
	int		i;
	int		j;

	gopush(v);
	i = 0;
	while ((*mas)[i])
	{
		j = 0;
		while (j < 19)
		{
			if (ft_strvstr((*mas)[i], v[j]) == 1)
			{
				ft_strcpy((*mas)[i], v[j]);
				break ;
			}
			j++;
		}
		if (j == 19)
			return (-1);
		i++;
	}
	return (1);
}
