/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrynish <vgrynish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:06:01 by vgrynish          #+#    #+#             */
/*   Updated: 2018/11/15 19:15:41 by arudyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int fd;
	int k;

	if (ac != 2)
	{
		write(1, "usage ./fillit filename\n", 24);
		return (0);
	}
	else
	{
		fd = open(av[1], O_RDONLY);
		k = fillit(fd);
		if (k == -1)
			return (1);
	}
	return (0);
}
