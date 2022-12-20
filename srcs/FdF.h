/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:30:45 by achansar          #+#    #+#             */
/*   Updated: 2022/12/20 17:09:00 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <stdlib.h>//                       => verifier si les include sont necessaires dans chacun des fichiers (utils)
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>//                        => verifier l'utilite de chaque lib
# include <stdlib.h>
# include <math.h>

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <stdio.h>
// . !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define WHITE 0xFFFFFF
# define RED 0xFF0000

# define WIDTH 1000
# define HEIGHT 1000

enum keys {
    ESC         = 53,
    UP          = 126,
    DOWN        = 125,
    LEFT        = 123,
    RIGHT       = 124,
    ZOOM_IN     = 69,
    ZOOM_OUT    = 78,
    Z_UP        = 92,
    Z_DOWN      = 85,
    MOUSE       = 1
};

typedef struct s_line {

    int x0;
    int y0;
    int x1;
    int y1;
    int ix;
    int iy;
    int i;
    int color;
} t_line;

typedef struct s_dot {

    float   x;
    float   y;
    float   z;
    int     color;
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
    int     szline;//                      => connaitre l'utilite de chacun de ces elements
    int     endian;
}   t_img;

typedef struct s_data {

    void        *mlx;
    void        *win;
    t_img       img;
    t_matrix    matrix;
}   t_data;

t_dot   **get_matrix(t_dot **mtx, char *file_path, int h, int w);
int     get_dimensions(t_matrix *matrix, char *file_path);//                 => Verifier l'utilite de chaque fonction
int     scale(t_matrix *ele);
int     isometric(t_matrix  *matrix);
int     drawline_all(t_data *set, t_img *img, t_matrix *matrix, t_dot **mtx);
int     bresenham(t_img *img, t_line line);
t_line  bresenham_init(int x, int y, int x1, int y1);
void	img_pix_put(t_img *img, int x, int y);
int     ft_keys(int key, t_data *set);
int     destroy(t_data *set);
t_dot **free_matrix(t_dot **matrix, int i);
int ft_error_msg(char *str);
int	free_tab(char **tab);

/*----LIBFT------*/
int     ft_atoi(const char *str);
char	*get_next_line(int fd);
char	*ft_strdup_gnl(char *s1);
int		ft_strlen(char *s);
int		ft_isin(char *str, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	*ft_free_all(char *s1, char **s2);
int     ft_isdigit(int c);
void	ft_bzero(void *s, size_t n);

char	**ft_split(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif