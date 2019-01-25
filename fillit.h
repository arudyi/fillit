/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrynish <vgrynish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 11:13:04 by vgrynish          #+#    #+#             */
/*   Updated: 2018/11/18 13:03:24 by arudyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

int		fillit(int fd);
int		read_fd(int fd, char **tmp);
int		valid_tmp_easy(char *tmp, int ret);
int		valid_sec(char *c);
int		valid(char *c);
void	change_tmp(char **tmp);
char	**ft_strsplit(char const *s, char c);
void	robota_n(char ***mas);
void	gopush(char v[19][20]);
int		go_left(char ***mas);
void	ft_rename(char ***mas);
char	*ft_strcpy(char *dst, const char *src);
void	ft_solve(char **tetri, int n);
int		min_square(int n);
char	**new_map(int min);
void	ft_delete_map(char **map);
void	print_map(char **map, int n);
char	liter(char *tetri);
int		main_solve(char **map, char **tetri, int x, int y);
void	ft_remove(char **map, char *tetri);
void	put(char **mas, char *tetri, int x, int y);
int		can_put(char **mas, char *tetri, int x, int y);
void	plus(char **tetri, int *c, int *y);
void	plus2(char **tetri, int *c, int *y);
void	plus3(int *k, int *c, int *y, int y2);

#endif
