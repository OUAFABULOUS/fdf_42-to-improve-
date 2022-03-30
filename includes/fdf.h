/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:00:26 by omoudni           #+#    #+#             */
/*   Updated: 2022/03/29 20:20:12 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//-----INCLUDES-----------------------------------------------------------

# include <stdlib.h> 
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <stdio.h>
# include <math.h>

//-----MACROS--------------------------------------------------------------

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define SHIFT 10
# define UINT unsigned int 
# define WIN_H 720
# define WIN_W 1280
# define IMG_0_0 200
# define IMG_0_1 5
# define STEP 10
# define ROT_STEP 0.05
# define ZOOM_STEP 0.5
# define X_ANGLE 0 
# define Y_ANGLE 0
# define Z_ANGLE 0

# define WHITE 0xFFFFFF

# define ESC 65307 
# define D 100
# define F 102
# define R 114
# define C 99
# define J 106
# define K 107
# define I 105
# define M 109
# define N 110
# define U 117
# define P 112
# define UP 65362
# define DOWN 65364
# define SPACE 32

//-----DATA STRUCTURES-----------------------------------------------------

typedef struct s_color {
	float	r;
	float	g;
	float	b;
}				t_color;

typedef struct s_proj {
	float		l;
	float		h;
	float		center[2];
	float		tx;
	float		ty;
	float		sx;
	float		sy;
}				t_proj;

typedef struct s_map {
	int				win_h;
	int				win_w;
	float			rx;
	float			ry;
	float			rz;
	float			sx;
	float			sy;
	float			sz;
	float			tx;
	float			ty;
	float			tz;
	float			sm[16];
	float			tm[16];
	float			rm[16];
	float			gm[16];
	float			pm_ba[16];
	float			pm[16];
	int				i;
	int				j;
	int				iso;
	float			**coords;
	float			**t_coords;
	float			**pp_coords;
	float			**p_coords;
	float			**coords_pr_rot;
	float			min;
	float			max;
	t_proj			*proj;
}				t_map;

typedef struct s_mlx {
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				l_length;
	int				end;
}				t_mlx;

typedef struct s_data {
	t_map			*map;
	t_mlx			*mlx;
	unsigned int	*i_add;
}				t_data;

typedef struct s_line {
	float		p1[4];
	float		p2[4];
	int			size;
	float		**fcoords;
	int			**icoords;
	UINT		*cols;
}				t_line;

//-----SRC FILES - PARSING---------------------------------------------------

//open_store:
char			*ft_open_store(char *str);

//split:
char			**ft_split(char *s, char *c);

//atof:
int				ft_is_digit(char *str);
float			*ft_advanced_atof(char *str);

//utils_parsing:
int				ft_count_elem(char **tab);
char			***ft_ultimate_split(char **tab);
int				ft_check_lines(char ***d_tab, int i, int j);
float			**ft_float_tab(char ***d_tab, int n_lines, int n_elem);

//free:
void			ft_free_triple(char ***tab);
void			free_split(char **tab);

//file_2_cloud:
char			***char_tab(char *argv1, t_map *map);
float			**float_tab(char ***char_tab, t_map *map);
float			**mat_2_cloud(float **mat, t_map *map);

//file_2_cloud_2:
float			**file_2_cloud(char *argv1, t_map *map);
void			*free_uncompleted_tab(float **atof, float ***tab, int i);
void			display_error(char *str);

//utils_init:

float			ft_min(float **tab, int i, int j, int xyz);
float			ft_max(float **tab, int i, int j, int xyz);
void			ft_scale(t_map *map, float l, float h);
void			ft_translate(t_map *map, float tx, float ty);

//init_free:
void			ft_init_map(t_proj *proj, t_map *map, char *argv1);
void			free_map(t_map *map);
void			init_mlx(t_mlx *mlx);
void			free_mlx(t_mlx *mlx);
void			init_data(t_data *data, t_map *map, char *argv1, t_mlx *mlx);
void			free_data(t_data *data);

//init_free_2:
void			init_proj(t_proj *proj, t_map *map);
void			init_srt(t_map *map);

//utils_display:
void			ft_bzero(UINT **addr, int bytes);
void			draw_pt(t_data *data, float x, float y, float z);
void			draw_line_bis(t_data *data, float **coords, int i, char hv);
void			draw_line(t_data *data, float **coords, int i);

//utils_display_2:
void			init_line_1(t_line *line, t_map *map, float **coords, int i);
void			init_line_2(t_line *line, t_map *map, float **coords, int i);

//display:
void			display(t_data *data);

//set_stg_mat:
void			set_sm(float *sm, t_map *map);
void			set_tm(float *tm, t_map *map);
void			set_gm(float *gm, t_map *map);

//set_r_mat:
void			set_rm(float *rm, t_map *map);

//set_p_mat:
void			set_pm_ba(float *pm_ba);
void			set_pm(float *pm, t_proj *proj);

//mat_calc.c
void			x_2_mat(float *res, float *mat_1, float *mat_2);
int				ft_round(float to_round);
void			round_arr(t_map *map, float **coords);
float			**mat_x_arr(float *mat, float **coords, t_map *map);

//mat_calc_2:
float			**trans_array(t_map *map);
float			**proj_array_ba(t_map *map);
float			**proj_array(t_map *map);
void			print_mat(float *mat);

//get_color:
UINT			get_color(t_map *map, float z);

//utils_draw_line:
float			ft_tan(float *p1, float *p2);
void			ft_line_same_x(t_data *data, float *p1, float *p2);
void			tab_1(t_data *data, float *p1, float *p2, char ij);
void			ft_line_same_y(t_data *data, float *p1, float *p2);

//utils_draw_line_2:
int				ft_smallest(float v1, float v2);
void			ft_line_tp(t_data *data, float *p1, float *p2, float tan);
void			tab_v1(t_data *data, float *p1, float *p2);
void			tab_v2(t_data *data, float *p1, float *p2);
void			tab_v3(t_data *data, float *p1, float *p2);
void			ft_line_tp(t_data *data, float *p1, float *p2, float tan);

//utils_draw_line_3:
float			*ft_a_b_line(float *p1, float *p2);
float			ft_get_x(float *params, float y);
float			ft_get_y(float *params, float x);

//utils_draw_line_4:
void			ft_line_tp(t_data *data, float *p1, float *p2, float tan);
void			ft_line_tn(t_data *data, float *p1, float *p2, float tan);
void			tab_v4(t_data *data, float *p1, float *p2);
void			tab_v5(t_data *data, float *p1, float *p2);
void			tab_v6(t_data *data, float *p1, float *p2);

//utils_draw_line_5:
float			get_line_size(float *p1, float *p2, char ij);

//interact:
int				ft_close(t_data *data);
void			free_2_reinit_map(t_map *map);
void			reinitialize_map(t_map *map, int centralize, int op);
void			ft_move(int key, t_data *data);
void			ft_zoom(int key, t_data *data, int *centralize, int *op);

//interact_2:
int				key_hook(int key, t_data *data);
void			ft_rotate(int key, t_data *data, int *centralize, int *op);
void			free_int_point(float **p_int);

//interact_3:
void			free_double_float(float **tab, int size);
void			reinitialize_rot(t_map *map);
void			reinitialize_zoom(t_map *map);

//draw_menu:
void			draw_menu(t_data *data);

#endif
