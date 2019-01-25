/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrynish <vgrynish@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:46:56 by vgrynish          #+#    #+#             */
/*   Updated: 2018/11/15 19:13:35 by arudyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		min_square(int n)
{
	int i;
	int j;

	i = 2;
	j = n * 4;
	while (i * i < j)
		i++;
	return (i);
}

char	**new_map(int min)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = (char **)malloc(sizeof(char *) * min + 1);
	while (i < min)
	{
		map[i] = (char *)malloc(sizeof(char) * min + 1);
		j = 0;
		while (j < min)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	ft_delete_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	print_map(char **map, int n)
{
	int i;

	i = 0;
	while (map[i])
	{
		write(1, map[i], n);
		write(1, "\n", 1);
		i++;
	}
}

char	liter(char *tetri)
{
	int i;

	i = 0;
	while (tetri[i] == '.')
		i++;
	return (tetri[i]);
}
