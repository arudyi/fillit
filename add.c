/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrynish <vgrynish@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:28:48 by vgrynish          #+#    #+#             */
/*   Updated: 2018/11/15 19:28:49 by vgrynish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	plus(char **tetri, int *c, int *y)
{
	(*tetri)++;
	(*c)++;
	(*y)++;
}

void	plus2(char **tetri, int *c, int *y)
{
	(*tetri)++;
	(*c)++;
	(*y)--;
}

void	plus3(int *k, int *c, int *y, int y2)
{
	(*k) = 0;
	(*c)++;
	(*y) = y2;
}
