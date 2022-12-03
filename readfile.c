/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:16:54 by achansar          #+#    #+#             */
/*   Updated: 2022/12/03 10:03:12 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static int get_height(int h, char *file_path)
{
    int fd;
    char *line;
    int i = 0;

    h = 0;
    fd = open(file_path, O_RDONLY);
    line = get_next_line(fd);
    while(line)
   {
        free(line);
        line = get_next_line(fd);
        h += 1;
        i++;
    }
    close(fd);
    free(line);
    //printf("h = %d\n", h);
    return (h);
}

static int get_width(int w, char *file_path)
{
    int fd;
    int i;
    char *line;

    fd = open(file_path, O_RDONLY);
    line = get_next_line(fd);
    i = 0;
    w = 0;
    while (line[i] && line[i] != '\n')//     => transformer cette fctn en checker pour justifier l'ouverture complete
    {
        if (ft_isdigit(line[i]))
            w += 1;
        get_next_line(fd);
        i++;
   }
    free(line);
    close(fd);
    //printf("w = %d\n", w);
    return (w);
}

int get_dimensions(t_matrix *matrix, char *file_path)
{
    matrix->h = get_height(matrix->h, file_path);
    matrix->w = get_width(matrix->w, file_path);
    printf("w = %d | h = %d\n", matrix->w, matrix->h);
    return (0);
}
    