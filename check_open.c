/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrynish <vgrynish@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:19:02 by vgrynish          #+#    #+#             */
/*   Updated: 2018/11/14 18:19:04 by vgrynish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		read_fd(int fd, char **tmp)
{
	int ret;
	int i;

	i = 0;
	ret = read(fd, *tmp, 546);
	if (ret == 546)
		return (-1);
	else
	{
		(*tmp)[ret] = '\0';
		if (valid_tmp_easy(*tmp, ret) == -1)
		{
			return (-1);
		}
		change_tmp(&(*tmp));
		return ((ret + 1) / 21);
	}
}

int		valid(char *c)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (i <= 19)
	{
		if (i % 5 == 4)
		{
			if (c[i] != '\n')
				return (0);
			i++;
		}
		else if (c[i] == '.' || c[i] == '#')
		{
			if (c[i] == '#')
				n++;
			i++;
		}
		else
			return (0);
	}
	if (n != 4)
		return (0);
	return (1);
}

int		valid_sec(char *c)
{
	int sosed;
	int i;

	i = 0;
	sosed = 0;
	while (i <= 19)
	{
		if (c[i] == '#')
		{
			if (i - 1 >= 0 && c[i - 1] == '#')
				sosed++;
			if (i + 1 <= 19 && c[i + 1] == '#')
				sosed++;
			if (i - 5 >= 0 && c[i - 5] == '#')
				sosed++;
			if (i + 5 <= 19 && c[i + 5] == '#')
				sosed++;
		}
		i++;
	}
	if (sosed == 6 || sosed == 8)
		return (1);
	return (0);
}

int		valid_tmp_easy(char *tmp, int ret)
{
	int n;

	n = 0;
	while (n < ret)
	{
		if (valid(&tmp[n]) == 0)
		{
			return (-1);
		}
		if (valid_sec(&tmp[n]) == 0)
		{
			return (-1);
		}
		if (tmp[n + 20] == '\n')
			n = n + 21;
		else if (tmp[n + 20] == '\0' && n + 20 == ret)
			return (1);
		else
		{
			return (-1);
		}
	}
	return (-1);
}

void	change_tmp(char **tmp)
{
	int i;

	i = 20;
	while ((*tmp)[i])
	{
		(*tmp)[i] = 'd';
		i = i + 21;
	}
}
