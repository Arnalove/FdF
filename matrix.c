/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:01:01 by achansar          #+#    #+#             */
/*   Updated: 2022/11/28 12:20:33 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static t_dot	**free_matrix(t_dot **matrix, int i)
{
	while(i)
	{
		free(matrix[i]);
		i--;
	}
	free(matrix);
	matrix = NULL;
	return (matrix);
}

static char	*buffer_map(char *buff)
{
	int     i;
	int		fd;
	char    *line;

	fd = open("test_maps/42.fdf", O_RDONLY);
	i = 0;
	while (i + 1 < 12)
	{
		line = get_next_line(fd);
		buff = ft_strjoin_gnl(buff, line);
		free(line);
		i++;
	}
	close(fd);
	return (buff);
}

static t_dot	**create_matrix(int h, int w, char **tab)
{
	int		i;
	int		j;
	char	**line;
	t_dot	**matrix;
	
	matrix = malloc(sizeof(t_dot *) * h);
	if (!matrix)
		return (matrix);
	i = 0;
	while (i < h)
	{
		j = 0;
		matrix[i] = malloc(sizeof(t_dot) * w);
		if (!matrix[i])
			return(free_matrix(matrix, i));
		line = ft_split(tab[i], ' ');
		while (j < w)
		{
			matrix[i][j].x = j;
			matrix[i][j].y = i;
			matrix[i][j].z = ft_atoi(line[j]);
			//printf("x = %d | y = %d\n", matrix[i][j].x, matrix[i][j].y);
			free(line[j]);
			j++;
		}
		i++;
	}
	free(line);
	return (matrix);
}

t_dot **get_matrix(t_dot **mtx, int h, int w)
{
	char	*buff;
	char	**map;

	buff = malloc(sizeof(char) * 1);
	if (!buff)
		return (0);
	buff[0] = '\0';
	buff = buffer_map(buff);
	map = ft_split(buff, '\n');
	free(buff);
    mtx = create_matrix(h, w, map);
	//printf("x = %d | y = %d\n", mtx[5][5].x, mtx[5][5].y);
	return (mtx);
}