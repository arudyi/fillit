/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrynish <vgrynish@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:30:59 by vgrynish          #+#    #+#             */
/*   Updated: 2018/11/14 19:31:01 by vgrynish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	ft_rename(char ***mas)
{
	char	i;
	int		j;
	int		k;

	i = 'A';
	j = 0;
	while ((*mas)[j])
	{
		k = 0;
		while ((*mas)[j][k])
		{
			if ((*mas)[j][k] == '#')
				(*mas)[j][k] = i;
			k++;
		}
		i++;
		j++;
	}
}
