/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:30:45 by achansar          #+#    #+#             */
/*   Updated: 2022/11/30 15:58:35 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <stdio.h>
// . !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define WHITE 0xFFFFFF
# define pi 3.142857

# define WIDTH 1920
# define HEIGHT 1080

# define ESC 53

typedef struct s_dot {

    int     x;
    int     y;
    int     z;
}   t_dot;

typedef struct s_matrix {

    t_dot   **mtx;
    int     w;
    int     h;
}   t_matrix;

typedef struct s_img {
    
    void    *img;
    char    *addr;
    int     bpp;
    int     szline;
    int     endian;
}   t_img;

typedef struct s_data {

    void    *mlx;
    void    *win;
    t_img   img;
}   t_data;

int     destroy(int key, t_data *set);
t_dot   **get_matrix(t_dot **mtx, char *file_path, int h, int w);
int     get_dimensions(t_matrix *matrix, char *file_path);
int     scale(t_matrix *ele);
int     open_window(t_data *set);
int     isometric(t_matrix  *matrix);
int     drawline_all(t_img *img, t_dot **mtx, int w, int h);

/*----LIBFT------*/
int     ft_atoi(const char *str);
char	*get_next_line(int fd);
char	*ft_strdup_gnl(char *s1);
int		ft_strlen(char *s);
int		ft_isin(char *str, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	*ft_free_all(char *s1, char **s2);
int     ft_isdigit(int c);

char	**ft_split(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif