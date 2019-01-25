/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_gr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrynish <vgrynish@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:27:06 by vgrynish          #+#    #+#             */
/*   Updated: 2018/11/15 15:27:07 by vgrynish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_solve(char **tetri, int n)
{
	char	**map;
	int		min;

	min = min_square(n);
	map = new_map(min);
	while (main_solve(map, tetri, 0, 0) == 0)
	{
		min++;
		ft_delete_map(map);
		map = new_map(min);
	}
	print_map(map, min);
	ft_delete_map(map);
	ft_delete_map(tetri);
}

int		can_put(char **mas, char *tetri, int x, int y)
{
	int y2;
	int i;

	y2 = y;
	i = 0;
	while (*tetri == '.')
		plus2(&tetri, &i, &y2);
	if (y2 < 0)
		return (0);
	while (*tetri)
	{
		if (i > 3)
			plus3(&i, &x, &y, y2);
		else if (*tetri == '.')
			plus(&(tetri), &i, &y);
		else if (mas[x] && *tetri != '.' && mas[x][y] == '.')
			plus(&(tetri), &i, &y);
		else
			return (0);
	}
	return (1);
}

void	put(char **mas, char *tetri, int x, int y)
{
	int y2;
	int i;

	y2 = y;
	i = 0;
	while (*tetri == '.')
		plus2(&tetri, &i, &y2);
	while (*tetri)
	{
		if (i > 3)
		{
			i = 0;
			x++;
			y = y2;
		}
		else if (*tetri == '.')
			plus(&(tetri), &i, &y);
		else if (*tetri != '.' && mas[x][y] == '.')
		{
			mas[x][y] = *tetri;
			plus(&(tetri), &i, &y);
		}
	}
}

void	ft_remove(char **map, char *tetri)
{
	char	c;
	int		i;
	int		j;
	int		n;

	i = 0;
	n = 0;
	c = liter(tetri);
	while (map[i])
	{
		j = 0;
		if (n == 4)
			break ;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				n++;
				map[i][j] = '.';
			}
			j++;
		}
		i++;
	}
}

int		main_solve(char **map, char **tetri, int x, int y)
{
	if (*tetri == NULL)
		return (1);
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (can_put(map, *tetri, x, y) == 1)
			{
				put(map, *tetri, x, y);
				if (main_solve(map, tetri + 1, 0, 0) == 1)
					return (1);
				else
					ft_remove(map, *tetri);
			}
			y++;
		}
		x++;
	}
	return (0);
}
